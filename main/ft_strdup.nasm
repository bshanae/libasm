global _ft_strdup
section .text

extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
			cmp rdi, 0
			je error_exit

			push rdi

			; compute string size

			call _ft_strlen

			; allocate memory with desired size

			mov rdi, rax
			inc rdi
			call _malloc

			; check for null

			cmp rax, 0
			je error_exit

			; copy characters
			; rax - destination
			; rdx - source
			; r8 - temporary character

			pop rdx

			mov rdi, rax
			mov rsi, rdx
			call _ft_strcpy

			ret
error_exit:
			xor rax, rax
			ret
            