; boot.asm - 512 bytes, bootsector
BITS 16
ORG 0x7c00

start:
    ; zet video mode (kleur textmode 3)
    mov ah, 0x0
    mov al, 0x03
    int 0x10

    ; achtergrond blauw, tekst wit (kleur 1F)
    mov ax, 0x1F00
    mov es, ax

    ; schrijf tekst "Hello OS!" op schermpositie 0 (boven links)
    mov si, hello_msg
    mov di, 0

.print_char:
    lodsb               ; haal byte uit SI in AL
    cmp al, 0
    je .hang            ; einde string?
    mov [es:di*2], al   ; schrijf char in video geheugen
    mov byte [es:di*2+1], 0x1F ; attribuut (kleur)
    inc di
    jmp .print_char

.hang:
    cli
    hlt
    jmp .hang

hello_msg db "Hello OS!", 0

; vult rest van bootsector met 0 tot 510 bytes
times 510-($-$$) db 0

; laatste 2 bytes: bootsector magic number
dw 0xAA55
