global print_c_nl
section .text

extern _printf

print_c_nl:
    mov rsi, rdi
    lea rdi, [rel format_c_nl]
    call _printf

    ret

    
section .data
format_c_nl: db `%c\n`, 0