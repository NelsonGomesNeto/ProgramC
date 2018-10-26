# Main
	addi $a0, $zero, 4   # a = a0 = 2
	addi $a1, $zero, 10  # b = a1 = 5
	jal sumRange         # call sumRange(a, b)
	add $s0, $zero, $v0  # s0 = v0
j END

# Functions
sumRange:
	addi $sp, $sp, -12 # preparing stack
	sw $ra, 8($sp)     # saving return address
	sw $a1, 4($sp)     # saving b
	sw $a0, 0($sp)     # saving a

	bne $a0, $a1, continue # if (a != b) goto continue
		add $v0, $zero, $a0    # v0 = a
		addi $sp, $sp, 12      # pop stack
		jr $ra                 # return(a)
	continue:
	slt $t0, $a1, $a0      # t0 = (b < a)
	beq $t0, $zero, valid  # if (!t0) goto valid
		addi $v1, $zero, 1     # v1 = 1
		jr $ra                 # return (INVALID)
	valid:
	addi $a0, $a0, 1       # a += 1
	jal sumRange           # recursive call sumRange(a + 1, b)
	lw $a0, 0($sp)         # load prev a
	lw $a1, 4($sp)         # load prev b
	lw $ra, 8($sp)         # load prev return address
	addi $sp, $sp, 12      # pop stack
	add $v0, $v0, $a0      # v0 += a
	jr $ra                 # return(v0)

END:
nop
