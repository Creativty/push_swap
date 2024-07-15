/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:01:15 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/07 19:01:22 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "writef.h"

int	writefv(const char *format, va_list args)
{
	return (writefdv(1, format, args));
}

int	writefd(int fd, const char *format, ...)
{
	int		retval;
	va_list	args;

	va_start(args, format);
	retval = writefdv(fd, format, args);
	va_end(args);
	return (retval);
}

int	writef(const char *format, ...)
{
	int		retval;
	va_list	args;

	va_start(args, format);
	retval = writefdv(1, format, args);
	va_end(args);
	return (retval);
}
