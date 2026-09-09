/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:13:51 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/09 03:28:34 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data,
		int (*cmp)(void *, void *))
{
	t_list	*node;
	t_list	*prev;
	t_list	*cur;

	node = ft_create_elem(data);
	if (!node)
		return ;
	prev = 0;
	cur = *begin_list;
	while (cur && cmp(cur->data, data) < 0)
	{
		prev = cur;
		cur = cur->next;
	}
	node->next = cur;
	if (prev)
		prev->next = node;
	else
		*begin_list = node;
}
