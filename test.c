/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:23:54 by aabda             #+#    #+#             */
/*   Updated: 2023/08/03 02:13:17 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./improved_malloc.h"
#include <stdio.h>

static void	ft_print_linked_list_and_str(t_malloc_lst *lst)
{
	t_malloc_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("===================================\n");
		printf("[%p] <- prev [%p] next -> [%p]\n", tmp->prev, tmp, tmp->next);
		printf("tmp->address = [%p]\n", tmp->address);
		printf("===================================\n");
		tmp = tmp->next;
	}
}

int	main(void)
{
	t_malloc_lst	*lst;
	char			*str;
	char			*str2;
	char			**str3;

	lst = NULL;
	str = improved_malloc(&lst, 10);
	str2 = improved_malloc(&lst, 10);
	str3 = improved_malloc(&lst, sizeof(char *) * 3);
	str3[0] = improved_malloc(&lst, sizeof(char) * 10);
	str3[1] = improved_malloc(&lst, sizeof(char) * 10);
	printf("[%p]\n", str);
	printf("[%p]\n", str2);
	printf("[%p]\n", str3);
	printf("[%p]\n", str3[0]);
	printf("[%p]\n", str3[1]);
	ft_print_linked_list_and_str(lst);
	lst_free_bloc(&lst, str);
	printf("\n");
	ft_print_linked_list_and_str(lst);
	return (0);
}
