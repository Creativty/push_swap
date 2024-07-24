/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_substring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:20:57 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/24 12:25:41 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stddef.h>
#include <stdlib.h>

char	*string_substring(const char *str, int sub_len)
{
	char	*substr;
	int		str_len;

	if (!str || !sub_len)
		return (NULL);
	str_len = string_length(str);
	if (sub_len > str_len)
		sub_len = str_len;
	substr = malloc((sub_len + 1) * sizeof(char));
	if (substr)
	{
		string_copy(str, substr, sub_len);
		substr[sub_len] = '\0';
	}
	return (substr);
}
