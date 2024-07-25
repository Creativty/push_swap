/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:29:27 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/25 09:24:47 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITEF_H
# define WRITEF_H

# include <stdarg.h>

typedef enum e_format_modifiers
{
	FORMAT_MODIFIER_PREPEND = 1 << 0,
	FORMAT_MODIFIER_SIGNED = 1 << 1,
	FORMAT_MODIFIER_ALIGNED = 1 << 2,
	FORMAT_MODIFIER_ALT_FORM = 1 << 3,
	FORMAT_MODIFIER_PAD_ZERO = 1 << 4,
	FORMAT_MODIFIER_PRECISION = 1 << 5,
}	t_format_modifiers;

typedef struct s_format
{
	int					field_width;
	int					precision;
	t_format_modifiers	modifiers;
	unsigned char		specifier;
}	t_format;

int			write_rune_repeat(int fd, unsigned char rune, int count);
int			write_ulong_hex_low(int fd, unsigned long n);
int			write_ulong_hex_up(int fd, unsigned long n);
int			write_uint_hex_low(int fd, unsigned int n);
int			write_uint_hex_up(int fd, unsigned int n);
int			write_cstring(int fd, const char *str);
int			write_string(int fd, const char *str, int len);
int			write_rune(int fd, unsigned char rune);
int			write_ulong(int fd, unsigned long n);
int			write_uint(int fd, unsigned int n);
int			write_long(int fd, long n);
int			write_int(int fd, int n);

int			writef_int(int fd, t_format fmt, int n);
int			writef_pointer(int fd, t_format fmt, void *ptr);
int			writef_rune(int fd, t_format fmt, char rune);
int			writef_uint(int fd, t_format fmt, unsigned int n);
int			writef_hex_low(int fd, t_format fmt, unsigned int n);
int			writef_hex_up(int fd, t_format fmt, unsigned int n);
int			writef_cstring(int fd, t_format fmt, const char *str);
int			writef_cstring(int fd, t_format fmt, const char *str);

int			writef(const char *format, ...);
int			writefd(int fd, const char *format, ...);
int			writefv(const char *format, va_list args);
int			writefdv(int fd, const char *format, va_list args);

t_format	format_make(void);
void		format_modifier_parse(t_format *format, char rune);
int			format_atoi(const char *format, int *offset);

#endif
