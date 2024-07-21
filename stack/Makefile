# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 15:09:42 by abderrahim        #+#    #+#              #
#    Updated: 2024/07/19 17:20:28 by abderrahim       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR		:=	ar
ARFLAGS	:=	rcs

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

RM		:=	rm -rf

NAME	:=	libstack.a
OBJECTS	:=	stack_new.o stack_spread.o stack_push.o stack_rot.o \
			stack_includes.o stack_is_sorted.o stack_rot_rev.o \
			stack_find.o stack_set_indices.o stack_swap.o stack_at.o

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
