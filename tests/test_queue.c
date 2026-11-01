
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ************************************************************************** */
/*                               CONFIGURATION                                */
/* ************************************************************************** */

#define STRESS_OPERATIONS       1000000
#define LIFECYCLE_ITERATIONS    10000
#define LIFECYCLE_ELEMENTS      1000
#define REFERENCE_CAPACITY      1000000

/* ************************************************************************** */
/*                                  TEST DATA                                 */
/* ************************************************************************** */

typedef struct s_test_data
{
    int             id;
    double          score;
    char            name[32];
    unsigned char   flags[16];
}   t_test_data;

static unsigned int g_seed = 42;
static size_t       g_checks = 0;
static size_t       g_failures = 0;

/* ************************************************************************** */
/*                              TEST UTILITIES                               */
/* ************************************************************************** */

#define CHECK(condition, message) \
    do \
    { \
        g_checks++; \
        if (!(condition)) \
        { \
            g_failures++; \
            fprintf(stderr, "[FAIL] %s (line %d)\n", message, __LINE__); \
            return (0); \
        } \
    } while (0)

static unsigned int test_random(void)
{
    g_seed = g_seed * 1664525u + 1013904223u;
    return (g_seed);
}

static t_test_data make_test_data(int id)
{
    t_test_data data;

    data.id = id;
    data.score = (double)id / 3.0;
    snprintf(data.name, sizeof(data.name), "element_%d", id);
    memset(data.flags, id % 256, sizeof(data.flags));
    return (data);
}

static int same_test_data(const t_test_data *a, const t_test_data *b)
{
    return (
        a->id == b->id
        && a->score == b->score
        && strcmp(a->name, b->name) == 0
        && memcmp(a->flags, b->flags, sizeof(a->flags)) == 0
    );
}

/* ************************************************************************** */
/*                              BASIC OPERATIONS                              */
/* ************************************************************************** */

static int test_basic_fifo(void)
{
    t_queue *queue;
    int     value;
    int     expected;

    printf("[TEST] Basic FIFO operations\n");

    queue = queue_create(sizeof(int));
    CHECK(queue != NULL, "queue_create failed");

    CHECK(queue_is_empty(queue), "new queue should be empty");
    CHECK(queue_size(queue) == 0, "new queue size should be zero");

    for (int i = 1; i <= 100000; i++)
        CHECK(queue_enqueue(queue, &i), "enqueue failed");

    CHECK(queue_size(queue) == 100000, "incorrect queue size");
    CHECK(!queue_is_empty(queue), "queue should not be empty");

    for (int i = 1; i <= 100000; i++)
    {
        value = -1;
        CHECK(queue_peek(queue, &value), "peek failed");
        CHECK(value == i, "peek returned incorrect value");
        CHECK(queue_size(queue) == (size_t)(100001 - i),
            "peek changed queue size");

        CHECK(queue_dequeue(queue, &value), "dequeue failed");
        CHECK(value == i, "FIFO ordering violated");
    }

    expected = 0;
    CHECK(queue_size(queue) == 0, "queue should be empty");
    CHECK(queue_is_empty(queue), "queue should be empty");

    queue_destroy(queue);
    (void)expected;
    return (1);
}

/* ************************************************************************** */
/*                            CIRCULAR BUFFER TEST                            */
/* ************************************************************************** */

static int test_wraparound(void)
{
    t_queue *queue;
    int     value;

    printf("[TEST] Circular buffer wraparound\n");

    queue = queue_create(sizeof(int));
    CHECK(queue != NULL, "queue_create failed");

    /*
     * Repeatedly move the front and back positions.
     * This should force many circular-buffer wraparounds.
     */
    for (int round = 0; round < 10000; round++)
    {
        for (int i = 0; i < 100; i++)
        {
            value = round * 100 + i;
            CHECK(queue_enqueue(queue, &value), "enqueue failed");
        }

        for (int i = 0; i < 100; i++)
        {
            CHECK(queue_dequeue(queue, &value), "dequeue failed");
            CHECK(value == round * 100 + i,
                "wraparound changed FIFO ordering");
        }

        CHECK(queue_is_empty(queue), "queue should be empty");
    }

    queue_destroy(queue);
    return (1);
}

/* ************************************************************************** */
/*                           GROW WHILE WRAPPED                               */
/* ************************************************************************** */

