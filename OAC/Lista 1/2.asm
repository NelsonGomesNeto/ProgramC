#$s0 = a
#$s1 = b
#$s2 = x
addi $s0, $zero, -2
addi $s1, $zero, 1
addi $s2, $zero, 0
sgt $t0, $s0, -1
slt $t1, $s0, $s1
beq $t0, 1, AGT0
beq $t0, 0, ALT0

AGT0:
beq $t1, 1, FST
j THR

ALT0:
beqz $t1, SCD
j THR

FST:
addi $s2, $s2, 1
j END

SCD:
addi $s2, $s2, 2
j END

THR:
addi, $s2, $s2, 3
j END

END:
nop