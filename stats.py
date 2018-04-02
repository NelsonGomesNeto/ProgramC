def rec(end, c0, c1):
    if (end == 8):
        return(0, 0)
    total = [0, 0]

    ret = rec(end + 1, c0 + 1, 0)
    total[0] += ret[0]
    total[1] += ret[1]

    ret = rec(end + 1, 0, c1 + 1)
    total[0] += ret[0]
    total[1] += ret[1]

    return(total[0] + (c0 >= 3 and c1 < 4), total[1] + (c1 >= 4 and c0 < 3))

ans = rec(-1, 0, 0)
print(ans, sum(ans))