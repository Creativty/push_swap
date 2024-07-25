# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 18:06:45 by abderrahim        #+#    #+#              #
#    Updated: 2024/07/25 09:13:24 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror

RM			:=	rm -rf

NAME		:=	push_swap
NAME_BONUS	:=	checker
OBJS		:=	push_swap.o state_sorters.o quicksort.o quicksort_a2b_three.o \
				quicksort_b2a_three.o quicksort_place.o quicksort_rewind.o \
				quicksort_two.o
OBJS_BONUS	:=	checker.o input/libinput.a
SHARED_OBJS	:=	writef/libwritef.a state.o state_action.o state_utility.o \
				state_argv.o string/libstring.a \
				stack/libstack.a stack/list/liblist.a memory/libmemory.a

all: $(NAME)

debug: CFLAGS = -Wall -Wextra -Werror -g
debug: $(NAME)

bonus: $(NAME_BONUS)

sanitize_deps:
	$(MAKE) -C memory sanitize
	$(MAKE) -C stack/list sanitize
	$(MAKE) -C stack sanitize
	$(MAKE) -C string sanitize
	$(MAKE) -C writef sanitize
	$(MAKE) -C input sanitize

sanitize: sanitize_deps
	$(CC) $(CFLAGS) -g -fsanitize=address -c $(OBJS:.o=.c) -o $(OBJS)
	$(CC) $(CFLAGS) -g -fsanitize=address $(OBJS) $(SHARED_OBJS) -o $(NAME)

input/libinput.a:
	$(MAKE) -C input CFLAGS="$(CFLAGS)"

string/libstring.a:
	$(MAKE) -C string CFLAGS="$(CFLAGS)"

stack/libstack.a:
	$(MAKE) -C stack CFLAGS="$(CFLAGS)"

stack/list/liblist.a:
	$(MAKE) -C stack/list CFLAGS="$(CFLAGS)"

memory/libmemory.a:
	$(MAKE) -C memory CFLAGS="$(CFLAGS)"

writef/libwritef.a:
	$(MAKE) -C writef CFLAGS="$(CFLAGS)"

$(NAME): $(SHARED_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SHARED_OBJS) -o $(NAME)

$(NAME_BONUS):	$(SHARED_OBJS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(SHARED_OBJS) -o $(NAME_BONUS)

clean:
	$(MAKE) -C memory clean
	$(MAKE) -C stack/list clean
	$(MAKE) -C stack clean
	$(MAKE) -C string clean
	$(MAKE) -C writef clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C memory fclean
	$(MAKE) -C stack/list fclean
	$(MAKE) -C stack fclean
	$(MAKE) -C string fclean
	$(MAKE) -C writef fclean
	$(RM) $(NAME) $(NAME_BONUS)

re_deps:
	$(MAKE) -C string re
	$(MAKE) -C stack re
	$(MAKE) -C stack/list re
	$(MAKE) -C memory re
	$(MAKE) -C writef re

re: fclean re_deps all

checker_OS:
	@echo "downloading remote checker from 42cdn..."
	@wget -q -O $@ 'https://cdn.intra.42.fr/document/document/25123/checker_linux'
	@echo "setting executable permissions..."
	@chmod +x $@
	@echo "done, you can now use it via" "$@"

.PHONY: all clean fclean re re_deps

.SECONDARY: $(SHARED_OBJS) $(OBJS) $(OBJS_BONUS)
