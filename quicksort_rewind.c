/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_rewind.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:56:46 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 11:56:52 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

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
