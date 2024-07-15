/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:55:27 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/11 18:00:44 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_is_sorted_asc(t_stack *stack)
{
	t_stack	*iter;

	iter = stack;
	while (iter)
	{
		if (iter->next)
			if (iter->index > ((t_stack *)iter->next)->index)
				return (0);
		iter = (t_stack *)iter->next;
	}
	return (1);
}

int	stack_is_sorted_desc(t_stack *stack)
{
	t_stack	*iter;

	iter = stack;
	while (iter)
	{
		if (iter->next)
			if (iter->index < ((t_stack *)iter->next)->index)
				return (0);
		iter = (t_stack *)iter->next;
	}
	return (1);
}
