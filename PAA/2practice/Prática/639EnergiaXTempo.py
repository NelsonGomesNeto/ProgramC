import sys
sys.setrecursionlimit(2**20)
DEBUG = 0

def solve(dp, program, etSwitch, level, i, end):
    if (i == end):
        return(0)

    if (dp[i][level] == -1):
        best = solve(dp, program, etSwitch, level, i + 1, end) + program[i][level]
        for j in range(len(program[i])):
            if (j != level):
                best = min(best, solve(dp, program, etSwitch, j, i + 1, end) + program[i][j] + etSwitch)
        dp[i][level] = best

    return(dp[i][level])

while (True):
    levels, programs, energySwitch, timeSwitch = map(int, input().split())
    if (levels == 0 and programs == 0 and energySwitch == 0 and timeSwitch == 0):
        break
    etSwitch = energySwitch * timeSwitch
    program = [[] for i in range(programs)]
    for i in range(programs):
        for j in range(levels):
            line = list(map(int, input().split()))
            program[i] += [line[0] * line[1]]
    if (DEBUG):
        print("program", program)

    dp = [[-1] * levels for i in range(programs)]
    answer = solve(dp, program, etSwitch, 0, 0, len(program))

    print(answer)