global _ft_strcpy
section .text

_ft_strcpy:
			; rdi - destination
			; rsi - source
			; return rdi

			push rdi

copy:
			cmp byte [rsi], 0
			je break

			mov al, byte [rsi]
			mov byte [rdi], al

			inc rdi
			inc rsi

			jmp copy
break:
			pop rax
			ret
            