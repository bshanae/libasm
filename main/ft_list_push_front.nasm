global ft_list_push_front
section .text

extern malloc

ft_list_push_front:
			; allocate new node

			push rdi
			push rsi

			mov rdi, 16
			call malloc

			cmp rax, 0
			je error

			pop rsi
			pop rdi

			; configure new node

			mov qword [rax], rsi
			mov qword [rax + 8], 0

			; insert node

			cmp rdi, 0
			je set_begin

			; insert before begin

			mov rcx, qword [rdi]
			mov qword [rax + 8], rcx

set_begin:

			mov qword [rdi], rax
			ret

error:
			mov rax, 0
			ret