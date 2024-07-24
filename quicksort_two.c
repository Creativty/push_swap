/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:55:13 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 11:55:47 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a2b_two(t_state *state)
{
	if (state->stack_a->index > ((t_stack *)state->stack_a->next)->index)
		state_action_verbose(state, "sa\n");
}

void	quicksort_b2a_two(t_state *state)
{
	if (state->stack_b->index < ((t_stack *)state->stack_b->next)->index)
		state_action_verbose(state, "sb\n");
}
