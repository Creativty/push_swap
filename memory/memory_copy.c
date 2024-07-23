/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:24:02 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 17:25:06 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	memory_copy(void *src, uint count, void *dst)
{
	uint	i;

	if (dst && src)
	{
		i = 0;
		while (i < count)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
}
