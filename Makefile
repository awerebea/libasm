# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awerebea <awerebea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 21:56:47 by awerebea          #+#    #+#              #
#    Updated: 2020/09/06 20:08:19 by awerebea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
AC			= nasm
AFLAGS		= -fmacho64
DBGFLAGS	= -g
OBJDIR		= bin/
SRCDIR		= srcs/
SRCS		=	ft_strlen \
				ft_strcpy \
				ft_strcmp \
				ft_write \
				ft_read \
				ft_strdup
OBJS		= $(addprefix $(OBJDIR), $(SRCS:=.o))

TEST		= tester
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I includes/
TEST_SRCDIR	= test/
TEST_SRCS	= main
TEST_OBJS	= $(addprefix $(OBJDIR), $(TEST_SRCS:=.o))
TEST_DFLS	= $(addprefix $(OBJDIR), $(TEST_SRCS:=.d))

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
	rm -f	*.txt
	./$(TEST)

debug:
	make FLAGS="$(AFLAGS) $(DBGFLAGS)" all

include $(wildcard $(TEST_DFLS))

clean:
	rm -rf		$(OBJDIR)

fclean:			clean
	rm -f		$(NAME) $(TEST) *.txt

re:				fclean all

diff_files:
	@printf "\e[1;34mcat test_write.txt\e[0m"
	@echo
	@cat test_write.txt
	@echo
	@echo
	@printf "\e[1;35mcat test_write_ft.txt\e[0m"
	@echo
	@cat test_write_ft.txt
	@echo
	@echo
	@printf "\e[1;33mdiff test_write.txt test_write_ft.txt\e[0m"
	@echo
	@diff test_write.txt test_write_ft.txt

.PHONY: all clean debug fclean re test test_re diff_files
