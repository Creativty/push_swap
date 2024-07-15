/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:03:18 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 15:03:26 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

t_list	*list_shift(t_list **head)
{
	t_list	*node;

	if (!head)
		return (NULL);
	node = *head;
	if (node)
	{
		*head = (*head)->next;
		node->next = NULL;
	}
	return (node);
}
