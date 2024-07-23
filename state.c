/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:32:19 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/23 18:43:37 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "push_swap.h"
#include "stack/stack.h"
#include "memory/memory.h"
#include "string/string.h"

int	state_halt(t_state *state)
{
	state->is_error = state->is_error || (list_size(state->stack_b) > 0);
	if (state->is_error)
		return (0);
	return (stack_is_sorted_asc(state->stack_a));
}

void	state_start(t_state *state, const char **argv)
{
	if (!state)
		return ;
	memory_zero(state, sizeof(t_state));
	state_collect_argv(state, argv);
	state_check_duplicates(state);
	if (state->is_error)
		return ;
	state->length_a = list_size(state->stack_a);
	state->length_b = list_size(state->stack_b);
	stack_set_indices(state->stack_a);
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

void	state_cleanup(t_state *state)
{
	stack_free(state->stack_a);
	stack_free(state->stack_b);
}

int	state_collect_argv_group(t_state *state, const char *arg)
{
	char	**argv;

	if (string_includes(arg, ' '))
	{
		argv = string_split(arg, ' ');
		if (argv)
		{
			state_collect_argv(state, (const char **)argv);
			return (memory_free_cstyle((void **)argv, 1), 1);
		}
		else
		{
			state->is_error = 1;
			return (0);
		}
	}
	else
		return (0);
}

void	state_collect_argv(t_state *state, const char **argv)
{
	int		n;
	t_stack	*node;

	while (*argv && !state->is_error)
	{
		if (!state_collect_argv_group(state, *argv))
		{
			if (state->is_error)
				break ;
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
		}
		++argv;
	}
}
