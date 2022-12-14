global _ft_strcmp
section .text

_ft_strcmp:
			xor rax, rax
			xor rcx, rcx

			cmp rdi, 0
			je error

			cmp rsi, 0
			je error

compare:
			movzx eax, BYTE [rdi]
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

error:
			ret