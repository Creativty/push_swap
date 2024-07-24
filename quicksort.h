/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:02:12 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 11:57:49 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

# include "push_swap.h"

typedef struct s_quicksort
{
	int	range;
	int	count;
	int	min_idx;
	int	max_idx;
	int	ra;
	int	pa;
	int	rb;
	int	pb;
}	t_quicksort;

void	quicksort_a2b_place(t_quicksort *sort, t_state *state);
void	quicksort_a2b_three(t_state *state);
void	quicksort_a2b_two(t_state *state);
void	quicksort_a2b(t_state *state, int len);

void	quicksort_rewind(t_quicksort sort, t_state *state);

void	quicksort_b2a_place(t_quicksort *sort, t_state *state);
void	quicksort_b2a_three(t_state *state);
void	quicksort_b2a_two(t_state *state);
void	quicksort_b2a(t_state *state, int len);

#endif
