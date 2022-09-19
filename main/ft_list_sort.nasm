global _ft_list_sort
section .text

_ft_list_sort:
			; rdi - head **
			; rsi - comparator

			cmp rdi, 0
			je exit

			; rdi - head *
			mov rdi, qword [rdi]

			; rcx - ceiling node
			; rdx - current node

			mov rcx, 0

sort_pass:
			; if head = ceiling node: return
			cmp rdi, rcx
			je exit

			mov rdx, rdi

sort_step:
			; r10 - next node
			mov r10, [rdx + 8]

			; if next = ceiling: break
			cmp r10, rcx
			je sort_end

			; call comparator

			push rdi
			push rsi
			push rcx
			push rdx
			push r10

			sub rsp, 8

			mov r11, rsi

			mov rdi, qword [rdx]
			mov rsi, qword [r10]
			call r11

			add rsp, 8

			pop r10
			pop rdx
			pop rcx
			pop rsi
			pop rdi

			cmp eax, 0
			jle move_current

			; swap value
			; rax - current value
			; r11 - next value

			mov rax, qword [rdx]
			mov r11, qword [r10]

			mov qword [rdx], r11
			mov qword [r10], rax

move_current:
			mov rdx, qword [rdx + 8]
			jmp sort_step

sort_end:
			mov rcx, rdx
			jmp sort_pass

exit:
			ret
