	global _ft_strcpy				;	char *ft_strcpy(char * dst, const char * src);
	section	.text
_ft_strcpy:							;	rdi - dst, rsi - src
	xor		rcx, rcx				;	i = 0;
	mov		rax, rdi				;	ret_value = dst;
.loop:
	mov		dl, byte[rsi + rcx]		;	dl = src[i];
	mov		byte[rdi + rcx], dl		;	dst[i] = dl;
	test	dl, dl					;	(dl & dl) ? 0
	jz		.end					;	jump if zero flag is set
	inc		rcx						;	i++;
	jmp		.loop					;	jump to start of loop
.end:
	ret								;	return (ret_value);		rax
