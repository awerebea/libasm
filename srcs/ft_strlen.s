	global _ft_strlen				;	size_t strlen(char const *str);
	section	.text
_ft_strlen:							;	rdi - str
	xor		rax, rax				;	i = 0;
.loop:
	cmp		byte[rdi + rax], 0;		;	(str[i] == 0) ?
	je		.end					;	je - jump if eqal
	inc		rax						;	i++;
	jmp		.loop					;	jump to start of loop
.end:
	ret								;	return (i);		rax
