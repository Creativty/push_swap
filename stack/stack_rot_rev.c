/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rot_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:51:00 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 11:59:48 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_rotate_reverse(t_stack **stack)
{
	if (!stack || list_size((t_list *)(*stack)) < 2)
		return ;
	list_insert((t_list **)stack, list_pop((t_list **)stack));
}
