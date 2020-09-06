	global _ft_read
	extern ___error
	section .text
_ft_read:
	mov rax, 0x0000000002000003
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
