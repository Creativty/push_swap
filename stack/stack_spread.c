/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_spread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:26:40 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 12:02:11 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stddef.h>

void	stack_spread_array(t_stack **stack, int *data, int *indices, int size)
{
	int		i;
	t_stack	*iter;

	if (!stack || !data || !indices || size <= 0)
		return ;
	i = 0;
	while (i < size)
	{
		iter = stack_new(data[i], indices[i], NULL);
		if (iter)
			list_append((t_list **)stack, (t_list *)iter);
		else
			break ;
		i++;
	}
}
