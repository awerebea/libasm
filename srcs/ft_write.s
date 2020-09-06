	extern ___error
	global _ft_write ; ssize_t ft_write(int fd, const void *buf, size_t count);
	section .text
_ft_write:							;	rdi - fd, rsi - buff, rdx - count
	mov rax, 0x0000000002000004		;	code of system 'write' function
	syscall				;	call system write fuction with params rdi, rsi, rdx
	jc .error			;	jump if carry flag is set (an error occurred in 'write')
	ret					;	return (num_of_written_bytes);		rax
.error:
	push rax			;	push rax value to top of stack to save errno value
	call ___error		;	call error function to get "errno address"
	pop rdx				;	retrieve value from top of stack to rdx (errno)
	mov [rax], edx		;	move errno value to errno address
	mov rax, -1			;	rax = -1;
	ret					;	return (-1);		rax
