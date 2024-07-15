# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 15:09:42 by abderrahim        #+#    #+#              #
#    Updated: 2024/07/12 19:46:28 by abderrahim       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR		:=	ar
ARFLAGS	:=	rcs

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

RM		:=	rm -rf

NAME	:=	liblist.a
OBJECTS	:=	list_append.o list_at.o list_free.o list_insert.o list_new.o \
			list_pop.o list_shift.o list_size.o list_tail.o

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
