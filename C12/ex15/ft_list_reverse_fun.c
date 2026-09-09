/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 03:32:59 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/09 04:06:43 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*node;
	unsigned int	i;

	i = 0;
	node = begin_list;
	while (node && i < nbr)
	{
		node = node->next;
		i++;
	}
	return (node);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*a;
	t_list	*b;
	void	*temp;

	i = 0;
	size = ft_list_size(begin_list);
	while (i < size / 2)
	{
		a = ft_list_at(begin_list, i);
		b = ft_list_at(begin_list, size - 1 - i);
		temp = a->data;
		a->data = b->data;
		b->data = temp;
		i++;
	}
}
