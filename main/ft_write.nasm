global _ft_write

extern ___error

section .text

_ft_write:
			mov rax, 0x2000004
			syscall

			jc error

			ret

error:
			mov	rdi, rax

			call ___error
			mov	[rax], rdi

			mov	rax, -1

			ret		