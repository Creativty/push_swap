# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 17:25:50 by abderrahim        #+#    #+#              #
#    Updated: 2024/07/22 16:47:58 by abderrahim       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR			:=	ar rcs

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror

RM			:=	rm -rf

NAME		:=	libinput.a
OBJS		:=	input_readline.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJS)
