/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a2b_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:10 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:39 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a2b_three_middle(t_state *state)
{
	state_action_verbose(state, "ra\n");
	state_action_verbose(state, "sa\n");
	state_action_verbose(state, "rra\n");
	state_action_verbose(state, "sa\n");
}

void	quicksort_a2b_three_surround(t_state *state)
{
	state_action_verbose(state, "sa\n");
	state_action_verbose(state, "ra\n");
	state_action_verbose(state, "sa\n");
	state_action_verbose(state, "rra\n");
}

void	quicksort_a2b_three(t_state *state)
{
	int	list[3];

	list[0] = stack_at(state->stack_a, 2)->index;
	list[1] = stack_at(state->stack_a, 1)->index;
	list[2] = stack_at(state->stack_a, 0)->index;
	if (list[0] < list[1] && list[1] > list[2])
		quicksort_a2b_three_middle(state);
	else if (list[1] < list[2] && list[0] < list[1])
		quicksort_a2b_three_surround(state);
	else if (list[1] < list[2] && list[0] > list[1] && list[0] < list[2])
		quicksort_a2b_three_surround(state);
	if (stack_at(state->stack_a, 1)->index < stack_at(state->stack_a, 0)->index)
		state_action_verbose(state, "sa\n");
}