static int test_growth(void)
{
    t_queue *queue;
    int     value;

    printf("[TEST] Growth and wrapped storage\n");

    queue = queue_create(sizeof(int));
    CHECK(queue != NULL, "queue_create failed");

    for (int i = 0; i < 10000; i++)
        CHECK(queue_enqueue(queue, &i), "initial enqueue failed");

    for (int i = 0; i < 5000; i++)
    {
        CHECK(queue_dequeue(queue, &value), "initial dequeue failed");
        CHECK(value == i, "initial FIFO ordering violated");
    }

    for (int i = 10000; i < 30000; i++)
        CHECK(queue_enqueue(queue, &i), "wrapped enqueue failed");

    for (int i = 5000; i < 30000; i++)
    {
        CHECK(queue_dequeue(queue, &value), "final dequeue failed");
        CHECK(value == i, "growth corrupted FIFO ordering");
    }

    CHECK(queue_is_empty(queue), "queue should be empty");

    queue_destroy(queue);
    return (1);
}

/* ************************************************************************** */
/*                             GENERIC DATA TEST                              */
/* ************************************************************************** */

static int test_generic_data(void)
{
    t_queue     *queue;
    t_test_data input;
    t_test_data output;

    printf("[TEST] Generic structure storage\n");

    queue = queue_create(sizeof(t_test_data));
    CHECK(queue != NULL, "queue_create failed");

    for (int i = 0; i < 100000; i++)
    {
        input = make_test_data(i);
        CHECK(queue_enqueue(queue, &input), "structure enqueue failed");
    }

    for (int i = 0; i < 100000; i++)
    {
        memset(&output, 0, sizeof(output));

        CHECK(queue_dequeue(queue, &output),
            "structure dequeue failed");

        input = make_test_data(i);
        CHECK(same_test_data(&input, &output),
            "structure data corrupted");
    }

    queue_destroy(queue);
    return (1);
}

/* ************************************************************************** */
/*                            NULL STORE TESTS                                */
/* ************************************************************************** */

static int test_null_store(void)
{
    t_queue *queue;
    int     value;

    printf("[TEST] NULL store handling\n");

    queue = queue_create(sizeof(int));
    CHECK(queue != NULL, "queue_create failed");

    value = 42;
    CHECK(queue_enqueue(queue, &value), "enqueue failed");

    CHECK(queue_peek(queue, NULL), "peek with NULL store failed");
    CHECK(queue_size(queue) == 1, "peek with NULL changed size");

    CHECK(queue_dequeue(queue, NULL), "dequeue with NULL store failed");
    CHECK(queue_is_empty(queue), "dequeue with NULL did not remove item");

    queue_destroy(queue);
    return (1);
}

/* ************************************************************************** */
/*                          RANDOMIZED DIFFERENTIAL TEST                      */
/* ************************************************************************** */

static int test_randomized(void)
{
    t_queue *queue;
    size_t  front;
    size_t  size;
    int     operation;
    int     value;
    int     expected;
	int *reference = malloc(
		REFERENCE_CAPACITY * sizeof(*reference)
	);
	if (!reference)
		return (0);

    printf("[TEST] Randomized differential testing (%d operations)\n",
        STRESS_OPERATIONS);

    queue = queue_create(sizeof(int));
    CHECK(queue != NULL, "queue_create failed");

    front = 0;
    size = 0;

    for (int i = 0; i < STRESS_OPERATIONS; i++)
    {
        operation = test_random() % 100;

        if (operation < 55 && size < REFERENCE_CAPACITY)
        {
            value = (int)test_random();

            CHECK(queue_enqueue(queue, &value),
                "random enqueue failed");

            reference[(front + size) % REFERENCE_CAPACITY] = value;
            size++;
        }
        else if (operation < 90 && size > 0)
        {
            expected = reference[front];

            CHECK(queue_dequeue(queue, &value),
                "random dequeue failed");
            CHECK(value == expected,
                "random FIFO ordering violated");

            front = (front + 1) % REFERENCE_CAPACITY;
            size--;
        }
        else if (size > 0)
        {
            expected = reference[front];

            CHECK(queue_peek(queue, &value),
                "random peek failed");
            CHECK(value == expected,
                "random peek returned incorrect value");
        }
        else
        {
            CHECK(!queue_dequeue(queue, &value),
                "dequeue on empty queue should fail");
            CHECK(!queue_peek(queue, &value),
                "peek on empty queue should fail");
        }

        CHECK(queue_size(queue) == size,
            "random queue size mismatch");
        CHECK(queue_is_empty(queue) == (size == 0),
            "random empty state mismatch");
    }

    while (size > 0)
    {
        expected = reference[front];

        CHECK(queue_dequeue(queue, &value),
            "final random dequeue failed");
        CHECK(value == expected,
            "final random FIFO ordering violated");

        front = (front + 1) % REFERENCE_CAPACITY;
        size--;
    }

    queue_destroy(queue);
	free(reference);
    return (1);
}

/* ************************************************************************** */
/*                          CLEAR AND REUSE TEST                              */
/* ************************************************************************** */

