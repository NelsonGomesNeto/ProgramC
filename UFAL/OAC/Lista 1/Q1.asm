# Main
addi $s0, $zero, 2  # a = 2
addi $s1, $zero, 1  # b = 1
addi $s2, $zero, 0  # m = 0
add $s2, $zero, $s0 # m = a

slt $t0, $s1, $s2     # t0 = (b < m)
beq $t0, $zero, else  # if (b >= m) goto ELSE
	add $s2, $zero, $s1 # m = b
	j endif
else:
	addi $s2, $zero, 0
endif:
nop
