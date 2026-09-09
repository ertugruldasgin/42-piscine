/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 05:12:05 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/09 06:13:52 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	enqueue(t_queue **head, t_queue **tail, t_btree *node, int level)
{
	t_queue	*new;

	if (!node)
		return ;
	new = malloc(sizeof(t_queue));
	if (!new)
		return ;
	new->node = node;
	new->level = level;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
		(*tail)->next = new;
	*tail = new;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_queue	*head;
	t_queue	*tail;
	t_queue	*cur;
	int		last;

	head = NULL;
	tail = NULL;
	last = -1;
	enqueue(&head, &tail, root, 0);
	while (head)
	{
		cur = head;
		head = head->next;
		applyf(cur->node->item, cur->level, cur->level != last);
		last = cur->level;
		enqueue(&head, &tail, cur->node->left, cur->level + 1);
		enqueue(&head, &tail, cur->node->right, cur->level + 1);
		free(cur);
	}
}
