/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:28:40 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 12:28:51 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		return (
			write_uint_hex_low(fd, n / 16)
			+ write_uint_hex_low(fd, n % 16)
		);
}
