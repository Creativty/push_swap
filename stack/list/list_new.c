/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:01:14 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 18:20:26 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*list_new(void)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
		node->next = NULL;
	return (node);
}
