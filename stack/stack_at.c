/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:29:39 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/12 20:34:59 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stddef.h>

t_stack	*stack_at(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack && i < index)
	{
		i++;
		stack = (t_stack *)stack->next;
	}
	if (i == index)
		return (stack);
	else
		return (NULL);
}
