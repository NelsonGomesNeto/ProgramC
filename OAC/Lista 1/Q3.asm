.data
string: .space 100
revString: .space 100

# Main
.text
addi $a1, $zero, 100 # prepare to read size 100 string
jal readString       # call read string
la $s0, ($a0)        # s0 = pointer to normal string

la $a0, ($s0)        # a0 = pointer to normal string
jal verifyString     # call verify string
add $v1, $zero, $v0  # v1 = v0
bne $v0, $zero, END  # if (v0) goto end (has invalid characters)

la $a0, ($s0)        # a0 = pointer to normal string
addi $a1, $zero, 0   # a1 = 0
jal stringLength     # call string length
add $s1, $zero, $v0  # s1 = string length

la $s2, revString    # s2 = pointer to reversed string

la $a0, ($s2)       # a0 = pointer to reversed string
la $a1, ($s0)       # a1 = pointer to normal string
add $a1, $a1, $s1   # a1 = a1 + string length
addi $a1, $a1, -1   # a1 = pointer to end of string
add $a2, $zero, $s1 # a2 = string length
jal reverseString   # call reverse string

la $a0, ($s2)       # a0 = pointer to reversed string
jal invertString    # call invert string

la $a0, ($s0)       # a0 = pointer to normal string
jal printString     # print normal string
la $a0, ($s2)       # a0 = pointer to reversed string
jal printString     # print reversed string

j END # End of Main

# Functions
readString:
addi $v0, $zero, 8 # prepares syscall to read a string
la $a0, string     # a0 = pointer to normal string
syscall            # read string
jr $ra             # return

printString:
addi $v0, $zero, 4 # prepare syscall to print a string
syscall            # print string
jr $ra             # return

verifyString:          
addi $sp, $sp, -4      # prepare stack
sw $ra, 0($sp)         # save return address
addi $t0, $zero, 10    # t0 = '\n'
lb $t1, ($a0)          # t1 = string[0]
bne $t0, $t1, cVerifyString # if (string[0] != '\n') goto cVerifyString
	addi $sp, $sp, 4     # pop stack
	addi $v0, $zero, 0   # v0 = 0
	jr $ra               # return
cVerifyString:
jal verifyChar         # call verifyChar
beq $v0, $zero, cVerifyChar # if (!v0) goto cVerifyChar
	lw $ra, 0($sp)       # load return address
	addi $sp, $sp, 4     # pop stack
	jr $ra               # return
cVerifyChar:
addi $a0, $a0, 1       # string ++ (moving pointer)
jal verifyString       # recursive call verifyString
lw $ra, 0($sp)         # load return address
addi $sp, $sp, 4       # pop stack
jr $ra                 # return

verifyChar:
addi $t0, $zero, 64  # t0 = 'A' - 1
addi $t1, $zero, 91  # t1 = 'Z' + 1
addi $t2, $zero, 96  # t2 = 'a' - 1
addi $t3, $zero, 123 # t3 = 'z' + 1
lb $t4, ($a0)        # t4 = string[0]
slt $t5, $t0, $t4    # t5 = ('A' - 1) < string[0]
slt $t6, $t4, $t1    # t6 = string[0] < ('Z' + 1)
slt $t7, $t2, $t4    # t7 = ('a' - 1) < string[0]
slt $t8, $t4, $t3    # t8 = string[0] < ('z' + 1)
bne $t5, $zero, vc1  # if (string[0] > ('A' - 1)) goto vc1
	addi $v0, $zero, 1 # v0 = 1 (invalid character)
	jr $ra             # return
vc1:
bne $t8, $zero, vc2  # if (string[0] < ('z' + 1)) goto vc2
	addi $v0, $zero, 1 # v0 = 1 (invalid character)
	jr $ra             # return
vc2:
beq $t6, $zero, vc3  # if (string[0] >= ('Z' + 1) goto vc3
	addi $v0, $zero, 0 # v0 = 0 (valid character)
	jr $ra             # return
vc3:
beq $t7, $zero, vc4  # if (string[0] > ('A' - 1)) goto vc4
	addi $v0, $zero, 0 # v0 = 0 (valid character)
	jr $ra             # return
vc4:
addi $v0, $zero, 1   # v0 = 1 (valid character)
jr $ra               # return


stringLength:
addi $sp, $sp, -4      # prepare stack
sw $ra, 0($sp)         # save return address
addi $t0, $zero, 10    # t0 = '\n'
lb $t1, ($a0)          # t1 = s[0]
bne $t0, $t1, cStringLength # if (s[0] != '\n') goto continue
	add $v0, $zero, $a1  # v0 = string length
	addi $sp, $sp, 4     # pop stack
	jr $ra               # return
cStringLength:
addi $a1, $a1, 1       # string length ++
addi $a0, $a0, 1       # string ++ (moving pointer)
jal stringLength       # recursive call stringLength
lw $ra, 0($sp)         # load return address
addi $sp, $sp, 4       # pop stack
jr $ra                 # return

reverseString:
addi $sp, $sp, -4      # prepare stack
sw $ra, 0($sp)         # save return address
bne $a2, $zero, cReverseString # if (!(end of string)) goto continue
	addi $sp, $sp, 4     # pop stack
	jr $ra               # return
cReverseString:
lb $t0, 0($a1)         # t0 = normalString[0]
sb $t0, 0($a0)         # reversedString[0] = t0
addi $a0, $a0, 1       # reversedString ++ (moving pointer)
addi $a1, $a1, -1      # normalString -- (moving pointer)
addi $a2, $a2, -1      # stringLength --
jal reverseString      # recursive call reverseString
lw $ra, 0($sp)         # load return address
addi $sp, $sp, 4       # pop stack
jr $ra                 # return

invertString:
addi $sp, $sp -4      # prepare stack
sw $ra, 0($sp)        # save return address
lb $t0, ($a0)         # t0 = string[0]
bne $t0, $zero, cInvertString # if (s[0] != '\0') goto continue
	addi $sp, $sp, 4    # pop stack
	jr $ra              # return
cInvertString:
jal invertChar       # call invert char
addi $a0, $a0, 1     # string ++ (moving pointer)
jal invertString     # recursive call invertString
lw $ra, 0($sp)       # load return address
addi $sp, $sp, 4     # pop stack
jr $ra               # return

invertChar:
addi $t0, $zero, 97  # t0 = 'a'
lb $t1, ($a0)        # t1 = string[0]
slt $t2, $t1, $t0    # t2 = string[0] < 'a'
bne $t2, $zero, toLower # if (string[0] < 'a') goto toLower
	addi $t1, $t1, -32 # t1 -= 32
	sb $t1, ($a0)      # string[0] = t1
	jr $ra             # return
toLower:
addi $t1, $t1, 32    # t1 += 32
sb $t1, ($a0)        # string[0] = t1
jr $ra               # return

END:
nop
