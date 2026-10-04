#include "pq_utility.h"

size_t		pqu_parent_node(size_t index)
{
	return (index / 2 + 1);
}

size_t		pqu_left_node(size_t index)
{
	return (2 * index + 1);
}

size_t		pqu_right_node(size_t index)
{
	return (2 * index + 2);
}

