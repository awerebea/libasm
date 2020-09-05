	global _ft_strcmp
	section	.text
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
