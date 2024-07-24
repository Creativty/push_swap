/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:27:54 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 12:28:08 by aindjare         ###   ########.fr       */
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
