# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awerebea <awerebea@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/03 12:32:13 by awerebea          #+#    #+#              #
#    Updated: 2020/09/05 12:24:38 by awerebea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global ft_strcpy

ft_strcpy:
	xor		rcx, rcx
	mov		rax, rdi
.loop:
	mov		dl, byte[rsi + rcx]
	mov		byte[rdi + rcx], dl
	test	dl, dl;
	jz		.end
	inc		rcx
	jmp		.loop
.end:
	ret
