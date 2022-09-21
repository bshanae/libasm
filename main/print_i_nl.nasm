global print_i_nl
section .text

extern _printf

print_i_nl:
    mov rsi, rdi
    lea rdi, [rel format_i_nl]
    call _printf

    ret

    
section .data
format_i_nl: db `%i\n`, 0
