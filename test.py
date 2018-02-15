while (True):
    try:
        a = int(input())
    except EOFError as e:
        break


s = "HArdwArE"
j = 0
for i in s:
    print("addi $t0, $zero, %d # t0 = %c" % (ord(i), i))
    print("sb $t0, 0($t1) # s[%d] = t0" % (j))
    print("addi $t1, $t1, 4 # t += 4 (i += 1)")
    j += 1
print("sb $zero, 0($t1) # s[%d] = '\0'" % (j))