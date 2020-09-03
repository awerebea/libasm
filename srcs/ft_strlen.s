# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awerebea <awerebea@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/03 12:32:13 by awerebea          #+#    #+#              #
#    Updated: 2020/09/03 17:12:50 by awerebea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global _ft_strlen

_ft_strlen:
	xor		rax, rax
.loop:
	cmp		byte[rdi + rax], 0;
	je		.end
	inc		rax
	jmp		.loop
.end
	ret
