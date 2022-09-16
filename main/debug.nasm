global debug
section .text

extern printf

print_i_nl:
    sub rsp, 8

    mov rsi, rdi
    mov rdi, format_i_nl
    call printf

    add rsp, 8
    ret

print_c_nl:
    sub rsp, 8

    mov rsi, rdi
    mov rdi, format_c_nl
    call printf

    add rsp, 8
    ret

    
section .data
format_i_nl: db `%i\n`, 0
format_c_nl: db `%c\n`, 0