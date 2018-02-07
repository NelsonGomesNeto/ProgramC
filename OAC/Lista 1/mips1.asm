addi $s0, $zero, 2  # int a = 2;
addi $s1, $zero, 1  # int b = 1;
addi $s2, $zero, 0  # int m = 0;
add $s2, $s2, $s0   # m = a;
slt $t0, $s1, $s2   # t0 = b < m
beqz $t0, ELSE      # if (!t0) goto else
	addi $s2, $s1, 0  # m = b;
	j ENDIF
ELSE:
	addi $s2, $zero, 0 # m = 0;
ENDIF:
nop