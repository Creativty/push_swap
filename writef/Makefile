# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 15:09:42 by abderrahim        #+#    #+#              #
#    Updated: 2024/07/08 18:19:27 by abderrahim       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR		:=	ar
ARFLAGS	:=	rcs

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

RM		:=	rm -rf

NAME	:=	libwritef.a
OBJECTS	:=	format.o math.o variations.o writef.o writers.o

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJECTS)
