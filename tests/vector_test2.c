#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#define TEST(name) \
	do { \
		printf("\n[TEST] %s\n", name); \
	} while (0)

#define CHECK(condition) \
	do { \
		checks++; \
		if (!(condition)) { \
			failures++; \
			printf("  [FAIL] %s:%d: %s\n", \
				__FILE__, __LINE__, #condition); \
		} \
	} while (0)

static size_t	checks = 0;
static size_t	failures = 0;

static void	test_creation(void)
{
	t_vector	*vector;

	TEST("Creation and destruction");

	vector = vector_create(sizeof(int));
	CHECK(vector != NULL);
	CHECK(vector_size(vector) == 0);
	CHECK(vector_capacity(vector) == 0);
	CHECK(vector_is_empty(vector) == 1);

	vector_destroy(vector);
	vector_destroy(NULL);

	CHECK(vector_create(0) == NULL);
}

static void	test_push_pop(void)
{
	t_vector	*vector;
	int			value;
	int			store;
	size_t		i;

	TEST("Push and pop");

	vector = vector_create(sizeof(int));
	CHECK(vector != NULL);
	if (!vector)
		return ;

	for (i = 0; i < 1000; i++)
	{
		value = (int)i;
		CHECK(vector_push(vector, &value) == 1);
	}

	CHECK(vector_size(vector) == 1000);
	CHECK(vector_is_empty(vector) == 0);

	for (i = 1000; i > 0; i--)
	{
		store = -1;
		CHECK(vector_pop(vector, &store) == 1);
		CHECK(store == (int)(i - 1));
	}

	CHECK(vector_size(vector) == 0);
	CHECK(vector_is_empty(vector) == 1);

	store = -1;
	CHECK(vector_pop(vector, &store) == 0);

	vector_destroy(vector);
}

static void	test_get_set(void)
{
	t_vector	*vector;
	int			value;
	int			store;
	size_t		i;

	TEST("Get and set");

	vector = vector_create(sizeof(int));
	CHECK(vector != NULL);
	if (!vector)
		return ;

	for (i = 0; i < 10; i++)
	{
		value = (int)i;
		CHECK(vector_push(vector, &value) == 1);
	}

	for (i = 0; i < 10; i++)
	{
		store = -1;
		CHECK(vector_get(vector, i, &store) == 1);
		CHECK(store == (int)i);
	}

	value = 999;
	CHECK(vector_set(vector, 5, &value) == 1);

	store = -1;
	CHECK(vector_get(vector, 5, &store) == 1);
	CHECK(store == 999);

	CHECK(vector_get(vector, 10, &store) == 0);
	CHECK(vector_set(vector, 10, &value) == 0);

	CHECK(vector_get(vector, SIZE_MAX, &store) == 0);
	CHECK(vector_set(vector, SIZE_MAX, &value) == 0);

	vector_destroy(vector);
}

static void	test_reserve(void)
{
	t_vector	*vector;
	int			value;
	int			store;
	size_t		old_capacity;
	size_t		i;

	TEST("Reserve and capacity");

	vector = vector_create(sizeof(int));
	CHECK(vector != NULL);
	if (!vector)
		return ;

	CHECK(vector_reserve(vector, 100) == 1);
	CHECK(vector_capacity(vector) >= 100);

	old_capacity = vector_capacity(vector);

	CHECK(vector_reserve(vector, 50) == 1);
	CHECK(vector_capacity(vector) == old_capacity);

	CHECK(vector_reserve(vector, 0) == 0);

	for (i = 0; i < 100; i++)
	{
		value = (int)i;
		CHECK(vector_push(vector, &value) == 1);
	}

	CHECK(vector_size(vector) == 100);

	CHECK(vector_capacity(vector) >= 100);

	for (i = 0; i < 100; i++)
	{
		store = -1;
		CHECK(vector_get(vector, i, &store) == 1);
		CHECK(store == (int)i);
	}

	vector_destroy(vector);
}

static void	test_clear(void)
{
	t_vector	*vector;
	int			value;
	int			store;
	size_t		i;
	size_t		old_capacity;

	TEST("Clear");

	vector = vector_create(sizeof(int));
	CHECK(vector != NULL);
	if (!vector)
		return ;

	for (i = 0; i < 100; i++)
	{
		value = (int)i;
		CHECK(vector_push(vector, &value) == 1);
	}

	old_capacity = vector_capacity(vector);

	vector_clear(vector);

	CHECK(vector_size(vector) == 0);
	CHECK(vector_is_empty(vector) == 1);
	CHECK(vector_capacity(vector) == old_capacity);

	CHECK(vector_pop(vector, &store) == 0);
	CHECK(vector_get(vector, 0, &store) == 0);

	value = 42;
	CHECK(vector_push(vector, &value) == 1);

	store = -1;
	CHECK(vector_get(vector, 0, &store) == 1);
	CHECK(store == 42);

	vector_destroy(vector);
}

static void	test_data_independence(void)
{
	t_vector	*vector;
	int			value;
	int			store;

	TEST("Data independence");

	vector = vector_create(sizeof(int));
	CHECK(vector != NULL);
	if (!vector)
		return ;

	value = 42;
	CHECK(vector_push(vector, &value) == 1);

	value = 999;

	store = 0;
	CHECK(vector_get(vector, 0, &store) == 1);
	CHECK(store == 42);

	value = 100;
	CHECK(vector_set(vector, 0, &value) == 1);

	value = 200;
	store = 0;
	CHECK(vector_get(vector, 0, &store) == 1);
	CHECK(store == 100);

	vector_destroy(vector);
}

static void	test_null_arguments(void)
{
	t_vector	*vector;
	int			value;
	int			store;

	TEST("NULL arguments");

	value = 42;
	store = 0;

	CHECK(vector_size(NULL) == 0);
	CHECK(vector_capacity(NULL) == 0);
	CHECK(vector_is_empty(NULL) == 1);

	CHECK(vector_push(NULL, &value) == 0);
	CHECK(vector_push(NULL, NULL) == 0);
	CHECK(vector_pop(NULL, &store) == 0);
	CHECK(vector_pop(NULL, NULL) == 0);

	CHECK(vector_get(NULL, 0, &store) == 0);
	CHECK(vector_get(NULL, 0, NULL) == 0);
	CHECK(vector_set(NULL, 0, &value) == 0);
	CHECK(vector_set(NULL, 0, NULL) == 0);

	CHECK(vector_reserve(NULL, 10) == 0);

	vector_clear(NULL);
	vector_destroy(NULL);

	vector = vector_create(sizeof(int));
	CHECK(vector != NULL);
	if (!vector)
		return ;

	CHECK(vector_push(vector, NULL) == 0);
	CHECK(vector_get(vector, 0, NULL) == 0);
	CHECK(vector_set(vector, 0, NULL) == 0);
	CHECK(vector_pop(vector, NULL) == 0);

	vector_destroy(vector);
}

static void	test_randomized(void)
{
	t_vector	*vector;
	int			value;
	int			store;
	int			reference[10000];
	size_t		count;
	size_t		index;
	size_t		i;
	size_t		seed;

	TEST("Randomized operations");

	vector = vector_create(sizeof(int));
	CHECK(vector != NULL);
	if (!vector)
		return ;

	count = 0;
	seed = 42;

	for (i = 0; i < 100000; i++)
	{
		seed = seed * 1103515245 + 12345;

		if ((seed % 3 == 0 || count == 0) && count < 10000)
		{
			value = (int)(seed >> 16);
			CHECK(vector_push(vector, &value) == 1);
			reference[count++] = value;
		}
		else if (seed % 3 == 1)
		{
			CHECK(vector_pop(vector, &store) == 1);
			CHECK(store == reference[count - 1]);
			count--;
		}
		else if (count > 0)
		{
			index = (seed >> 16) % count;
			value = (int)(seed >> 8);

			CHECK(vector_set(vector, index, &value) == 1);
			reference[index] = value;
		}

		CHECK(vector_size(vector) == count);

		if (count > 0)
		{
			index = (seed >> 8) % count;
			store = 0;

			CHECK(vector_get(vector, index, &store) == 1);
			CHECK(store == reference[index]);
		}
	}

	vector_destroy(vector);
}

int	main(void)
{
	printf("====================================\n");
	printf("          VECTOR TEST SUITE         \n");
	printf("====================================\n");

	test_creation();
	test_push_pop();
	test_get_set();
	test_reserve();
	test_clear();
	test_data_independence();
	test_null_arguments();
	test_randomized();

	printf("\n====================================\n");
	printf("              SUMMARY               \n");
	printf("====================================\n");
	printf("Checks   : %zu\n", checks);
	printf("Failures : %zu\n", failures);
	printf("====================================\n");

	if (failures == 0)
		printf("\033[32mALL TESTS PASSED\033[0m\n");
	else
		printf("\033[31mSOME TESTS FAILED\033[0m\n");

	return (failures != 0);
}

