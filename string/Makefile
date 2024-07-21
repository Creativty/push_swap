# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 18:24:13 by abderrahim        #+#    #+#              #
#    Updated: 2024/07/21 11:34:21 by abderrahim       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR		:=	ar
ARFLAGS	:=	rcs

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

RM		:=	rm -rf

NAME	:=	libstring.a
OBJECTS	:=	string_copy.o string_duplicate.o string_includes.o \
			string_length.o string_index_of.o string_substring.o \
			string_equals.o string_split.o

all: $(NAME)

sanitize: CFLAGS=-Wall -Wextra -Werror -g -fsanitize=address
sanitize: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re sanitize

.SECONDARY: $(OBJECTS)
