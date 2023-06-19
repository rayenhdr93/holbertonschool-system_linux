BITS 64

global asm_strcmp
section .text

asm_strcmp:
    push rbp
    mov rbp, rsp

loop:
    mov al, byte [rdi]   ; Move a byte from [rdi] to AL register
    mov dl, byte [rsi]   ; Move a byte from [rsi] to DL register
    cmp al, dl           ; Compare the bytes in AL and DL
    jne check            ; If they are not equal, jump to the check section
    test al, al          ; Check if AL is zero (null terminator)
    jz equal             ; If it's zero, the strings are equal
    inc rdi              ; Increment rdi
    inc rsi              ; Increment rsi
    jmp loop             ; Continue looping

check:
    cmp al, dl           ; Compare the bytes in AL and DL
    jl less              ; If AL is less than DL, jump to less
    jmp greater          ; Otherwise, jump to greater

equal:
    xor eax, eax         ; Set RAX to 0 (indicating equal)
    jmp exit

less:
    mov eax, -1          ; Set RAX to -1 (indicating less)
    jmp exit

greater:
    mov eax, 1           ; Set RAX to 1 (indicating greater)
    jmp exit

exit:
    mov rsp, rbp
    pop rbp
    ret
