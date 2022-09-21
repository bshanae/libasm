global _ft_strdup
section .text

extern _malloc
extern _ft_strlen

_ft_strdup:
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
			push rax

copy_next_char:
			mov r8b, byte [rdx]
			mov byte [rax], r8b
			inc rdx
			inc rax

			cmp byte [rdx], 0
			jne copy_next_char

			pop rax
			ret

error_exit:
			xor rax, rax
			ret
            