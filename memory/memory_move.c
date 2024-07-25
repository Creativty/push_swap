/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:19:03 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/25 09:10:29 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	memory_move(void *src, t_uint count, void *dst)
{
	t_uint	i;

	if (!dst && !src)
		return ;
	i = 1;
	if (dst >= src)
	{
		while (i <= count)
		{
			((char *)dst)[count - i] = ((char *)src)[count - i];
			i++;
		}
	}
	else
		memory_copy(src, count, dst);
}
