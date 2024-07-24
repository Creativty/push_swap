/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:30:06 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/24 12:30:11 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	write_uint(int fd, unsigned int n)
{
	if (n < 10)
		return (write(fd, &("0123456789"[n]), 1));
	else
		return (write_uint(fd, n / 10) + write_uint(fd, n % 10));
}
