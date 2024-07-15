/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:02:32 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 15:02:47 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_append(t_list **head, t_list *node)
{
	t_list	*slot;

	if (!head)
		return ;
	if (*head)
	{
		slot = *head;
		while (slot && slot->next)
			slot = slot->next;
		slot->next = node;
	}
	else
		*head = node;
}
