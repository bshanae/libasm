global _ft_list_remove_if
section .text

extern _free

_ft_list_remove_if:
			; rdi - node **
			; r10 - node *
			; rsi - data ref
			; rdx - comparator

			; if (node == NULL) return

			cmp rdi, 0
			je exit

process_node:
			; if (*node == NULL) return

			mov r10, [rdi]

			cmp r10, 0
			je exit

			; cmp((*node)->data, data_ref)

			push rdi
			push r10
			push rsi
			push rdx

			sub rsp, 8

			; rdi <- (**node).data
			mov rdi, [r10]
			call rdx

			add rsp, 8

			pop rdx
			pop rsi
			pop r10
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
