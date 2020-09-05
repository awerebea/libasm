# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awerebea <awerebea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 21:56:47 by awerebea          #+#    #+#              #
#    Updated: 2020/09/05 20:47:56 by awerebea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
AC			= nasm
DBGFLAGS	= -g
OBJDIR		= bin/
SRCDIR		= srcs/
SRCS		=	ft_strlen \
				ft_strcpy \
				ft_strcmp
OBJS		= $(addprefix $(OBJDIR), $(SRCS:=.o))

TEST		= tester
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I includes/
TEST_SRCDIR	= test/
TEST_SRCS	= main
TEST_OBJS	= $(addprefix $(OBJDIR), $(TEST_SRCS:=.o))
TEST_DFLS	= $(addprefix $(OBJDIR), $(TEST_SRCS:=.d))

#-------------------- configuring variables depending on OS --------------------
OS				= $(shell uname)
ifeq ($(OS), Linux)
	AFLAGS		= -f elf64
else
	AFLAGS		= -fmacho64
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
	$(CC)		$(CFLAGS) $(TEST_OBJS) $(INCLUDES) -L. -lasm -o $(TEST)

$(TEST_OBJS):	$(OBJDIR)%.o: $(TEST_SRCDIR)%.c
	mkdir -p	$(OBJDIR)
	$(CC)		$(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD

test:			$(TEST)
	./$(TEST)

test_re: fclean test

debug:
	make FLAGS="$(AFLAGS) $(DBGFLAGS)" all

include $(wildcard $(TEST_DFLS))

clean:
	rm -rf		$(OBJDIR)

fclean:			clean
	rm -f		$(NAME) $(TEST)

re:				fclean all

.PHONY: all clean debug fclean re test test_re
