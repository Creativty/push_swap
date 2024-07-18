/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:52:11 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/18 12:41:27 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stack **from, t_stack **to)
{
	if (!from || !to)
		return ;
	list_insert((t_list**)to, list_shift((t_list**)from));
}
