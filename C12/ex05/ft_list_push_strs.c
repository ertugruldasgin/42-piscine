/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 00:39:15 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/08 00:57:28 by udasgin          ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*node;
	t_list	*temp_node;

	if (!strs || size <= 0)
		return (NULL);
	temp_node = NULL;
	while (size > 0)
	{
		node = ft_create_elem(*strs);
		if (!node)
			return (temp_node);
		node->next = temp_node;
		temp_node = node;
		strs++;
		size--;
	}
	return (temp_node);
}
