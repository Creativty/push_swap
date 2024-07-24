/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:56:41 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 12:01:44 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "../writef/writef.h"
#include <stddef.h>

void	stack_print(t_stack *stack)
{
	if (stack)
	{
		writef(
			"stack %p has value %d and index %d and points towards %p\n",
			stack, stack->value, stack->index, stack->next);
		stack_print((t_stack *)stack->next);
	}
}

int	main(void)
{
	t_stack		*stack;
	const int	data[3] = {4, 0, 3};
	const int	indices[3] = {3, 1, 2};

	stack_spread_array(&stack, (int *)data, (int *)indices, 3);
	stack_print(stack);
	stack_free(stack);
	return (0);
}
