global _ft_atoi_base
section .text


_ft_atoi_base:
			; rdi : string (char ptr)
			; esi : base (int)

			; check if string is null
			cmp rdi, 0
			je ft_atoi_base_error

			; check base is at least 2
			cmp esi, 2
			jl ft_atoi_base_error

			; check base is not greater than 16
			cmp esi, 16
			ja ft_atoi_base_error

process_whitespaces:
			; al : current character
			mov al, byte [rdi]

			cmp al, 0
			je ft_atoi_base_error

			cmp al, `\t`
			je pass_whitespace

			cmp al, `\r`
			je pass_whitespace

			cmp al, `\n`
			je pass_whitespace

			cmp al, `\v`
			je pass_whitespace

			cmp al, ' '
			je pass_whitespace

			jmp finish_whitespaces_processing

pass_whitespace:
			inc rdi
			jmp process_whitespaces

finish_whitespaces_processing:
process_sign:
			; al : current character
			; ecx : sign, +1 or -1
			mov ecx, +1

process_next_sign:
			mov al, byte [rdi]

			cmp al, 0
			je ft_atoi_base_error

			cmp al, '+'
			je pass_plus

			cmp al, '-'
			je pass_minus

			jmp finish_signs_processing

pass_plus:
			inc rdi
			mov ecx, +1
			jmp process_next_sign

pass_minus:
			inc rdi
			mov ecx, -1
			jmp process_next_sign

finish_signs_processing:
process_digits:
			; edx : result number (long)

			mov r8, [rel lookup]
			mov edx, 0

process_one_digit:
			; al : character

			xor eax, eax
			mov al, byte [rdi]

			cmp al, 0
			je finish_digits_processing

			; character is not ascii
			cmp al, 127
			ja ft_atoi_base_error

			; lookup digit
			mov al, byte [r8 + rax]

			; character is not a valid digit
			cmp al, -1
			je ft_atoi_base_error

			imul edx, esi
			add edx, eax

			inc rdi

			jmp process_one_digit

finish_digits_processing:
			imul edx, ecx

ft_atoi_base_ok:
			mov eax, edx
			ret

ft_atoi_base_error:
			mov rax, 0
			ret


section .data
lookup:    
			db -1 ; 0 ?
			db -1 ; 1 ?
			db -1 ; 2 ?
			db -1 ; 3 ?
			db -1 ; 4 ?
			db -1 ; 5 ?
			db -1 ; 6 ?
			db -1 ; 7 ?
			db -1 ; 8 ?
			db -1 ; 9 ?
			db -1 ; 10 ?
			db -1 ; 11 ?
			db -1 ; 12 ?
			db -1 ; 13 ?
			db -1 ; 14 ?
			db -1 ; 15 ?
			db -1 ; 16 ?
			db -1 ; 17 ?
			db -1 ; 18 ?
			db -1 ; 19 ?
			db -1 ; 20 ?
			db -1 ; 21 ?
			db -1 ; 22 ?
			db -1 ; 23 ?
			db -1 ; 24 ?
			db -1 ; 25 ?
			db -1 ; 26 ?
			db -1 ; 27 ?
			db -1 ; 28 ?
			db -1 ; 29 ?
			db -1 ; 30 ?
			db -1 ; 31 ?
			db -1 ; 32 ?
			db -1 ; 33 ?
			db -1 ; 34 ?
			db -1 ; 35 ?
			db -1 ; 36 ?
			db -1 ; 37 ?
			db -1 ; 38 ?
			db -1 ; 39 ?
			db -1 ; 40 ?
			db -1 ; 41 ?
			db -1 ; 42 ?
			db -1 ; 43 ?
			db -1 ; 44 ?
			db -1 ; 45 ?
			db -1 ; 46 ?
			db -1 ; 47 ?
			db 0 ; 48 0
			db 1 ; 49 1
			db 2 ; 50 2
			db 3 ; 51 3
			db 4 ; 52 4
			db 5 ; 53 5
			db 6 ; 54 6
			db 7 ; 55 7
			db 8 ; 56 8
			db 9 ; 57 9
			db -1 ; 58 ?
			db -1 ; 59 ?
			db -1 ; 60 ?
			db -1 ; 61 ?
			db -1 ; 62 ?
			db -1 ; 63 ?
			db -1 ; 64 ?
			db 10 ; 65 A
			db 11 ; 66 B
			db 12 ; 67 C
			db 13 ; 68 D
			db 14 ; 69 E
			db 15 ; 70 F
			db -1 ; 71 G
			db -1 ; 72 H
			db -1 ; 73 I
			db -1 ; 74 J
			db -1 ; 75 K
			db -1 ; 76 L
			db -1 ; 77 M
			db -1 ; 78 N
			db -1 ; 79 O
			db -1 ; 80 P
			db -1 ; 81 Q
			db -1 ; 82 R
			db -1 ; 83 S
			db -1 ; 84 T
			db -1 ; 85 U
			db -1 ; 86 V
			db -1 ; 87 W
			db -1 ; 88 X
			db -1 ; 89 Y
			db -1 ; 90 Z
			db -1 ; 91 ?
			db -1 ; 92 ?
			db -1 ; 93 ?
			db -1 ; 94 ?
			db -1 ; 95 ?
			db -1 ; 96 ?
			db 10 ; 97 a
			db 11 ; 98 b
			db 12 ; 99 c
			db 13 ; 100 d
			db 14 ; 101 e
			db 15 ; 102 f
			db -1 ; 103 g
			db -1 ; 104 h
			db -1 ; 105 i
			db -1 ; 106 j
			db -1 ; 107 k
			db -1 ; 108 l
			db -1 ; 109 m
			db -1 ; 110 n
			db -1 ; 111 o
			db -1 ; 112 p
			db -1 ; 113 q
			db -1 ; 114 r
			db -1 ; 115 s
			db -1 ; 116 t
			db -1 ; 117 u
			db -1 ; 118 v
			db -1 ; 119 w
			db -1 ; 120 x
			db -1 ; 121 y
			db -1 ; 122 z
			db -1 ; 123 ?
			db -1 ; 124 ?
			db -1 ; 125 ?
			db -1 ; 126 ?
			db -1 ; 127 ?
