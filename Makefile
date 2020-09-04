# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awerebea <awerebea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 21:56:47 by awerebea          #+#    #+#              #
#    Updated: 2020/09/04 23:08:17 by awerebea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
AC			= nasm
DBGFLAGS	= -g
SRCDIR		= srcs/
OBJDIR		= objs/
SRCS		=	ft_strlen \
				ft_strcpy \
				ft_strcmp
OBJS		= $(addprefix $(OBJDIR), $(SRCS:=.o))

TEST		= tester
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
TEST_SRCS	= main
TEST_OBJS	= $(TEST_SRCS:=.o)
TEST_DFLS	= $(TEST_SRCS:=.d)

#-- configuring MLX library path and 'key-define' header files depending on OS
OS				= $(shell uname)
ifeq ($(OS), Linux)
	AFLAGS		= -f elf64
else
	AFLAGS		= -f macho64
endif

override FLAGS ?= $(AFLAGS)

all:			$(NAME)

$(NAME):		$(OBJS)
	ar rc		$(NAME) $?
	ranlib		$(NAME)

$(OBJS):		$(OBJDIR)%.o: $(SRCDIR)%.s
	mkdir -p	$(OBJDIR)
	$(AC)		$(FLAGS) $< -o $@

$(TEST):		$(NAME) $(TEST_OBJS)
	$(CC)		$(CFLAGS) -L. -lasm $(TEST_OBJS) -o $(TEST)

$(TEST_OBJS):	./%.o: ./%.c
	$(CC)		$(CFLAGS) -c $< -o $@ -MD

test:			$(TEST)
	./$(TEST)

debug:
	make FLAGS="$(AFLAGS) $(DBGFLAGS)" all

include $(wildcard $(TEST_DFLS))

clean:
	rm -rf		$(OBJDIR) $(TEST_OBJS) $(TEST_DFLS)

fclean:			clean
	rm -f		$(NAME) $(TEST)

re:				fclean all

.PHONY: all clean debug fclean re test
