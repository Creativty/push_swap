/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:56:41 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 18:26:21 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "../writef/writef.h"
#include <stddef.h>

void	stack_print(t_stack *stack)
{
	if (stack) {
		writef("stack %p has value %d and index %d and points towards %p\n", stack, stack->value, stack->index, stack->next);
		stack_print((t_stack *)stack->next);
	}
}

int	main(void)
{
	t_stack	*stack = NULL;
	int	data[] = { 4, 0, 3 };
	int	indices[] = { 3, 1, 2 };
	stack_spread_array(&stack, data, indices, 3);
	stack_print(stack);
	stack_free(stack);
	return (0);
}
