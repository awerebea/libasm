	global _ft_strcmp		;	int ft_strcmp(const char *s1, const char *s2);
	section	.text
_ft_strcmp:						;	rdi - s1, rsi - s2
	xor		rax, rax			;	char tmp1 = '\0';	ret_value
	xor		rcx, rcx			;	char tmp2 = '\0';
.loop:
	mov		al, byte[rdi]		;	tmp1 = *s1;
	mov		cl, byte[rsi]		;	tmp2 = *s2;
	cmp		al, cl				;	(tmp1 == tmp2) ?
	je		.increment			;	jump if equal to increment
	jmp		.end				;	jump to end
.increment:
	test	al, al				;	(al & al) ? 0
	jz		.end				;	jump if zero flag is set
	inc		rdi					;	s1++;
	inc		rsi					;	s2++;
	jmp		.loop				;	jump to start of loop
.end:
	sub		rax, rcx			;	ret_value = *s1 - *s2;	rax -= rcx
	ret							;	return (ret_value);		rax
