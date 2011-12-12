cli
xor ax,ax
mov ss,ax
mov sp,0x7bec
mov bp,sp
mov ds,ax
mov si,0x7c00
mov es,ax
mov di,0x600
mov cx,0x100
cld
rep movsw
jmp 0x0:0x61f
xor al,al
cmp dl,al
jnz 0x27
mov dl,0x80
mov [bp+0x12],dl
mov si,0x790
mov di,0x720
call di
mov si,0x7be
mov cx,0x4
mov ah,0x80
xor al,al
mov bl,[si+0x0]
cmp ah,bl
jz 0x56
cmp al,bl
jnz 0x66
add si,0x10
dec cx
jnz 0x3c
mov si,0x733
mov di,0x6fd
call di
mov di,si
add si,0x10
dec cx
jz 0x6e
mov bl,[si+0x0]
cmp ah,bl
jnz 0x58
mov si,0x74a
mov di,0x6fd
call di
mov ah,0x41
mov bx,0x55aa
mov dl,[bp+0x12]
int 0x13
jc 0xca
cmp bx,0xaa55
jnz 0xca
and cx,0x1
jz 0xca
mov byte [bp+0x0],0x10
mov byte [bp+0x1],0x0
mov byte [bp+0x2],0x1
mov byte [bp+0x3],0x0
mov word [bp+0x4],0x7c00
mov word [bp+0x6],0x0
mov ax,[di+0x8]
mov [bp+0x8],ax
mov ax,[di+0xa]
mov [bp+0xa],ax
mov word [bp+0xc],0x0
mov word [bp+0xe],0x0
mov si,bp
mov ah,0x42
int 0x13
jnc 0xe6
mov si,0x756
mov di,0x6fd
call di
mov dh,[di+0x1]
mov cx,[di+0x2]
mov ax,0x201
mov dl,[bp+0x12]
mov bx,0x7c00
int 0x13
jnc 0xe6
mov si,0x756
mov di,0x6fd
call di
mov bx,0x7c00
mov ax,[bx+0x1fe]
cmp ax,0xaa55
jnz 0xfa
mov si,di
jmp 0x0:0x7c00
mov si,0x760
mov di,0x720
call di
mov si,0x76c
mov di,0x720
call di
xor ax,ax
int 0x16
xor bx,bx
mov es,bx
mov bx,0x472
mov ax,0x1234
mov [es:bx],ax
jmp 0xffff:0x0
pusha
xor bx,bx
lodsb
or al,al
jz 0x131
mov ah,0xe
int 0x10
lodsb
or al,al
jnz 0x128
popa
ret
dec si
outsw
and [bx+di+0x63],ah
jz 0x1a3
jna 0x1a1
and [di+0x6e],ah
jz 0x1b3
jns 0x163
imul bp,[bp+0x20],word 0x424d
push dx
add [bx+di+0x6e],cl
jna 0x1af
insb
imul sp,[si+0x20],word 0x424d
push dx
add [bx+di+0x2f],cl
dec di
and [di+0x72],ah
jc 0x1cd
jc 0x160
dec cx
outsb
jna 0x1c5
insb
imul sp,[si+0x20],word 0x4250
push bx
add [di],cl
or dl,[bx+si+0x72]
gs jnc 0x1e6
and [bx+di+0x6c],ah
insw
outsw
jnc 0x1ee
and [bx+di+0x6e],ah
jns 0x19f
imul sp,[di+0x79],byte +0x20
jz 0x1f4
and [bp+si+0x65],dh
bound bp,[bx+0x6f]
jz 0x1bb
add [cs:di+0x42],cl
push dx
add [cs:bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add byte [bx+di],0x1
add [bx+di],bh
aas
mov di,0x3f07
add [bx+si],al
add cl,al
std
pop ds
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [bx+si],al
add [di-0x56],dl
