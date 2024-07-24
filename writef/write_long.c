/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:28:19 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 12:28:27 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

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
