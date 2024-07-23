/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:55:20 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/23 18:47:52 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "quicksort.h"
#include "stack/stack.h"
#include "stack/list/list.h"
#include "writef/writef.h"

void	state_execute_push_swap(t_state *state)
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
}

int	main(int argc, const char **argv)
{
	t_state	state;

	(void)argc;
	state_start(&state, &argv[1]);
	if (state.is_error)
		writefd(2, "Error\n");
	else
		state_execute_push_swap(&state);
	return (state_cleanup(&state), state.is_error);
}
