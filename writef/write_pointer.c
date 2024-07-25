/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:15:51 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/25 09:15:55 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writef.h"

int	writef_pointer(int fd, t_format fmt, void *ptr)
{
	(void)fmt;
	return (write_cstring(fd, "0x") + write_ulong_hex_low(fd, (long)ptr));
}
