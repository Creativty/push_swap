/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:29:28 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/25 09:25:16 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "math.h"
#include "writef.h"
#include "../string/string.h"

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

int	writef_cstring(int fd, t_format fmt, const char *str)
{
	int	bytes;

	bytes = 0;
	if (!(fmt.modifiers & FORMAT_MODIFIER_PRECISION))
		bytes += write_cstring(fd, str);
	else
		bytes += write_string(fd, str, min(fmt.precision, string_length(str)));
	return (bytes);
}
