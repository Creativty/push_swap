/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:47:38 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 11:59:37 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_rotate(t_stack **stack)
{
	if (!stack || list_size((t_list *)(*stack)) < 2)
		return ;
	list_append((t_list **)stack, list_shift((t_list **)stack));
}
