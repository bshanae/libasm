global ft_strcmp
section .text

ft_strcmp:
			xor rax, rax
			xor rcx, rcx
compare:
			movzx eax, byte [rdi]
			movzx ecx, byte [rsi]

			cmp eax, 0
			jz exit_z
			
			cmp ecx, 0
			jz exit_z

			sub eax, ecx
			jne exit

			inc rdi
			inc rsi

			jmp compare
exit_z:
			sub eax, ecx
exit:
			ret