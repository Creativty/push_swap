/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ulong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:30:18 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 12:30:22 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	write_ulong(int fd, unsigned long n)
{
	if (n < 10)
		return (write(fd, &("0123456789"[n]), 1));
	else
		return (write_ulong(fd, n / 10) + write_ulong(fd, n % 10));
}
