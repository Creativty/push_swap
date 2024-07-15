/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:55:20 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/13 14:32:42 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.h"
#include "stack/list/list.h"
#include "memory/memory.h"
#include "writef/writef.h"
#include "string/string.h"
#include <limits.h>
#include <stddef.h>

typedef struct s_state
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		is_error;
}	t_state;

void	stack_print(t_stack *stack)
{
	if (stack) {
		writef("\tstack node %p has value %d and index %d and points towards %p\n", stack, stack->value, stack->index, stack->next);
		stack_print((t_stack *)stack->next);
	} else {
		writef("\tstack node (null)\n");
	}
}

void	state_print(t_state *state)
{
	writef("-----------------------------------------------------------------------------------------------------------------------\n");
	stack_print(state->stack_a);
	writef("-----------------------------------------------------------------------------------------------------------------------\n");
	stack_print(state->stack_b);
	writef("-----------------------------------------------------------------------------------------------------------------------\n");
}

void	state_set_error(t_state *state, int error)
{
	state->is_error = state->is_error || error;
}

int	state_atoi(t_state *state, const char *arg)
{
	int		i;
	long	n;
	long	sign;

	n = 0;
	i = 0;
	sign = 1;
	state_set_error(state, string_includes_not(arg, "-0123456789"));
	if (!arg || state->is_error)
		return (n);
	if (arg[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (string_includes("0123456789", arg[i]))
		n = (n * 10) + (long)(arg[i++] - '0');
	if (n > (long)INT_MAX || n < (long)INT_MIN)
		return (state_set_error(state, 1), -1);
	return (n * sign);
}

void	state_collect_argv(t_state *state, const char **argv)
{
	int		n;
	t_stack	*node;

	while (*argv && !state->is_error)
	{
		n = state_atoi(state, *argv);
		if (stack_includes(state->stack_a, n))
			state->is_error = 1;
		if (state->is_error)
			break ;
		node = stack_new(n, 0, NULL);
		if (node)
			list_append((t_list **)&state->stack_a, (t_list *)node);
		else
			state->is_error = 1;
		++argv;
	}
}

void	state_cleanup(t_state *state)
{
	stack_free(state->stack_a);
	stack_free(state->stack_b);
}

void	state_check_duplicates(t_state *state)
{
	t_stack	*i;
	t_stack	*j;

	i = state->stack_a;
	while (!state->is_error && i)
	{
		j = (t_stack *)i->next;
		while (!state->is_error && j)
		{
			if (j->value == i->value)
				state->is_error = 1;
			j = (t_stack *)j->next;
		}
		i = (t_stack *)i->next;
	}
}

void	state_start(t_state *state, const char **argv)
{
	memory_zero(state, sizeof(t_state));
	state_collect_argv(state, argv);
	state_check_duplicates(state);
	if (state->is_error)
		return ;
	stack_set_indices(state->stack_a);
}

static inline void	state_rotate(t_state *state)
{
	stack_rotate(&state->stack_a);
	stack_rotate(&state->stack_b);
}

static inline void	state_rotate_reverse(t_state *state)
{
	stack_rotate_reverse(&state->stack_a);
	stack_rotate_reverse(&state->stack_b);
}

int	state_action_execute(t_state *state, const char *action)
{
	if (string_equals("ra\n", action))
		return (stack_rotate(&state->stack_a), 1);
	else if (string_equals("rb\n", action))
		return (stack_rotate(&state->stack_b), 1);
	else if (string_equals("rr\n", action))
		return (state_rotate(state), 1);
	else if (string_equals("rra\n", action))
		return (stack_rotate_reverse(&state->stack_a), 1);
	else if (string_equals("rrb\n", action))
		return (stack_rotate_reverse(&state->stack_b), 1);
	else if (string_equals("rrr\n", action))
		return (state_rotate_reverse(state), 1);
	else if (string_equals("sa\n", action))
		return (stack_swap(&state->stack_a), 1);
	else if (string_equals("sb\n", action))
		return (stack_swap(&state->stack_b), 1);
	else if (string_equals("ss\n", action))
		return (stack_swap(&state->stack_b), 1);
	else if (string_equals("pa\n", action))
		return (stack_push(&state->stack_b, &state->stack_a), 1);
	else if (string_equals("pb\n", action))
		return (stack_push(&state->stack_b, &state->stack_a), 1);
	else
		return (0);
}

void	state_action_verbose(t_state *state, const char *action)
{
	if (state_action_execute(state, action))
		writef("%s", action);
}

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

void state_sorter_mech_turk(t_state *state)
{
	while (!stack_is_sorted_asc(state->stack_a) && list_size(state->stack_a) > 3)
	{
		if (list_size(state->stack_b) > 2)
			mech_turk_procedure(state);
		else
			state_action_verbose(state, "pb\n");
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

int	state_halt(t_state *state)
{
	state->is_error = state->is_error || (list_size(state->stack_b) > 0);
	if (state->is_error)
		return (0);
	return (stack_is_sorted_asc(state->stack_a));
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
	// if (state_halt(&state)) {
	// 	if (list_size((t_list *)state.stack_a) > 0)
	// 		writef("OK\n");
	// }
	// else
	// 	writef("KO\n");
	return (state_cleanup(&state), state.is_error);
}
