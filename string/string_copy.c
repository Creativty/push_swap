/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:20:46 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/11 18:20:48 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_copy(const char *src, char *dst, int count)
{
	int	i;

	if (!src || !dst || count <= 0)
		return (0);
	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}
