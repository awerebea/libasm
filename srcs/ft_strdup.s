	extern _malloc
	extern ___error
	extern _ft_strlen
	extern _ft_strcpy
	global _ft_strdup		;	char *ft_strdup(const char *s1);
	section .text
_ft_strdup:				;	rdi - s1
	push rdi			;	backup rdi (s1) at top of stack before call ft_strlen
	call _ft_strlen		;	call ft_strlen(s1) (first parameter from rdi)
	mov rdi, rax		;	int len = ft_strlen(s1); (result of ft_strlen was placed in rax)
	inc rdi				;	len++;
	call _malloc		;	call malloc(len) (first parametr from rdi);
	jc .error			;	jump if carry flag is set (an error occurred in 'malloc')
	pop rsi				;	retrieve s1 from top of stack and move to rsi (src)
	mov rdi, rax		;	char *dst = malloc(len); (result of malloc was placed in rax)
	call _ft_strcpy		;	call ft_strcpy (dst from rdi, src from rsi)
	ret					;	return (dst); (result of ft_strcpy was placed in rax)
.error:
	push rax			;	push rax value to top of stack to save errno value
	call ___error		;	call error function to get "errno address"
	pop rdx				;	retrieve value from top of stack to rdx (errno)
	mov [rax], edx		;	move errno value to errno address
	mov rax, -1			;	rax = -1;
	ret					;	return (-1);		rax
