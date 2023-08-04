/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 00:41:38 by aabda             #+#    #+#             */
/*   Updated: 2023/08/03 11:47:14 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./improved_malloc.h"

static t_malloc_lst	*lst_last_node(t_malloc_lst *lst)
{
	t_malloc_lst	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	lst_create_node(t_malloc_lst **lst, void *elem)
{
	t_malloc_lst	*current;
	t_malloc_lst	*last;
	t_malloc_lst	*new;

	new = malloc(sizeof(t_malloc_lst));
	if (!new)
		return ;
	current = *lst;
	new->address = elem;
	new->next = NULL;
	if (current)
	{
		last = lst_last_node(current);
		last->next = new;
		new->prev = last;
	}
	else
	{
		*lst = new;
		new->prev = NULL;
	}
}

void	*improved_malloc(t_malloc_lst **lst, size_t len)
{
	void	*elem;

	elem = malloc(len);
	if (elem)
		lst_create_node(lst, elem);
	return (elem);
}

static void	remove_and_place_node(t_malloc_lst **lst, t_malloc_lst *current)
{
	t_malloc_lst	*tmp_l;
	t_malloc_lst	*tmp_r;

	tmp_l = current->prev;
	tmp_r = current->next;
	if (tmp_l && tmp_r)
	{
		tmp_l->next = tmp_r;
		tmp_r->prev = tmp_l;
	}
	else if (tmp_l && !tmp_r)
		tmp_l->next = NULL;
	else if (!tmp_l && tmp_r)
	{
		tmp_r->prev = NULL;
		*lst = tmp_r;
	}
	free(current->address);
	current->address = NULL;
	free(current);
	current = NULL;
}

void	lst_free_bloc(t_malloc_lst **lst, void *elem)
{
	t_malloc_lst	*current;

	current = *lst;
	if (!current)
		return ;
	while (current->address != elem)
		current = current->next;
	if (current)
		remove_and_place_node(lst, current);
	else
		return ;
}
