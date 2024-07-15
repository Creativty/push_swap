/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:20:03 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/11 18:20:19 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_index_of(const char *hay, char needle)
{
	int	i;

	i = 0;
	if (hay && needle)
		while (hay[i])
		{
			if (hay[i] == needle)
				return (i);
			i++;
		}
	return (-1);
}
