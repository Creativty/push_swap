/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:14:11 by abderrahim        #+#    #+#             */
/*   Updated: 2024/07/23 13:07:14 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "../writef/writef.h"
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

static void	write_bytes(char *buff, uint count) {
	#define COL 8
	for (uint i = 0; i < (count / COL); i++) {
		for (uint j = 0; j < COL; j++) {
			if (i * count + j >= count)
				break ;
			if (buff[i * count + j] == '\n')
				writef("<\\n>");
			else if (buff[i * count + j] == '\0')
				writef("<\\0>");
			else
				writef("%c", buff[i * count + j]);
			writef(" ");
		}
		writef("\n");
	}
}

static void	input_line_buffer_cleanup(char buffer[BUFF_CAP])
{
	int	index;

	index = string_index_of_safe(buffer, BUFF_CAP, '\n');
	write_bytes(buffer, BUFF_CAP);
	if (index == -1 || index == BUFF_CAP - 1)
		memory_zero(buffer, BUFF_CAP);
	else
	{
		memory_move(&buffer[index + 1], BUFF_CAP - index, buffer);
		memory_zero(&buffer[BUFF_CAP - index], index + 1);
	}
	write_bytes(buffer, BUFF_CAP);
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
		if (count == 0 && string_length_safe(buffer, BUFF_CAP) == 0)
			return (line);
		join_len = input_line_join_length(buffer, count);
		temp = string_join(line, 0, buffer, join_len);
		line = (free(line), temp);
		if (string_includes(line, '\n'))
			return (writef("[input_readline]: string_includes(\"line\", '\\n') => %s", line), line);
	}
	return (line);
}
