/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:58:08 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/20 09:36:45 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "quicksort.h"
#include "push_swap.h"

void	quicksort_a2b_three(t_state *state)
{
	int	list[3];

	list[0] = stack_at(state->stack_a, 2)->index;
	list[1] = stack_at(state->stack_a, 1)->index;
	list[2] = stack_at(state->stack_a, 0)->index;
	if (list[0] < list[1] && list[1] > list[2])
	{
		state_action_verbose(state, "ra\n");
		state_action_verbose(state, "sa\n");
		state_action_verbose(state, "rra\n");
		state_action_verbose(state, "sa\n");
	}
	else if (list[1] < list[2] && list[0] < list[1])
	{
		state_action_verbose(state, "sa\n");
		state_action_verbose(state, "ra\n");
		state_action_verbose(state, "sa\n");
		state_action_verbose(state, "rra\n");
	}
	else if (list[1] < list[2] && list[0] > list[1] && list[0] < list[2])
	{
		state_action_verbose(state, "sa\n");
		state_action_verbose(state, "ra\n");
		state_action_verbose(state, "sa\n");
		state_action_verbose(state, "rra\n");
	}
	if (stack_at(state->stack_a, 1)->index < stack_at(state->stack_a, 0)->index)
		state_action_verbose(state, "sa\n");
}

void	quicksort_b2a_three(t_state *state)
{
	int	list[3];

	list[0] = stack_at(state->stack_b, 2)->index;
	list[1] = stack_at(state->stack_b, 1)->index;
	list[2] = stack_at(state->stack_b, 0)->index;
	if (list[0] > list[1] && list[1] < list[2])
	{
		state_action_verbose(state, "rb\n");
		state_action_verbose(state, "sb\n");
		state_action_verbose(state, "rrb\n");
		state_action_verbose(state, "sb\n");
	}
	else if (list[1] > list[2] && list[0] > list[1])
	{
		state_action_verbose(state, "sb\n");
		state_action_verbose(state, "rb\n");
		state_action_verbose(state, "sb\n");
		state_action_verbose(state, "rrb\n");
	}
	else if (list[1] > list[2] && list[0] < list[1] && list[0] > list[2])
	{
		state_action_verbose(state, "sb\n");
		state_action_verbose(state, "rb\n");
		state_action_verbose(state, "sb\n");
		state_action_verbose(state, "rrb\n");
	}
	// else if (list[1] > list[2] && (list[0] > list[1] || list[0] > list[2]))
	if (stack_at(state->stack_b, 1)->index > stack_at(state->stack_b, 0)->index)
		state_action_verbose(state, "sb\n");
}

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

typedef struct s_quicksort
{
	int	range;
	int	count;
	int	min_idx;
	int	max_idx;
	int	ra;
	int	pa;
	int	rb;
	int	pb;
}	t_quicksort;

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

void	quicksort_rewind(t_quicksort sort, t_state *state)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < sort.ra && b < sort.rb)
	{
		state_action_verbose(state, "rrr\n");
		a++;
		b++;
	}
	while (a < sort.ra)
	{
		state_action_verbose(state, "rra\n");
		a++;
	}
	while (b < sort.rb)
	{
		state_action_verbose(state, "rrb\n");
		b++;
	}
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
