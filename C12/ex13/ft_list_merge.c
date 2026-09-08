/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:56:15 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/08 20:02:45 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*node1;

	node1 = *begin_list1;
	if (!node1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (node1->next)
		node1 = node1->next;
	node1->next = begin_list2;
}
