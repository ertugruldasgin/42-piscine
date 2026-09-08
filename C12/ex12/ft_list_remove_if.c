/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:35:02 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/08 19:55:38 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	**node;
	t_list	*temp;

	node = begin_list;
	while (*node)
	{
		if (cmp((*node)->data, data_ref) == 0)
		{
			temp = *node;
			*node = temp->next;
			free_fct(temp->data);
			free(temp);
		}
		else
		{
			*node = (*node)->next;
		}
	}
}
