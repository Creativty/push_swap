/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_rune.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:29:44 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/25 09:17:00 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "writef.h"

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

int	writef_rune(int fd, t_format fmt, char rune)
{
	(void)fmt;
	return (write_rune(fd, rune));
}