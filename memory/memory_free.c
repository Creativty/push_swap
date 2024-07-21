/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:26:14 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 11:27:22 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	memory_free_list_members(void **array, int count, int free_self)
{
	int	i;

	i = 0;
	while (i < count)
		free(array[i++]);
	if (free_self)
		free(array);
}
