/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:28:48 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/08 15:29:40 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	memory_set(void	*memory, int size, byte rune)
{
	int	i;

	if (!memory || size <= 0)
		return ;
	i = 0;
	while (i < size)
		((char *)memory)[i++] = rune;
}
