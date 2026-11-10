.model small
.stack 100h
.data
prompt DB 'Enter a character: \$'
msg1 DB 'The user entered \$'
msg2 DB ' character.\$'
user_char DB ?
.code
main proc
    mov ax, @data
    mov ds, ax

    mov dx, offset prompt
    mov ah, 9
    int 21h

    mov ah, 1
    int 21h
    mov user_char, al

    mov dx, 10
    mov ah, 2
    int 21h
    mov dx, 13
    mov ah, 2
    int 21h

    mov dx, offset msg1
    mov ah, 9
    int 21h

    mov dl, user_char
    mov ah, 2
    int 21h

    mov dx, offset msg2
    mov ah, 9
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main
