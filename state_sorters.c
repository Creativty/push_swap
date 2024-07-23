/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_sorters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:12:36 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 17:12:55 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "quicksort.h"

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

void	state_sorter_quicksort(t_state *state)
{
	quicksort_a2b(state, state->length_a);
}

void	state_sorter_four(t_state *state)
{
	if (stack_at(state->stack_a, 0)->index == 3)
		state_action_verbose(state, "ra\n");
	while (stack_at(state->stack_a, 3)->index != 3)
		state_action_verbose(state, "rra\n");
	quicksort_a2b_three(state);
}

void	state_sorter_five(t_state *state)
{
	int	i;

	while (list_size(state->stack_a) > 3)
	{
		i = 0;
		while (stack_at(state->stack_a, i)->index > 1)
			i++;
		while (stack_at(state->stack_a, 0)->index > 1)
		{
			if (i <= 2)
				state_action_verbose(state, "ra\n");
			else
				state_action_verbose(state, "rra\n");
		}
		state_action_verbose(state, "pb\n");
	}
	state_sorter_three(state);
	if (!stack_is_sorted_desc(state->stack_b))
		state_action_verbose(state, "sb\n");
	state_action_verbose(state, "pa\n");
	state_action_verbose(state, "pa\n");
}
