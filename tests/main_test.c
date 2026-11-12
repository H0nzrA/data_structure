
#include "heapq.h"
#include <stdio.h>

#define DATA_SIZE 20

static int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return ((x > y) - (x < y));
}

static int another(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return ((y > x) - (y < x));
}

static void print_heap(t_heapq *heapq, const char *title)
{
    int store;

    printf("%s\n", title);
    while (!heapq_is_empty(heapq))
    {
        if (!heapq_pop(heapq, &store))
        {
            printf("Pop failed!\n");
            return;
        }
        printf("%6d", store);
    }
    printf("\n\n");
}

static int refill_heap(t_heapq *heapq, const int *data)
{
    for (size_t i = 0; i < DATA_SIZE; i++)
    {
        if (!heapq_push(heapq, &data[i]))
            return (0);
    }
    return (1);
}

int main(void)
{
    int data[DATA_SIZE] = {
        42, 17, 8, 93, 25,
        61, 3, 74, 36, 12,
        89, 50, 6, 28, 95,
        41, 19, 67, 31, 54
    };

    t_heapq *heapq;

    heapq = heapq_create(sizeof(data[0]), compare, min_heap);
    if (!heapq)
        return (1);

    /* Test 1: Normal min-heap */
    if (!refill_heap(heapq, data))
        goto error;
    print_heap(heapq, "Min-heap:");

    /* Test 2: Transform into max-heap */
    if (!refill_heap(heapq, data))
        goto error;
    if (!heapq_set_type(heapq, max_heap))
        goto error;
    print_heap(heapq, "Max-heap:");

    /* Test 3: Transform back into min-heap */
    if (!refill_heap(heapq, data))
        goto error;
    if (!heapq_set_type(heapq, min_heap))
        goto error;
    print_heap(heapq, "Back to min-heap:");

    /* Test 4: Change comparison function */
    if (!refill_heap(heapq, data))
        goto error;
    if (!heapq_set_compare(heapq, another))
        goto error;
    print_heap(heapq, "Reverse comparison:");

    /* Test 5: Empty heap */
    print_heap(heapq, "Empty heap:");

    heapq_destroy(heapq);
    return (0);

error:
    fprintf(stderr, "Heap operation failed!\n");
    heapq_destroy(heapq);
    return (1);
}
