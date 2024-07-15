/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:55:20 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/15 13:42:43 by aindjare         ###   ########.fr       */
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

void	mech_turk_procedure(t_state *state)
{
	(void)state;
}

void	state_sorter_mech_turk(t_state *state)
{
	t_stack	**stack;

	stack = &state->stack_a;
	while (!stack_is_sorted_asc(*stack) && list_size(*stack) > 3)
	{
		if (list_size(state->stack_b) > 2)
			mech_turk_procedure(state);
		else if (list_size(state->stack_b) > 0)
			state_action_verbose(state, "pb\n");
		else
			break ;
	}
	state_sorter_three(state);
}

void	state_execute(t_state *state)
{
	int	len;

	if (stack_is_sorted_asc(state->stack_a))
		return ;
	len = list_size(state->stack_a);
	if (len == 2)
		state_action_verbose(state, "sa\n");
	if (len == 3)
		state_sorter_three(state);
	if (len <= 5)
		state_sorter_mech_turk(state);
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
