#include "heapq.h"
#include "list.h"
#include "stack.h"

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRESS_COUNT 100000

static int g_checks;
static int g_failures;

#define CHECK(condition) do { \
    ++g_checks; \
    if (!(condition)) { \
        ++g_failures; \
        fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); \
    } \
} while (0)

static int compare_int(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

static unsigned int next_random(unsigned int *state)
{
    *state = *state * 1103515245u + 12345u;
    return (*state >> 1) & 0x7fffffffu;
}

static int int_compare_qsort(const void *a, const void *b)
{
    return compare_int(a, b);
}

static void test_heapq_min(void)
{
    t_heapq *heap;
    int *values;
    int value;
    int output;
    int previous;
    int i;

    puts("[SUCCESS] heapq min-heap stress");
    values = malloc(sizeof(*values) * STRESS_COUNT);
    CHECK(values != NULL);
    if (!values)
        return;

    heap = heapq_create(sizeof(int), compare_int, min_heapq);
    CHECK(heap != NULL);
    if (!heap) {
        free(values);
        return;
    }

    {
        unsigned int seed = 42;
        for (i = 0; i < STRESS_COUNT; ++i) {
            values[i] = (int)(next_random(&seed) % 200001u) - 100000;
            value = values[i];
            CHECK(heapq_push(heap, &value) != 0);
        }
    }

    CHECK(heapq_peek(heap, &output) != 0);
    qsort(values, STRESS_COUNT, sizeof(*values), int_compare_qsort);
    CHECK(output == values[0]);

    previous = INT_MIN;
    for (i = 0; i < STRESS_COUNT; ++i) {
        CHECK(heapq_pop(heap, &output) != 0);
        CHECK(output >= previous);
        CHECK(output == values[i]);
        previous = output;
    }
    CHECK(heapq_pop(heap, &output) == 0);
    CHECK(heapq_peek(heap, &output) == 0);

    heapq_destroy(heap);
    free(values);
}

static void test_heapq_max(void)
{
    t_heapq *heap;
    int output;
    int value;
    int i;

    puts("[SUCCESS] heapq max-heap stress");
    heap = heapq_create(sizeof(int), compare_int, max_heapq);
    CHECK(heap != NULL);
    if (!heap)
        return;

    for (i = 0; i < STRESS_COUNT; ++i) {
        value = (i * 7919) % 100003;
        CHECK(heapq_push(heap, &value) != 0);
    }

    for (i = 100002; i >= 0; --i) {
        /* This workload does not contain every integer, so check monotonicity
           rather than expecting a specific sequence. */
        if (i == 100002)
            CHECK(heapq_peek(heap, &output) != 0);
    }

    CHECK(heapq_pop(heap, &output) != 0);
    for (i = 1; i < STRESS_COUNT; ++i) {
        int next;
        CHECK(heapq_pop(heap, &next) != 0);
        CHECK(output >= next);
        output = next;
    }
    CHECK(heapq_pop(heap, &output) == 0);
    heapq_destroy(heap);
}

static void test_heapq_copy_semantics(void)
{
    t_heapq *heap;
    int value = 17;
    int output = 0;

    puts("[SUCCESS] heapq copies pushed values");
    heap = heapq_create(sizeof(int), compare_int, min_heapq);
    CHECK(heap != NULL);
    if (!heap)
        return;

    CHECK(heapq_push(heap, &value) != 0);
    value = -500;
    CHECK(heapq_peek(heap, &output) != 0);
    CHECK(output == 17);
    heapq_destroy(heap);
}

static void test_list_stress(void)
{
    t_list *list;
    int value;
    int output;
    int i;

    puts("[SUCCESS] list FIFO stress (push_back / pop_front)");
    list = list_create(sizeof(int));
    CHECK(list != NULL);
    if (!list)
        return;

    for (i = 0; i < STRESS_COUNT; ++i) {
        value = i;
        CHECK(list_push_back(list, &value) != 0);
    }
    for (i = 0; i < STRESS_COUNT; ++i) {
        output = -1;
        CHECK(list_pop_front(list, &output) != 0);
        CHECK(output == i);
    }
    CHECK(list_pop_front(list, &output) == 0);
    list_destroy(list);

    puts("[SUCCESS] list LIFO stress (push_front / pop_front)");
    list = list_create(sizeof(int));
    CHECK(list != NULL);
    if (!list)
        return;

    for (i = 0; i < STRESS_COUNT; ++i) {
        value = i;
        CHECK(list_push_front(list, &value) != 0);
    }
    for (i = STRESS_COUNT - 1; i >= 0; --i) {
        CHECK(list_pop_front(list, &output) != 0);
        CHECK(output == i);
    }
    CHECK(list_pop_front(list, &output) == 0);
    list_destroy(list);
}

static void test_list_copy_and_discard(void)
{
    t_list *list;
    int value = 123;
    int output = 0;

    puts("[SUCCESS] list copies values and supports discard");
    list = list_create(sizeof(int));
    CHECK(list != NULL);
    if (!list)
        return;

    CHECK(list_push_back(list, &value) != 0);
    value = 999;
    CHECK(list_pop_back(list, &output) != 0);
    CHECK(output == 123);

    value = 456;
    CHECK(list_push_front(list, &value) != 0);
    CHECK(list_pop_front(list, NULL) != 0);

    list_destroy(list);
}

static void test_stack_stress(void)
{
    t_stack *stack;
    int value;
    int output;
    int i;

    puts("[SUCCESS] stack LIFO stress");
    stack = stack_create(sizeof(int));
    CHECK(stack != NULL);
    if (!stack)
        return;

    CHECK(stack_is_empty(stack) != 0);
    CHECK(stack_size(stack) == 0);
    CHECK(stack_top(stack, &output) == 0);

    for (i = 0; i < STRESS_COUNT; ++i) {
        value = i * 3;
        CHECK(stack_push(stack, &value) != 0);
        CHECK(stack_size(stack) == (size_t)i + 1);
    }
    CHECK(stack_is_empty(stack) == 0);
    CHECK(stack_top(stack, &output) != 0);
    CHECK(output == (STRESS_COUNT - 1) * 3);

    for (i = STRESS_COUNT - 1; i >= 0; --i) {
        CHECK(stack_pop(stack, &output) != 0);
        CHECK(output == i * 3);
        CHECK(stack_size(stack) == (size_t)i);
    }

    CHECK(stack_is_empty(stack) != 0);
    CHECK(stack_pop(stack, &output) == 0);
    stack_destroy(stack);
}

static void run_success_tests(void)
{
    test_heapq_min();
    test_heapq_max();
    test_heapq_copy_semantics();
    test_list_stress();
    test_list_copy_and_discard();
    test_stack_stress();
}

/*
 * These tests assume the API contract is:
 * - creation rejects data_size == 0;
 * - heap creation rejects a NULL comparator and an invalid heap type;
 * - operations on a NULL container fail safely;
 * - destroy(NULL) is safe.
 *
 * If you have not documented these guarantees yet, treat these as contract
 * decisions to make, not automatically as implementation bugs.
 */
static void run_broken_input_tests(void)
{
    t_heapq *heap;
    t_list *list;
    t_stack *stack;
    int value = 42;
    int output = 0;

    puts("[BROKEN] invalid creation arguments");
    CHECK(heapq_create(0, compare_int, min_heapq) == NULL);
    CHECK(heapq_create(sizeof(int), NULL, min_heapq) == NULL);
    CHECK(heapq_create(sizeof(int), compare_int, (t_heapq_type)99) == NULL);
    CHECK(list_create(0) == NULL);
    CHECK(stack_create(0) == NULL);

    puts("[BROKEN] empty-container operations");
    heap = heapq_create(sizeof(int), compare_int, min_heapq);
    CHECK(heap != NULL);
    if (heap) {
        CHECK(heapq_pop(heap, &output) == 0);
        CHECK(heapq_peek(heap, &output) == 0);
        CHECK(heapq_push(heap, NULL) == 0);
        heapq_destroy(heap);
    }

    list = list_create(sizeof(int));
    CHECK(list != NULL);
    if (list) {
        CHECK(list_pop_back(list, &output) == 0);
        CHECK(list_pop_front(list, &output) == 0);
        CHECK(list_push_back(list, NULL) == 0);
        CHECK(list_push_front(list, NULL) == 0);
        list_destroy(list);
    }

    stack = stack_create(sizeof(int));
    CHECK(stack != NULL);
    if (stack) {
        CHECK(stack_pop(stack, &output) == 0);
        CHECK(stack_top(stack, &output) == 0);
        CHECK(stack_push(stack, NULL) == 0);
        stack_destroy(stack);
    }

    puts("[BROKEN] NULL container handling (must fail safely)");
    CHECK(heapq_push(NULL, &value) == 0);
    CHECK(heapq_pop(NULL, &output) == 0);
    CHECK(heapq_peek(NULL, &output) == 0);
    heapq_destroy(NULL);

    CHECK(list_push_back(NULL, &value) == 0);
    CHECK(list_push_front(NULL, &value) == 0);
    CHECK(list_pop_back(NULL, &output) == 0);
    CHECK(list_pop_front(NULL, &output) == 0);
    list_destroy(NULL);

    CHECK(stack_push(NULL, &value) == 0);
    CHECK(stack_pop(NULL, &output) == 0);
    CHECK(stack_top(NULL, &output) == 0);
    CHECK(stack_is_empty(NULL) != 0);
    CHECK(stack_size(NULL) == 0);
    stack_destroy(NULL);
}

int main(int argc, char **argv)
{
    if (argc != 2 || (strcmp(argv[1], "success") != 0
            && strcmp(argv[1], "broken") != 0)) {
        fprintf(stderr, "Usage: %s success|broken\n", argv[0]);
        return 2;
    }

    if (strcmp(argv[1], "success") == 0)
        run_success_tests();
    else
        run_broken_input_tests();

    printf("\nChecks: %d | Failures: %d\n", g_checks, g_failures);
    return (g_failures != 0);
}
