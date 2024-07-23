/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:59:31 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/23 13:04:40 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "writef.h"
#include "math.h"
#include "../string/string.h"

t_format	writef_format(const char *format, int *offset)
{
	int			i;
	t_format	fmt;

	i = 1;
	fmt = format_make();
	while (string_includes(" +-#0", format[i]))
		format_modifier_parse(&fmt, format[i++]);
	fmt.field_width = format_atoi(&format[i], &i);
	if (format[i] == '.')
	{
		format_modifier_parse(&fmt, format[i++]);
		fmt.precision = format_atoi(&format[i], &i);
	}
	fmt.specifier = format[i++];
	if (offset)
		*offset += i;
	return (fmt);
}

int	writef_cstring(int fd, t_format fmt, const char *str)
{
	int	bytes;

	bytes = 0;
	if (!(fmt.modifiers & FORMAT_MODIFIER_PRECISION))
		bytes += write_cstring(fd, str);
	else
		bytes += write_string(fd, str, min(fmt.precision, string_length(str)));
	return (bytes);
}

int	writef_pointer(int fd, t_format fmt, void *ptr)
{
	(void)fmt;
	return (write_cstring(fd, "0x") + write_ulong_hex_low(fd, (long)ptr));
}

int	writef_hex_low(int fd, t_format fmt, unsigned int n)
{
	(void)fmt;
	return (write_uint_hex_low(fd, n));
}

int	writef_hex_up(int fd, t_format fmt, unsigned int n)
{
	(void)fmt;
	return (write_uint_hex_up(fd, n));
}

int	writef_uint(int fd, t_format fmt, unsigned int n)
{
	(void)fmt;
	return (write_uint(fd, n));
}

int	writef_int(int fd, t_format fmt, int n)
{
	(void)fmt;
	return (write_int(fd, n));
}

int	writef_rune(int fd, t_format fmt, char rune)
{
	(void)fmt;
	return (write_rune(fd, rune));
}

// static void	write_bytes(char *buff, uint count) {
// 	#define COL 8
// 	for (uint i = 0; i < (count / COL); i++) {
// 		for (uint j = 0; j < COL; j++) {
// 			if (i * count + j >= count)
// 				break ;
// 			if (buff[i * count + j] == '\n')
// 				writef("<\\n>");
// 			else if (buff[i * count + j] == '\0')
// 				writef("<\\0>");
// 			else
// 				writef("%c", buff[i * count + j]);
// 			writef(" ");
// 		}
// 		writef("\n");
// 	}
// }

int	writef_dynamic(int fd, const char *format, int *offset, va_list args)
{
	t_format	fmt;

	fmt = writef_format(format, offset);
	if (fmt.specifier == 'c')
		return (writef_rune(fd, fmt, (char)va_arg(args, int)));
	if (fmt.specifier == 's')
		return (writef_cstring(fd, fmt, va_arg(args, char *)));
	if (fmt.specifier == 'p')
		return (writef_pointer(fd, fmt, va_arg(args, void *)));
	if (fmt.specifier == 'x')
		return (writef_hex_low(fd, fmt, va_arg(args, unsigned int)));
	if (fmt.specifier == 'X')
		return (writef_hex_up(fd, fmt, va_arg(args, unsigned int)));
	if (fmt.specifier == 'u')
		return (writef_uint(fd, fmt, va_arg(args, unsigned int)));
	if (fmt.specifier == 'i' || fmt.specifier == 'd')
		return (writef_int(fd, fmt, va_arg(args, int)));
	return (write_rune(fd, '%'));
}

int	writef_static(int fd, const char *format, int *offset)
{
	int	len;

	len = string_index_of(format, '%');
	if (len == -1)
		len = string_length(format);
	if (offset)
		*offset += len;
	return (write_string(fd, format, len));
}

int	writefdv(int fd, const char *format, va_list args)
{
	int		i;
	int		write_call;
	int		bytes_written;

	i = 0;
	bytes_written = 0;
	while (format[i])
	{
		if (format[i] == '%')
			write_call = writef_dynamic(fd, &format[i], &i, args);
		else
			write_call = writef_static(fd, &format[i], &i);
		if (write_call < 0)
			break ;
		bytes_written += write_call;
	}
	return (bytes_written);
}
