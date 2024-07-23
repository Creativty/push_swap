/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:20:32 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/23 13:03:53 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_length(const char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int	string_length_safe(const char *str, int capacity)
{
	int	i;

	i = 0;
	if (str)
		while (i < capacity && str[i])
			i++;
	return (i);
}
