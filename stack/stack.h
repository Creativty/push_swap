/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:30:35 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/19 17:19:58 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include "list/list.h"

typedef struct s_stack
{
	struct s_list	*next;
	int				value;
	int				index;
}	t_stack;

t_stack	*stack_new(int value, int index, void *next);
void	stack_free(t_stack *stack);

void	stack_spread_array(t_stack **stack, int *data, int *indices, int size);
void	stack_push(t_stack **from, t_stack **to);
void	stack_swap(t_stack **stack);
void	stack_rotate(t_stack **stack);
void	stack_rotate_reverse(t_stack **stack);
int		stack_is_sorted_asc(t_stack *stack);
int		stack_is_sorted_desc(t_stack *stack);
int		stack_includes(t_stack *stack, int value);
void	stack_set_indices(t_stack *stack);
void	stack_set_indices_zeroed(t_stack *stack);
t_stack	*stack_at(t_stack *stack, int index);
t_stack	*stack_find_max(t_stack *stack);
t_stack	*stack_find_min(t_stack *stack);

#endif
