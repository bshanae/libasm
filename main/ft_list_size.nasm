global ft_list_size
section .text

ft_list_size:
			xor eax, eax

next:
			cmp rdi, 0
			je exit

			inc eax
			mov rdi, qword [rdi + 8]

			jmp next

exit:
			ret