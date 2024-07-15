/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:02:40 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/11 18:23:36 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writef.h"
#include "../string/string.h"
#include "../memory/memory.h"

t_format	format_make(void)
{
	t_format	format;
	
	memory_zero(&format, sizeof(format));
	return (format);
}

void	format_modifier_parse(t_format *format, char rune)
{
	if (rune == '.')
		format->modifiers |= FORMAT_MODIFIER_PRECISION;
	if (rune == ' ')
		format->modifiers |= FORMAT_MODIFIER_PREPEND;
	if (rune == '+')
		format->modifiers |= FORMAT_MODIFIER_SIGNED;
	if (rune == '-')
		format->modifiers |= FORMAT_MODIFIER_ALIGNED;
	if (rune == '#')
		format->modifiers |= FORMAT_MODIFIER_ALT_FORM;
	if (rune == '0')
		format->modifiers |= FORMAT_MODIFIER_PAD_ZERO;
}

int	format_atoi(const char *format, int *offset)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (string_includes("0123456789", format[i]))
		n = (n * 10) + (format[i++] - '0');
	if (offset)
		*offset += i;
	return (n);
}
