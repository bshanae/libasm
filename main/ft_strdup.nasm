global ft_strdup
section .text

extern malloc
extern ft_strlen

ft_strdup:
			push rdi

			; compute string size

			call ft_strlen

			; allocate memory with desired size

			mov rdi, rax
			call malloc

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
			mov r8, [rdx]
			mov [rax], r8
			inc rdx
			inc rax

			cmp byte [rax], 0
			jne copy_next_char

			pop rax
			ret

error_exit:
			pop rax
			mov rax, 0
			ret
            