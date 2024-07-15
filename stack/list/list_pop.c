/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:03:56 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 15:12:39 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

t_list	*list_pop(t_list **head)
{
	t_list	*tail;
	t_list	*iter;

	if (!head)
		return (NULL);
	tail = list_tail(*head);
	iter = *head;
	while (iter)
	{
		if (iter == tail)
			*head = NULL;
		if (iter->next == tail)
			iter->next = NULL;
		iter = iter->next;
	}
	return (tail);
}
