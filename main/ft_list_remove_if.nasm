global ft_list_remove_if
section .text

extern free

ft_list_remove_if:
			; rdi - node **
			; r10 - node *
			; rsi - data ref
			; rdx - comparator

			; if (node == NULL) return

			cmp rdi, 0
			je exit

process_node:
			; if (*node == NULL) return

			cmp qword [rdi], 0
			je exit

			mov r10, [rdi]

			; cmp((*node)->data, data_ref)

			push rdi
			push rsi
			push rdx

			; rdi <- (**node).data
			mov rdi, [r10]
			call rdx

			pop rdx
			pop rsi
			pop rdi

			; if (cmp(...) != 0) remove node

			cmp rax, 0
			je remove

			; node = &(*node)->next;

			lea rdi, qword [r10 + 8]

			jmp process_node

remove:
			; *node = (*node)->next;

			mov r11, qword [r10 + 8]
			mov [rdi], r11

			jmp process_node

exit:
			ret
