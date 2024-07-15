/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:16:55 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/07 18:41:40 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

int	write_int(int fd, int n)
{
	if (n == INT_MIN)
		return (write(fd, "-2147483648", 11));
	else if (n < 0)
		return (write(fd, "-", 1) + write_int(fd, -n));
	else if (n < 10)
		return (write(fd, &("0123456789"[n]), 1));
	else
		return (write_int(fd, n / 10) + write_int(fd, n % 10));
}

int	write_long(int fd, long n)
{
	if (n == LONG_MIN)
		return (write(fd, "-9223372036854775808", 20));
	else if (n < 0)
		return (write(fd, "-", 1) + write_long(fd, -n));
	else if (n < 10)
		return (write(fd, &("0123456789"[n]), 1));
	else
		return (write_long(fd, n / 10) + write_long(fd, n % 10));
}

int	write_uint(int fd, unsigned int n)
{
	if (n < 10)
		return (write(fd, &("0123456789"[n]), 1));
	else
		return (write_uint(fd, n / 10) + write_uint(fd, n % 10));
}

int	write_uint_hex_up(int fd, unsigned int n)
{
	if (n < 16)
		return (write(fd, &("0123456789ABCDEF"[n]), 1));
	else
		return (write_uint_hex_up(fd, n / 16) + write_uint_hex_up(fd, n % 16));
}

int	write_uint_hex_low(int fd, unsigned int n)
{
	if (n < 16)
		return (write(fd, &("0123456789abcdef"[n]), 1));
	else
		return (write_uint_hex_low(fd, n / 16) + write_uint_hex_low(fd, n % 16));
}

int	write_ulong(int fd, unsigned long n)
{
	if (n < 10)
		return (write(fd, &("0123456789"[n]), 1));
	else
		return (write_ulong(fd, n / 10) + write_ulong(fd, n % 10));
}

int	write_ulong_hex_up(int fd, unsigned long n)
{
	if (n < 16)
		return (write(fd, &("0123456789ABCDEF"[n]), 1));
	else
		return (write_ulong_hex_up(fd, n / 16) + write_ulong_hex_up(fd, n % 16));
}

int	write_ulong_hex_low(int fd, unsigned long n)
{
	if (n < 16)
		return (write(fd, &("0123456789abcdef"[n]), 1));
	else
		return (write_ulong_hex_low(fd, n / 16) + write_ulong_hex_low(fd, n % 16));
}

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

int	write_rune(int fd, unsigned char rune)
{
	return (write(fd, &rune, 1));
}

int	write_rune_repeat(int fd, unsigned char rune, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (write_rune(fd, rune) < 0)
			break ;
		i++;
	}
	return (i);
}
