global _ft_write
section .text

_ft_write:
			mov rax, 1
			syscall
			ret