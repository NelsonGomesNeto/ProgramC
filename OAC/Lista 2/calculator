def clkCycle(m, i):
    clk = 0
    for j in range(4):
        clk += dx[j] * m[i][j + 1]
    return(clk)

def time(m, i):
    clk = clkCycle(m, i)
    return(clk / (m[i][0] * 10**9))

def cpi(m, i):
    clk = clkCycle(m, i)
    return(clk / 10**6)

instructions = 10**6
dx = [0.1*instructions, 0.2*instructions, 0.5*instructions, 0.2*instructions]
m = [[1.5, 1, 2, 3, 4], [2, 2, 2, 2, 2]]
for i in range(2):
    print("Execution time: %lg; CPI: %lg; Cycles: %lf" % (time(m, i), cpi(m, i), clkCycle(m, i)))