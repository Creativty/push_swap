/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:14:11 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/21 17:52:10 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "../string/string.h"
#include "../memory/memory.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static int	input_line_join_length(char buffer[BUFF_CAP], int count)
{
	int	index;

	index = string_index_of_safe(buffer, count, '\n');
	if (index == -1)
		return (count);
	else
		return (index + 1);
}

static void	input_line_buffer_cleanup(char buffer[BUFF_CAP])
{
	int	index;

	index = string_index_of_safe(buffer, BUFF_CAP, '\n');
	if (index == -1 || index == BUFF_CAP - 1)
		memory_zero(buffer, BUFF_CAP);
	else
	{
		memory_move(&buffer[index + 1], BUFF_CAP - index, buffer);
		memory_zero(&buffer[index + 1], BUFF_CAP - index);
	}
}

char	*input_readline(int fd)
{
	int			count;
	int			join_len;
	char		*line;
	char		*temp;
	static char	buffer[BUFF_CAP];

	line = NULL;
	while (!string_includes(line, '\n'))
	{
		input_line_buffer_cleanup(buffer);
		count = read(fd, buffer, BUFF_CAP);
		if (count == -1)
			return (free(line), NULL);
		if (count == 0)
			return (line);
		join_len = input_line_join_length(buffer, count);
		temp = string_join(line, 0, buffer, join_len);
		line = (free(line), temp);
		if (string_includes(line, '\n'))
			return (line);
	}
	return (line);
}
