/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:02:12 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 17:14:44 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QUICKSORT_H
#define QUICKSORT_H

typedef struct s_state t_state;

void	quicksort_a2b_three(t_state *state);
void	quicksort_a2b(t_state *state, int len);
void	quicksort_b2a(t_state *state, int len);

#endif
