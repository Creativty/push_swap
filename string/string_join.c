/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:01:17 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 17:41:49 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stdlib.h>

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*string_join(const char *lhs, int lcount, const char *rhs, int rcount)
{
	char	*str;

	if (lcount == 0)
		lcount = string_length(lhs);
	else
		lcount = min(lcount, string_length(lhs));
	if (rcount == 0)
		rcount = string_length(rhs);
	else
		rcount = min(rcount, string_length(rhs));
	str = malloc(sizeof(char) * (lcount + rcount + 1));
	if (str)
	{
		string_copy(lhs, str, lcount);
		string_copy(rhs, &str[lcount], rcount);
		str[lcount + rcount] = '\0';
	}
	return (str);
}
