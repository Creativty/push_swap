/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:29:28 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 12:29:34 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

int	write_cstring(int fd, const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	return (write(fd, str, len));
}

int	write_string(int fd, const char *str, int len)
{
	if (str == NULL)
	{
		str = "(null)";
		len = 6;
	}
	return (write(fd, str, len));
}
