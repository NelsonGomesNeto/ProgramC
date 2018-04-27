.data
.word 0, 0, 5, 2, 1, 3, -3, 2

.text
lui $3, 0x1001

lw $1, 0($3) 
lui $2, 1
srl $2, $2, 16 
beq $2, $1, fim
loop: lw $1, 8($3) 
lw $4, 24($3)
beq $1, $4, oper_b
j oper_c
oper_b: lw $4, 16 ($3) 
oper_c: jal swap
add $5, $5, $2 
addi $3, $3, 4 
slti $6, $5, 2
bne $6, $0, loop
fim:	break
swap:	xor $1, $1, $4
xor $1, $1, $4 
xor $4, $1, $4
xor $4, $1, $4 
sw $1, 8($3) 
jr $31
