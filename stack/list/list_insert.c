/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:03:01 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 15:03:05 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_insert(t_list **head, t_list *node)
{
	if (!head)
		return ;
	if (node)
	{
		if (*head)
			node->next = *head;
		*head = node;
	}
}
