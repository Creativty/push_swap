/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_indices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:14:24 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/12 10:15:45 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_set_indices(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i)
	{
		j = (t_stack *)i->next;
		while (j)
		{
			if (j->value > i->value)
				j->index++;
			else
				i->index++;
			j = (t_stack *)j->next;
		}
		i = (t_stack *)i->next;
	}
}
