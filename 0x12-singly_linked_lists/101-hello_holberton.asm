section .data
    msg db 'Hello, Holberton', 10, 0  ; 10 is newline character, 0 is null terminator

section .bss

section .text
    global _start
    extern printf

_start:
    ; Prepare the arguments for printf
    mov rdi, fmt        ; fmt is the format string
    mov rsi, msg        ; msg is the message to print
    call printf         ; Call printf function

    ; Exit the program
    mov eax, 60         ; syscall number for exit
    xor edi, edi        ; status code 0
    syscall             ; call kernel

section .data
    fmt db '%s', 0      ; format string for printf

