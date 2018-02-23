# Main
addi $s0, $zero, -2 # a = ...
addi $s1, $zero, -3 # b = ...
addi $s2, $zero, 0  # x = 0

slt $t0, $s0, $zero    # t0 = (a < 0)
bne $t0, $zero, elif   # if (a >= 0) goto elif
	slt $t1, $s0, $s1    # t1 = (a < b)
	beq $t1, $zero, elif # if (a >= b) goto elif
		addi $s2, $zero, 1 # x = 1
		j endif            # goto endif
elif:
	beq $t0, $zero, else   # if (a >= 0) goto else
		slt $t1, $s1, $s0    # t1 = (b < a)
		beq $t1, $zero, else # if (b >= a) else
			addi $s2, $zero, 2 # x = 2
			j endif            # goto endif
else:
	addi $s2, $zero, 3 # x = 3
endif:
nop
