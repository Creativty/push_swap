/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:56:27 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 11:56:31 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

void	quicksort_a2b_place(t_quicksort *sort, t_state *state)
{
	int	i;
	int	j;

	i = 0;
	while (i < sort->range)
	{
		j = state->stack_a->index;
		if (j >= (sort->max_idx - sort->count))
		{
			state_action_verbose(state, "ra\n");
			sort->ra++;
		}
		else
		{
			state_action_verbose(state, "pb\n");
			sort->pb++;
			if (j >= (sort->min_idx + sort->count))
			{
				state_action_verbose(state, "rb\n");
				sort->rb++;
			}
		}
		i++;
	}
}

void	quicksort_b2a_place(t_quicksort *sort, t_state *state)
{
	int	i;
	int	j;

	i = 0;
	while (i < sort->range)
	{
		j = state->stack_b->index;
		if (j < sort->min_idx + sort->count)
		{
			state_action_verbose(state, "rb\n");
			sort->rb++;
		}
		else
		{
			state_action_verbose(state, "pa\n");
			sort->pa++;
			if (j < sort->max_idx - sort->count)
			{
				state_action_verbose(state, "ra\n");
				sort->ra++;
			}
		}
		i++;
	}
}
