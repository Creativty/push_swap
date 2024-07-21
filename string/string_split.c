/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:09:13 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 11:36:03 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "../memory/memory.h"
#include <stddef.h>
#include <stdlib.h>

static char	*string_split_capture(const char *str, char sep)
{
	int	len;

	len = string_index_of(str, sep);
	if (len == -1)
		len = string_length(str);
	return (string_substring(str, len));
}

static int	string_split_count(const char *str, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			j++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (j);
}

static int	string_split_populate(
		const char *str, char sep, char **splits, int size)
{
	int		i;
	int		j;
	char	*split;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		split = string_split_capture(&str[i], sep);
		if (split == NULL)
			return (j);
		splits[j++] = split;
		i += string_length(split);
	}
	return (size);
}

/*
* @param const char *string: string to operate on.
* @param char sep: separator to use as a delimiter for splits.
* @returns in case successful a NULL terminated array of strings, otherwise a NULL pointer.
*/
char	**string_split(const char *str, char sep)
{
	int		size;
	int		count;
	char	**splits;

	size = string_split_count(str, sep);
	splits = malloc(sizeof(char *) * (size + 1));
	if (splits)
	{
		count = string_split_populate(str, sep, splits, size);
		if (count != size)
			return (memory_free_list_members((void **)splits, count, 1), NULL);
		splits[size] = NULL;
	}
	return (splits);
}
