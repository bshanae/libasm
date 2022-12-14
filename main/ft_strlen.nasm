global _ft_strlen
section .text

_ft_strlen:
            ; rdi - input string ptr
            ; rsi - copy of input string ptr, will increment it until [rsi] == 0

            cmp rdi, 0
            je error

            mov rsi, rdi

cycle:
            cmp byte [rsi], 0
            je end_of_string

            inc rsi
            jmp cycle

end_of_string:
            sub rsi, rdi
            mov rax, rsi
            ret

error:
            xor rax, rax
            ret