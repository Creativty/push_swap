/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:26:14 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 13:17:26 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	memory_free_count(void **array, int count, int self)
{
	int	i;

	if (array)
	{
		i = 0;
		while (i < count)
			free(array[i++]);
		if (self)
			free(array);
	}
}

void	memory_free_cstyle(void **array, int self)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
			free(array[i++]);
		if (self)
			free(array);
	}
}
