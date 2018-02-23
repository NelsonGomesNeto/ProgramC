# Main
	addi $a0, $zero, 7  # n = 7
	jal fib             # fib(7)
	add $s0, $zero, $v0 # s0 = fib(n)
j END

# Functions
fib:
	addi $sp, $sp, -12 # prepare stack
	sw $ra, 8($sp)     # save return address
	sw $a0, 0($sp)     # save n

	addi $t1, $zero, 2       # t1 = 2
	slt $t0, $a0, $t1        # t0 = (a < 2)
	beq $t0, $zero, continue # if (a >= 2) goto continue
		# addi $v0, $zero, 1       # v0 = 1 (IF FIRST FIB == 1)
		add $v0, $zero, $a0      # v0 = a0  (IF FIRST FIB == 0)
		jr $ra                   # return(1)
	continue:
	addi $a0, $a0, -1   # n -= 1
	jal fib             # fib(n - 1)
	addi $sp, $sp, 12   # pop stack
	add $t2, $zero, $v0 # t2 = fib(n - 1)
	sw $t2, 4($sp)      # save return of fib(n - 1)

	lw $a0, 0($sp)    # load prev n
	addi $a0, $a0, -2 # n -= 2
	jal fib           # fib(n - 2)
	addi $sp, $sp, 12 # pop stack
	lw $t2, 4($sp)    # load return of fib(n - 1)
	lw $ra, 8($sp)    # load prev return address
	add $v0, $v0, $t2 # v0 = fib(n - 2) + fib(n - 1)
	jr $ra            # return(fib(n - 1) + fib(n - 2))

END:
nop