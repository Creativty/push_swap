/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:08:57 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/18 11:34:24 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "stack.h"

t_stack	*stack_find_min(t_stack *stack)
{
	int		min;
	t_stack	*pref;
	t_stack	*iter;

	min = INT_MAX;
	iter = stack;
	pref = stack;
	while (iter)
	{
		if (iter->index < min)
		{
			min = iter->index;
			pref = iter;
		}
		iter = (t_stack *)iter->next;
	}
	return (pref);
}

t_stack	*stack_find_max(t_stack *stack)
{
	int	max;
	t_stack	*pref;
	t_stack	*iter;

	max = INT_MIN;
	iter = stack;
	pref = stack;
	while (iter)
	{
		if (iter->index > max)
		{
			max = iter->index;
			pref = iter;
		}
		iter = (t_stack *)iter->next;
	}
	return (pref);
}
