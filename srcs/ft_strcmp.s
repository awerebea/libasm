# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awerebea <awerebea@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 14:43:44 by awerebea          #+#    #+#              #
#    Updated: 2020/09/04 17:48:40 by awerebea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global _ft_strcmp

_ft_strcmp:
	xor		rax, rax
	xor		rcx, rcx
.loop:
	mov		al, byte[rdi]
	mov		cl, byte[rsi]
	cmp		al, cl
	je		.increment
	jmp		.end
.increment:
	test	al, al
	jz		.end
	inc		rdi
	inc		rsi
	jmp		.loop
.end:
	sub		rax, rcx
	ret
