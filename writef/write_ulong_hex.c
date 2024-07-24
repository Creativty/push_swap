/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ulong_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:29:08 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 12:29:12 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	write_ulong_hex_up(int fd, unsigned long n)
{
	if (n < 16)
		return (write(fd, &("0123456789ABCDEF"[n]), 1));
	else
		return (
			write_ulong_hex_up(fd, n / 16)
			+ write_ulong_hex_up(fd, n % 16)
		);
}

int	write_ulong_hex_low(int fd, unsigned long n)
{
	if (n < 16)
		return (write(fd, &("0123456789abcdef"[n]), 1));
	else
		return (
			write_ulong_hex_low(fd, n / 16)
			+ write_ulong_hex_low(fd, n % 16)
		);
}
