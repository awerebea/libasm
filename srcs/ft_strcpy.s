# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awerebea <awerebea@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/03 12:32:13 by awerebea          #+#    #+#              #
#    Updated: 2020/09/03 19:00:28 by awerebea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global _ft_strcpy

_ft_strcpy:
	xor		rcx, rcx
.loop:
	cmp		byte[rsi + rcx], 0;
	je		.end
	mov		[rdi + rcx], byte[rsi + rcx]
	inc		rcx
	jmp		.loop
.end
	mov		[rdi + rcx + 1], 0
	ret

