/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:32:58 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/25 10:12:11 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

t_uint	memory_length(void **array)
{
	t_uint	len;

	len = 0;
	if (array)
	{
		while (array[len])
			len++;
	}
	return (len);
}
