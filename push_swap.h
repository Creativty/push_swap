/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:25:24 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 11:48:12 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack/stack.h"

typedef struct s_state
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		length_a;
	int		length_b;
	int		is_error;
}	t_state;

void	state_start(t_state *state, const char **argv);
void	state_execute_push_swap(t_state *state);
void	state_cleanup(t_state *state);
int		state_halt(t_state *state);

void	state_check_duplicates(t_state *state);
void	state_collect_argv(t_state *state, const char **argv);

void	state_action_verbose(t_state *state, const char *action);
int		state_action_execute(t_state *state, const char *action);

int		state_atoi(t_state *state, const char *arg);
void	state_set_error(t_state *state, int error);
void	state_print(t_state *state);

void	state_sorter_quicksort(t_state *state);
void	state_sorter_three(t_state *state);
void	state_sorter_four(t_state *state);
void	state_sorter_five(t_state *state);

#endif
