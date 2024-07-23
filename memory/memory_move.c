/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:19:03 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 17:23:44 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	memory_move(void *src, uint count, void *dst)
{
	uint	i;

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
