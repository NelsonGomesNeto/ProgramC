addi $s0, $zero, -2 # int a = ...
addi $s1, $zero, -3 # int b = ...
addi $s2, $zero, 0 # x = 0

slt $t0, $s0, $zero # t0 = (a < 0)
bne $t0, $zero, ELIF # if (!t0) ELIF
	slt $t1, $s0, $s1 # t1 = (a < b)
	beq $t1, $zero, ELIF # if (!t1) ELIF
		addi $s2, $zero, 1 # x = 1
		j ENDIF # goto ENDIF
ELIF:
	beq $t0, $zero, ELSE # if (t0) ELSE
		slt $t1, $s1, $s0 # t1 = (b < a)
		beq $t1, $zero, ELSE # if (!t1) ELSE
			addi $s2, $zero, 2 # x = 2
			j ENDIF # goto ENDIF
ELSE:
	addi $s2, $zero, 3 # x = 3
ENDIF:
nop