/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:03:46 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 15:03:50 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_tail(t_list *head)
{
	t_list	*tail;

	tail = head;
	while (tail && tail->next)
		tail = tail->next;
	return (tail);
}
