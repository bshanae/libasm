global _ft_strcpy
section .text

_ft_strcpy:
			; rdi - destination
			; rsi - source
			; return rdi

			cmp rdi, 0
			je error

			cmp rsi, 0
			je error

			push rdi

copy:
			mov al, byte [rsi]
			mov byte [rdi], al

			cmp byte [rsi], 0
			je break

			inc rdi
			inc rsi

			jmp copy
break:
			pop rax
			ret

error:
			xor rax, rax
			ret