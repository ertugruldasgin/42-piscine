/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:52:52 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/09 03:27:31 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*node;
	t_list	*temp;
	t_list	*prev;
	t_list	*cur;

	node = begin_list2;
	while (node)
	{
		temp = node->next;
		prev = 0;
		cur = *begin_list1;
		while (cur && cmp(cur->data, node->data) < 0)
		{
			prev = cur;
			cur = cur->next;
		}
		node->next = cur;
		if (prev)
			prev->next = node;
		else
			*begin_list1 = node;
		node = temp;
	}
}
