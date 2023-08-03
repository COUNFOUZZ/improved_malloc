/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_malloc.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:18:55 by aabda             #+#    #+#             */
/*   Updated: 2023/08/03 01:35:07 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPROVED_MALLOC_H
# define IMPROVED_MALLOC_H

# include <stdlib.h>

typedef struct s_malloc_lst
{
	void				*address;
	struct s_malloc_lst	*next;
	struct s_malloc_lst	*prev;
}	t_malloc_lst;

void	*improved_malloc(t_malloc_lst **lst, size_t len);
void	lst_free_bloc(t_malloc_lst **lst, void *elem);

#endif