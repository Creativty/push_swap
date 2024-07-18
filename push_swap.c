/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:55:20 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/18 12:44:21 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include "push_swap.h"
#include "stack/stack.h"
#include "stack/list/list.h"
#include "writef/writef.h"

void	state_sorter_three(t_state *state)
{
	int		idx[3];
	t_stack	**stack;

	stack = &state->stack_a;
	while (!stack_is_sorted_asc(*stack) && list_size(*stack) == 3)
	{
		idx[0] = stack_at(state->stack_a, 0)->index;
		idx[1] = stack_at(state->stack_a, 1)->index;
		idx[2] = stack_at(state->stack_a, 2)->index;
		if (idx[1] > idx[0] && idx[1] > idx[2])
			state_action_verbose(state, "rra\n");
		else if (idx[0] > idx[1] && idx[0] > idx[2])
			state_action_verbose(state, "ra\n");
		else
			state_action_verbose(state, "sa\n");
	}
}

t_stack	*stack_turkish_nearest(t_stack *stack, int base)
{
	int		dist;
	t_stack	*iter;
	t_stack	*pref;

	dist = INT_MAX;
	iter = stack;
	pref = stack;
	while (iter)
	{
		if (iter->index < base && base - iter->index < dist)
		{
			dist = iter->index - base;
			pref = iter;
		}
		iter = (t_stack *)iter->next;
	}
	if (pref)
		return (pref);
	else
		return (stack_find_max(stack));
}

void	sorter_turkish_internal(t_state *state)
{
	// int	desired_index = state->stack_a->index;
	// t_stack	*sibling = stack_turkish_nearest(state->stack_b, desired_index);
	state_action_verbose(state, "pb\n");
}

void	state_sorter_turkish(t_state *state)
{
	state_print(state);
	while (list_size(state->stack_a) > 3)
	{
		if (list_size(state->stack_b) >= 2)
			sorter_turkish_internal(state);
		else
			state_action_verbose(state, "pb\n");
	}
	// Only three elements remaining.
	state_sorter_three(state);
	state_print(state);
}

void	state_execute(t_state *state)
{
	int	len;

	if (stack_is_sorted_asc(state->stack_a))
		return ;
	len = list_size(state->stack_a);
	if (len == 2)
		state_action_verbose(state, "sa\n");
	else if (len == 3)
		state_sorter_three(state);
	else
		state_sorter_turkish(state);
	state_set_error(state, !stack_is_sorted_asc(state->stack_a));
	state_set_error(state, list_size(state->stack_b) > 0);
}

int	main(int argc, const char **argv)
{
	t_state	state;

	(void)argc;
	state_start(&state, &argv[1]);
	if (state.is_error)
		writef("Error\n");
	else
		state_execute(&state);
	return (state_cleanup(&state), state.is_error);
}
