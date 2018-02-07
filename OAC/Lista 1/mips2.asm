addi $s0, $zero, -1       # int a = ...;
addi $s1, $zero, -1       # int b = ...;
addi $s2, $zero, 0       # int x = 0;

addi $t0, $zero, -1      # t0 = -1
sgt $t1, $s0, $t0        # t1 = (a > -1)
beqz $t1, ELIF           # if (a <= -1) goto ELIF
	slt $t2, $s0, $s1      # t2 = (a < b)
	beqz $t2, ELIF         # if (a >= b) goto ELIF
		addi $s2, $zero, 1   # x = 1
j ENDIF
ELIF:
	slt $t1, $s0, $zero
	beqz $t1, ELSE         # if (a > -1) goto ELSE111
		sgt $t2, $s0, $s1    # t2 = (a > b)
		beqz $t2, ELSE       # if (b >= a) goto ELSE
			addi $s2, $zero, 2 # x = 2
	j ENDIF
ELSE:
	addi $s2, $zero, 3     # x = 3
ENDIF: