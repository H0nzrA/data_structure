/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:00:32 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/01 13:01:55 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_SET_H
# define H0NZRA_SET_H

# include <stdlib.h>

typedef struct s_set	t_set;

t_set					set_create(size_t data_size);
void					set_destroy(t_set *set);

#endif // !H0NZRA_SET_H
