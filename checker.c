/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:28:09 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 11:49:49 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "input/input.h"
#include "writef/writef.h"
#include "string/string.h"
#include <stdlib.h>

void	state_execute_checker(t_state *state)
{
	char	*command;

	command = NULL;
	while (!state->is_error)
	{
		command = input_readline(STDIN);
		if (!command || string_length(command) == 0)
			break ;
		if (!state_action_execute(state, command))
			state->is_error = 1;
		free(command);
	}
}

int	main(int argc, const char **argv)
{
	t_state	state;

	(void)argc;
	state_start(&state, &argv[1]);
	if (state.is_error)
		return (writefd(2, "Error\n"), state.is_error);
	else if (list_size(state.stack_a) > 0)
		state_execute_checker(&state);
	if (!state.is_error)
	{
		if (state_halt(&state))
		{
			if (list_size((t_list *)state.stack_a) > 0)
				writef("OK\n");
		}
		else
			writef("KO\n");
	}
	else
		writefd(2, "Error\n");
	return (state_cleanup(&state), state.is_error);
}
