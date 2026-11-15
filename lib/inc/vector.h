/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:41:58 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/15 18:55:49 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_VECTOR_H
# define H0NZRA_VECTOR_H

# include "utils.h"
# include <stdlib.h>

typedef struct s_vector	t_vector;

t_vector				*vector_create(size_t data_size);
void					vector_destroy(t_vector *vector);

t_bool					vector_push(t_vector *vector, void *data);
t_bool					vector_pop(t_vector *vector, void *store);

t_bool					vector_at(t_vector *vector, size_t index, void *store);

size_t					vector_size(t_vector *vector);
t_bool					vector_is_empty(t_vector *vector);
void					vector_clear(t_vector *vector);

#endif // !H0NZRA_VECTOR_H
