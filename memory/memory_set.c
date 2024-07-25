/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:28:48 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/25 09:11:22 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	memory_set(void	*memory, int size, t_byte rune)
{
	int	i;

	if (!memory || size <= 0)
		return ;
	i = 0;
	while (i < size)
		((char *)memory)[i++] = rune;
}