static int test_clear_and_reuse(void)
{
    t_queue *queue;
    int     value;

    printf("[TEST] Clear and reuse\n");

    queue = queue_create(sizeof(int));
    CHECK(queue != NULL, "queue_create failed");

    for (int round = 0; round < 1000; round++)
    {
        for (int i = 0; i < 1000; i++)
        {
            value = round * 1000 + i;
            CHECK(queue_enqueue(queue, &value), "enqueue failed");
        }

        queue_clear(queue);

        CHECK(queue_is_empty(queue), "clear did not empty queue");
        CHECK(queue_size(queue) == 0, "clear did not reset size");

        CHECK(!queue_dequeue(queue, &value),
            "dequeue after clear should fail");

        value = round;
        CHECK(queue_enqueue(queue, &value),
            "enqueue after clear failed");

        CHECK(queue_dequeue(queue, &value),
            "dequeue after clear failed");
        CHECK(value == round, "wrong value after clear");
    }

    queue_destroy(queue);
    return (1);
}

/* ************************************************************************** */
/*                          CREATE / DESTROY STRESS                           */
/* ************************************************************************** */

static int test_lifecycle(void)
{
    t_queue *queue;
    int     value;

    printf("[TEST] Create / destroy (%d iterations)\n",
        LIFECYCLE_ITERATIONS);

    for (int round = 0; round < LIFECYCLE_ITERATIONS; round++)
    {
        queue = queue_create(sizeof(int));
        CHECK(queue != NULL, "queue_create failed");

        for (int i = 0; i < LIFECYCLE_ELEMENTS; i++)
        {
            value = round + i;
            CHECK(queue_enqueue(queue, &value), "enqueue failed");
        }

        for (int i = 0; i < LIFECYCLE_ELEMENTS / 2; i++)
        {
            CHECK(queue_dequeue(queue, &value), "dequeue failed");
            CHECK(value == round + i, "incorrect lifecycle value");
        }

        queue_clear(queue);

        CHECK(queue_is_empty(queue), "queue should be empty after clear");

        queue_destroy(queue);
    }

    return (1);
}

/* ************************************************************************** */
/*                            BROKEN USAGE TESTS                              */
/* ************************************************************************** */

static int test_invalid_usage(void)
{
    t_queue *queue;
    int     value;

    printf("[TEST] Invalid usage\n");

    /* NULL queue */
	value = 0;
    CHECK(queue_enqueue(NULL, &value) == 0,
        "enqueue(NULL) should fail");
    CHECK(queue_dequeue(NULL, &value) == 0,
        "dequeue(NULL) should fail");
    CHECK(queue_peek(NULL, &value) == 0,
        "peek(NULL) should fail");

    /* NULL value */
    queue = queue_create(sizeof(int));
    CHECK(queue != NULL, "queue_create failed");

    CHECK(queue_enqueue(queue, NULL) == 0,
        "enqueue with NULL value should fail");

    CHECK(queue_is_empty(queue), "failed enqueue changed queue");
    CHECK(queue_size(queue) == 0, "failed enqueue changed size");

    /* Empty queue */
    CHECK(queue_dequeue(queue, &value) == 0,
        "dequeue on empty queue should fail");
    CHECK(queue_peek(queue, &value) == 0,
        "peek on empty queue should fail");

    /* NULL store on empty queue */
    CHECK(queue_dequeue(queue, NULL) == 0,
        "dequeue NULL on empty queue should fail");
    CHECK(queue_peek(queue, NULL) == 0,
        "peek NULL on empty queue should fail");

    CHECK(queue_is_empty(queue), "invalid operations changed queue");
    CHECK(queue_size(queue) == 0, "invalid operations changed size");

    /* Repeated clear */
    queue_clear(queue);
    queue_clear(queue);
    queue_clear(queue);

    CHECK(queue_is_empty(queue), "repeated clear failed");

    queue_destroy(queue);

    /* NULL destruction and clearing */
    queue_destroy(NULL);
    queue_clear(NULL);

    return (1);
}

/* ************************************************************************** */
/*                                  MAIN                                      */
/* ************************************************************************** */

int main(void)
{
    int passed;

    passed = 1;

    printf("\n========== QUEUE STRESS TEST ==========\n\n");

    passed &= test_basic_fifo();
    passed &= test_wraparound();
    passed &= test_growth();
    passed &= test_generic_data();
    passed &= test_null_store();
    passed &= test_randomized();
    passed &= test_clear_and_reuse();
    passed &= test_lifecycle();
    passed &= test_invalid_usage();

    printf("\n========== TEST SUMMARY ===============\n");
    printf("Checks:   %zu\n", g_checks);
    printf("Failures: %zu\n", g_failures);

    if (passed && g_failures == 0)
    {
        printf("\n[SUCCESS] All queue tests passed.\n");
        return (EXIT_SUCCESS);
    }

    printf("\n[FAILURE] Queue tests failed.\n");
    return (EXIT_FAILURE);
}
