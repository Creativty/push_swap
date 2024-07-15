/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:16:56 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 18:31:47 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*stack_new(int value, int index, void *next)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->next = next;
		stack->index = index;
		stack->value = value;
	}
	return (stack);
}

void	stack_free(t_stack *stack)
{
	if (stack)
		stack_free((t_stack*)stack->next);
	free(stack);
}
