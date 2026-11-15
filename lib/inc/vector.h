/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:41:58 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/15 18:35:44 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_VECTOR_H
# define H0NZRA_VECTOR_H

# include <stdlib.h>
# include "utils.h"

typedef struct s_vector	t_vector;

t_vector				*vector_create(size_t data_size);
void					vector_destroy(t_vector *vector);

t_bool					vector_push(t_vector *vector, void *data);
t_bool					vector_pop(t_vector *vector, void *store);

#endif // !H0NZRA_VECTOR_H
