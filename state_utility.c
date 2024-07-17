/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:38:38 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 13:40:54 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "string/string.h"
#include "writef/writef.h"

void	state_set_error(t_state *state, int error)
{
	state->is_error = state->is_error || error;
}

int	state_atoi(t_state *state, const char *arg)
{
	int		i;
	long	n;
	long	sign;

	n = 0;
	i = 0;
	sign = 1;
	state_set_error(state, string_includes_not(arg, "-0123456789"));
	if (!arg || state->is_error)
		return (n);
	if (arg[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (string_includes("0123456789", arg[i]))
		n = (n * 10) + (long)(arg[i++] - '0');
	if (n > (long)INT_MAX || n < (long)INT_MIN)
		return (state_set_error(state, 1), -1);
	return (n * sign);
}

static void	stack_print(t_stack *stack)
{
	if (stack) {
		writef("\tstack node %p has value %d and index %d and points towards %p\n", stack, stack->value, stack->index, stack->next);
		stack_print((t_stack *)stack->next);
	} else {
		writef("\tstack node (null)\n");
	}
}

void	state_print(t_state *state)
{
	writef("-----------------------------------------------------------------------------------------------------------------------\n");
	stack_print(state->stack_a);
	writef("-----------------------------------------------------------------------------------------------------------------------\n");
	stack_print(state->stack_b);
	writef("-----------------------------------------------------------------------------------------------------------------------\n");
}
