/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:28:09 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/23 13:06:58 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "input/input.h"
#include "writef/writef.h"
#include <stdlib.h>

void	state_execute_checker(t_state *state)
{
	char	*command;

	command = NULL;
	while (!state->is_error)
	{
		command = input_readline(STDIN);
		if (!command)
			break ;
		if (!state_action_execute(state, command))
		{
			writef("unrecognized command: %s", command);
			// writef("Error\n");
			// state->is_error = 1;
		}
		free(command);
	}
}

int	main(int argc, const char **argv)
{
	t_state	state;

	(void)argc;
	state_start(&state, &argv[1]);
	if (state.is_error)
		writef("Error\n");
	else
		state_execute_checker(&state);
	if (!state.is_error)
	{
		if (state_halt(&state)) {
			if (list_size((t_list *)state.stack_a) > 0)
				writef("OK\n");
		}
		else
			writef("KO\n");
	}
	return (state_cleanup(&state), state.is_error);
}
