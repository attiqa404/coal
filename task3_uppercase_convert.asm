.model small
.stack 100h
.data
msg_in DB 'Enter a lowercase character: \$'
msg_out DB 'Uppercase character is: \$'
user_char DB ?
.code
main proc
    mov ax, @data
    mov ds, ax

    mov dx, offset msg_in
    mov ah, 9
    int 21h

    mov ah, 1
    int 21h

    sub al, 32
    mov user_char, al

    mov dx, 10
    mov ah, 2
    int 21h
    mov dx, 13
    mov ah, 2
    int 21h

    mov dx, offset msg_out
    mov ah, 9
    int 21h

    mov dl, user_char
    mov ah, 2
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main
