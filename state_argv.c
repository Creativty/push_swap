/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:26:35 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/25 09:35:39 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string/string.h"
#include "memory/memory.h"
#include <stddef.h>

int	state_collect_argv_group(t_state *state, const char *arg)
{
	char	**argv;

	if (string_includes(arg, ' '))
	{
		argv = string_split(arg, ' ');
		if (argv && memory_length((void **)argv) > 0)
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
