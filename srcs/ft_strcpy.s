	global _ft_strcpy
	section	.text
_ft_strcpy:
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
