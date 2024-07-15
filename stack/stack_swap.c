/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:54:34 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 16:56:28 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap(t_stack **stack)
{
	t_list	*a;
	t_list	*b;

	if (!stack || list_size((t_list*)*stack) < 2)
		return ;
	a = list_shift((t_list**)stack);
	b = list_shift((t_list**)stack);
	list_insert((t_list**)stack, a);
	list_insert((t_list**)stack, b);
}
