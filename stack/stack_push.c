/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:52:11 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 16:54:17 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stack **from, t_stack **to)
{
	if (!from || !to)
		return ;
	list_append((t_list**)to, list_shift((t_list**)from));
}
