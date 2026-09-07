/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 01:13:30 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/08 01:21:52 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
