# s0 = a
# s1 = b
# s2 = m

addi $s4, $zero, 1 # Setting one in register
addi $s0, $zero, 1 # int a = 1
addi $s1, $zero, 2 # int b = 2
addi $s2, $zero, 0 # int m = 0;
add $s2, $s2, $s0  # m = a;
slt $s3, $s1, $s2  # s3 = b < m
beq $s3, $s4, SMA  # if (s3)
beq $s3, $zero, EQB
SMA:
	add $s2, $zero, $s1
	j ENDIF
EQB:
	addi $s2, $zero, 0
  j ENDIF
ENDIF:
addi $s5, $zero, 1707
nop