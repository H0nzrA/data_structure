#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list	t_list;

t_list					*list_create(size_t data_size);
void					list_destroy(t_list *list);

int						list_push_back(t_list *list, void *data);
int						list_pop_back(t_list *list, void *store);

int						list_push_front(t_list *list, void *data);
int						list_pop_front(t_list *list, void *store);

#endif // !LIST_H
