/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:34:13 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/21 13:31:19 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack/stack.h"
#include "string/string.h"
#include "writef/writef.h"

static inline void	state_rotate(t_state *state)
{
	stack_rotate(&state->stack_a);
	stack_rotate(&state->stack_b);
}

static inline void	state_rotate_reverse(t_state *state)
{
	stack_rotate_reverse(&state->stack_a);
	stack_rotate_reverse(&state->stack_b);
}

int	state_action_execute(t_state *state, const char *action)
{
	if (string_equals("ra\n", action))
		return (stack_rotate(&state->stack_a), 1);
	else if (string_equals("rb\n", action))
		return (stack_rotate(&state->stack_b), 1);
	else if (string_equals("rr\n", action))
		return (state_rotate(state), 1);
	else if (string_equals("rra\n", action))
		return (stack_rotate_reverse(&state->stack_a), 1);
	else if (string_equals("rrb\n", action))
		return (stack_rotate_reverse(&state->stack_b), 1);
	else if (string_equals("rrr\n", action))
		return (state_rotate_reverse(state), 1);
	else if (string_equals("sa\n", action))
		return (stack_swap(&state->stack_a), 1);
	else if (string_equals("sb\n", action))
		return (stack_swap(&state->stack_b), 1);
	else if (string_equals("ss\n", action))
		return (stack_swap(&state->stack_b), 1);
	else if (string_equals("pa\n", action))
		return (stack_push(&state->stack_b, &state->stack_a), 1);
	else if (string_equals("pb\n", action))
		return (stack_push(&state->stack_a, &state->stack_b), 1);
	else
		return (0);
}

void	state_action_verbose(t_state *state, const char *action)
{
	if (state_action_execute(state, action))
	{
		writef("%s", action);
		state->length_a = list_size(state->stack_a);
		state->length_b = list_size(state->stack_b);
	}
}
