/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_includes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:37:51 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/12 09:39:22 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_includes(t_stack *stack, int value)
{
	t_stack	*iter;

	iter = stack;
	while (iter)
	{
		if (stack->value == value)
			return (1);
		iter = (t_stack *)iter->next;
	}
	return (0);
}
