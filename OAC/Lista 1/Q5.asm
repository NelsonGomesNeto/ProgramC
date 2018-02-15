.data
a: .word 117
b: .word 343

.text
lw $s0, a # a = s0 = ...
lw $s1, b # b = s1 = ...

add $a0, $zero, $s0  # a0 = a
add $a1, $zero, $s1  # a1 = b
jal prepAbs          # call prepAbs (a0, a1 = abs(a0), abs(a1))
jal multiply         # call multiply
add $s2, $zero, $v0  # s2 = a * b

slt $t0, $s0, $zero  # t0 = (s0 < 0)
slt $t1, $s1, $zero  # t1 = (s1 < 0)
xor $t2, $t0, $t1    # t2 = t0 xor t1
beq $t2, $zero, positive # if (s2 >= 0) goto positive
	sub $s2, $zero, $s2 # s2 = abs(s2)
positive:

j END

prepAbs:
slt $t0, $a0, $zero   # t0 = (a0 < 0)
beq $t0, $zero, a0pos # if (a0 >= 0) goto a0pos
	sub $a0, $zero, $a0 # a0 = abs(a0)
a0pos:
slt $t0, $a1, $zero   # t0 = (a1 < 0)
beq $t0, $zero, a1pos # if (a1 >= 0) goto a1pos
	sub $a1, $zero, $a1 # a1 = abs(a1)
a1pos:
jr $ra                # return

multiply:
addi $sp, $sp, -8    # prepare stack
sw $ra, 4($sp)       # save return address
sw $a1, 0($sp)       # save a1
bne $a1, $zero, cm   # if (a1 != 0) goto cm:
	addi $v0, $zero, 0 # v0 = 0
	addi $sp, $sp, 8   # pop stack
	jr $ra             # return
cm:
sra $a1, $a1, 1      # al /= 2 (a1 = a1 >> 1)
jal multiply         # recursive call multiply
lw $a1, 0($sp)       # load a1
lw $ra, 4($sp)       # load return address
add $v0, $v0, $v0    # v0 += v0
addi $sp, $sp, 8     # pop stack
addi $t1, $zero, 1   # t1 = 1
and $t0, $a1, $t1    # t0 = (a1 and 1)
beq $t0, $zero, even # if (!(a1 and 1)) goto even
	add $v0, $v0, $a0  # v0 += a0
even:
jr $ra               # return

END:
nop