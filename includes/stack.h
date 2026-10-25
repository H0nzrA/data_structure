#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct e_stack	t_stack;

t_stack					*stack_create(size_t data_size);
void					stack_destroy(t_stack *stack);

int						stack_push(t_stack *stack, const void *data);
int						stack_pop(t_stack *stack, void *store);
int						stack_top(const t_stack *stack, void *store);
int						stack_is_empty(const t_stack *stack);
size_t					stack_size(const t_stack *stack);

#endif // !STACK_H
