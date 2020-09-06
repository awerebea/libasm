	extern ___error
	global _ft_read		;	size_t read(int fildes, void *buf, size_t nbyte);
	section .text
_ft_read:							;	rdi - fd, rsi - buff, rdx - count
	mov rax, 0x0000000002000003		;	code of system 'read' function
	syscall				;	call system write fuction with params rdi, rsi, rdx
	jc .error			;	jump if carry flag is set (an error occurred in 'read')
	ret					;	return (num_of_written_bytes);		rax
.error:
	push rax			;	push rax value to top of stack to save errno value
	call ___error		;	call error function to get "errno address"
	pop rdx				;	retrieve value from top of stack to rdx (errno)
	mov [rax], edx		;	move errno value to errno address
	mov rax, -1			;	rax = -1;
	ret					;	return (-1);		rax
