/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 04:46:36 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/09 04:56:23 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
			void *))
{
	void	*found;

	if (!root)
		return (NULL);
	found = btree_search_item(root->left, data_ref, cmpf);
	if (found)
		return (found);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
