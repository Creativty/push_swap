/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:38:38 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/28 09:37:03 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "string/string.h"
#include "writef/writef.h"

long	state_atoi_parse(t_state *state, const char *arg, int i)
{
	long	n;

	n = 0;
	while (string_includes("0123456789", arg[i]))
	{
		n = (n * 10) + (long)(arg[i++] - '0');
		if (n > (long)INT_MAX || n < (long)INT_MIN)
			return (state_set_error(state, 1), -1);
	}
	if (i == 0 || !string_includes("0123456789", arg[i - 1]))
		return (state_set_error(state, 1), -1);
	else
		return (n);
}

int	state_atoi(t_state *state, const char *arg)
{
	long	sign;

	sign = 1;
	if (!arg || !string_length(arg) || string_includes_not(arg, "-+0123456789"))
		return (state_set_error(state, 1), -1);
	if (*arg == '-')
		sign = -1;
	return (state_atoi_parse(state, arg, *arg == '-' || *arg == '+') * sign);
}

void	state_set_error(t_state *state, int error)
{
	state->is_error = state->is_error || error;
}

static void	stack_print(t_stack *stack)
{
	if (stack)
	{
		writef(
			"\tstack node %p has value %d and index %d and points towards %p\n",
			stack, stack->value, stack->index, stack->next);
		stack_print((t_stack *)stack->next);
	}
	else
	{
		writef("\tstack node (null)\n");
	}
}

void	state_print(t_state *state)
{
	writef("-----------------------\n");
	stack_print(state->stack_a);
	writef("-----------------------\n");
	stack_print(state->stack_b);
	writef("-----------------------\n");
}
