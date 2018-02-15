addi $s0, $zero, 2 # int a = 2
addi $s1, $zero, 1 # int b = 1
addi $s2, $zero, 0 # int m = 0
add $s2, $zero, $s0 # m = a

slt $t0, $s1, $s2 # t0 = (b < m)
beq $t0, $zero, ELSE # if (!t0) goto ELSE
	add $s2, $zero, $s1 # m = b
	j ENDIF
ELSE:
	addi $s2, $zero, 0
ENDIF:
nop