/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:58:08 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 11:58:17 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "quicksort.h"
#include "push_swap.h"

void	quicksort_init(t_quicksort *sort, t_stack *stack, int len)
{
	int		i;
	t_stack	*iter;

	i = 0;
	sort->ra = 0;
	sort->rb = 0;
	sort->pa = 0;
	sort->pb = 0;
	sort->range = len;
	sort->max_idx = 0;
	sort->min_idx = INT_MAX;
	iter = stack;
	while (iter && i < len)
	{
		if ((int)iter->index > sort->max_idx)
			sort->max_idx = iter->index;
		if ((int)iter->index < sort->min_idx)
			sort->min_idx = iter->index;
		iter = (t_stack *)iter->next;
		i++;
	}
	sort->count = (sort->max_idx - sort->min_idx) / 3;
}

void	quicksort_b2a(t_state *state, int len)
{
	int			i;
	t_quicksort	sort;

	i = 0;
	if (len <= 3)
	{
		if (len == 3)
			quicksort_b2a_three(state);
		else if (len == 2)
			quicksort_b2a_two(state);
		while (i++ < len)
			state_action_verbose(state, "pa\n");
		return ;
	}
	quicksort_init(&sort, state->stack_b, len);
	quicksort_b2a_place(&sort, state);
	quicksort_a2b(state, sort.pa - sort.ra);
	quicksort_rewind(sort, state);
	quicksort_a2b(state, sort.ra);
	quicksort_b2a(state, sort.rb);
}

void	quicksort_a2b(t_state *state, int len)
{
	t_quicksort	sort;

	if (stack_is_sorted_asc(state->stack_a))
		return ;
	if (len <= 3)
	{
		if (len == 3)
			quicksort_a2b_three(state);
		else if (len == 2)
			quicksort_a2b_two(state);
		return ;
	}
	quicksort_init(&sort, state->stack_a, len);
	quicksort_a2b_place(&sort, state);
	quicksort_rewind(sort, state);
	quicksort_a2b(state, sort.ra);
	quicksort_b2a(state, sort.rb);
	quicksort_b2a(state, sort.pb - sort.rb);
}
