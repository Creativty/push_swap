/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:07:04 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 15:08:58 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

t_list	*list_at(t_list *head, int position)
{
	int		index;
	t_list	*iter;

	if (position < 0)
		position = (-position) % list_size(head);
	iter = head;
	index = 0;
	while (iter)
	{
		if (index++ == position)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}
