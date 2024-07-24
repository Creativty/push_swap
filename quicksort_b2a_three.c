/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b2a_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:54:34 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 11:54:40 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_b2a_three_middle(t_state *state)
{
	state_action_verbose(state, "rb\n");
	state_action_verbose(state, "sb\n");
	state_action_verbose(state, "rrb\n");
	state_action_verbose(state, "sb\n");
}

void	quicksort_b2a_three_surround(t_state *state)
{
	state_action_verbose(state, "sb\n");
	state_action_verbose(state, "rb\n");
	state_action_verbose(state, "sb\n");
	state_action_verbose(state, "rrb\n");
}

void	quicksort_b2a_three(t_state *state)
{
	int	list[3];

	list[0] = stack_at(state->stack_b, 2)->index;
	list[1] = stack_at(state->stack_b, 1)->index;
	list[2] = stack_at(state->stack_b, 0)->index;
	if (list[0] > list[1] && list[1] < list[2])
		quicksort_b2a_three_middle(state);
	else if (list[1] > list[2] && list[0] > list[1])
		quicksort_b2a_three_surround(state);
	else if (list[1] > list[2] && list[0] < list[1] && list[0] > list[2])
		quicksort_b2a_three_surround(state);
	if (stack_at(state->stack_b, 1)->index > stack_at(state->stack_b, 0)->index)
		state_action_verbose(state, "sb\n");
}
