/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:20:03 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 14:19:08 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	string_index_of(const char *hay, char needle)
{
	return (string_index_of_safe(hay, string_length(hay), needle));
}

int	string_index_of_safe(const char *hay, int length, char needle)
{
	int	i;

	if (hay && needle)
	{
		i = 0;
		while (hay[i] && i < length)
		{
			if (hay[i] == needle)
				return (i);
			i++;
		}
	}
	return (-1);
}
