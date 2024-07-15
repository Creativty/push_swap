/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:04:16 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/11 18:06:04 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

unsigned int	list_size(void *head)
{
	unsigned int	i;

	i = 0;
	while (head)
	{
		i++;
		head = ((t_list *)head)->next;
	}
	return (i);
}
