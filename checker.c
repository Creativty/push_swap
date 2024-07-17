/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:28:09 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 13:30:57 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "writef/writef.h"

int	main(int argc, const char **argv)
{
	t_state	state;

	(void)argc;
	state_start(&state, &argv[1]);
	if (state.is_error)
		writef("Error\n");
	if (state_halt(&state)) {
		if (list_size((t_list *)state.stack_a) > 0)
			writef("OK\n");
	}
	else
		writef("KO\n");
	return (state_cleanup(&state), state.is_error);
}
