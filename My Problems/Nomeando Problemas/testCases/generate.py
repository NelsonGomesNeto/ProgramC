test = int(input())
for i in range(1, test):
    fo = open("%d.in" % (i + 2), "w")
    are = int(input())
    print("1", file=fo)
    print(are, file=fo)
    for i in range(are):
        print(input(), file=fo)
    fo.close()