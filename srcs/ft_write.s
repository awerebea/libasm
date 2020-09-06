	global _ft_write
	extern ___error
	section .text
_ft_write:
	mov rax, 0x0000000002000004
	syscall
	jc .error
	ret
.error:
	push rax
	call ___error
	pop rdx
	mov [rax], edx
	mov rax, -1
	ret
