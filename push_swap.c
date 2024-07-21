/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:55:20 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/20 14:11:25 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "quicksort.h"
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

void	state_sorter_quicksort(t_state *state)
{
	quicksort_a2b(state, state->length_a);
	for (t_stack *node = state->stack_a; node; node = (t_stack *)node->next)
		writef("%d ", node->index);
	writef("\n");
}

void	quicksort_a2b_three(t_state *state);

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
	else if (len == 4)
		state_sorter_four(state);
	else if (len == 5)
		state_sorter_five(state);
	else
		state_sorter_quicksort(state);
	if (stack_is_sorted_asc(state->stack_a))
		writef("stack a is sorted.\n");
	if (list_size(state->stack_b) == 0)
		writef("stack b is empty.\n");
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
