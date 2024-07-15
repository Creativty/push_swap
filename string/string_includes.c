/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_includes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:18:18 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/12 10:05:45 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	string_includes(const char *str, char rune)
{
	return (string_index_of(str, rune) >= 0);
}

int	string_includes_not(const char *str, const char *charset)
{
	int	i;
	int	j;
	int	is_ok;

	if (str && charset)
	{
		i = 0;
		while (str[i])
		{
			j = 0;
			is_ok = 0;
			while (charset[j])
			{
				if (charset[j++] == str[i])
				{
					is_ok = 1;
					break ;
				}
			}
			if (!is_ok)
				return (1);
			i++;
		}
	}
	return (0);
}
