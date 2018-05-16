from turtle import *
import time
from math import acos
import sys

global size, sx, sy, pi
sx, sy, size, sc = -200, 200, 40, 0.4
dx, dy = [0, 1, 0, -1], [-1, 0, 1, 0]
moved = [-1] * 10000
pi = acos(-1)
waitTime = 0.3
colormode(255)
speed(0)
delay(0)
tracer(0, 0)

def printMaze(maze):
    for i in range(len(maze)):
        print(*maze[i])

def drawRectangle(j, i):
    j = j * size + sx
    i = -i * size + sy
    penup()
    setposition(j, i)
    pendown()
    begin_fill()
    for k in range(4):
        forward(size)
        right(90)
    end_fill()

def drawSR(j, i):
    j = j * size + sx
    i = -i * size + sy
    miau = (size - (size * sc)) / 2
    penup()
    setposition(j + miau, i - miau)
    pendown()
    begin_fill()
    for k in range(4):
        forward(size * sc)
        right(90)
    end_fill()

def drawPlayer(px, py):
    color((0, 0, 255))
    drawSR(px, py)

def drawBorders(y, x):
    color((0, 0, 0))
    for i in range(y):
        for j in range(x):
            jj = j * size + sx
            ii = -i * size + sy
            penup()
            setposition(jj, ii)
            pendown()
            for k in range(4):
                forward(size)
                right(90)

def drawTreasureCount(tc):
    penup()
    setposition(sx - 50, sy + 25)
    pendown()
    write("TreasureCount: %d" % tc, move=False, font=("Arial", 20, "normal"))
    update()

def setColor(c):
    if (c == '#'):
        color((0, 0, 0))
    elif (c == '.'):
        color((255, 255, 255))
    elif (c == 'b'):
        color((122, 63, 1))
    elif (c == 'p'):
        color((171, 186, 185))
    elif (c == 'o'):
        color((250, 159, 7))
    elif (c == 'd'):
        color((11, 235, 228))
    else:
        color((219, 1, 255))

def drawArrow(j, i, c):
    jj = j * size + sx
    ii = -i * size + sy
    penup()
    setposition(jj + size / 3, ii - 8 * (size / 9))
    pendown()
    write(maze[i][j], move=False, font=("Arial", 20, "bold"))

def drawMaze(y, x, py, px):
    clear()
    for i in range(y):
        for j in range(x):
            if (maze[i][j] == '#'): color((0, 0, 0))
            else: color((255, 255, 255))
            drawRectangle(j, i)
            setColor(maze[i][j])
            if (maze[i][j] != '#'):
                if (invalid(maze[i][j])):
                    drawArrow(j, i, maze[i][j])
                else:
                    drawSR(j, i)
    drawPlayer(px, py)
    drawBorders(y, x)
    update()

def drawMoved(y, x, movements):
    for i in range(movements):
        penup()
        setposition(sx + x * size + 20, sy - i * 20)
        pendown()
        write(getMoveTitle(moved[i][0]) + ": %d" % (moved[i][1]), move=False, font=("Arial", 12, "normal"))
    update()

def getMoveTitle(m):
    if (m == 0): return("Up")
    if (m == 1): return("Right")
    if (m == 2): return("Down")
    return("Left")

def getMove(m):
    if (m == 0): return("^")
    if (m == 1): return(">")
    if (m == 2): return("v")
    return("<")

def score(c):
    if (c == 'b'): return(1)
    if (c == 'p'): return(5)
    if (c == 'o'): return(10)
    if (c == 'd'): return(50)
    return(0)

def invalid(c):
    return(c == '#' or c == '>' or c == '<' or c == '^' or c == 'v')

def go(y, x, i, j, n, movements):
    #input()
    time.sleep(waitTime)
    drawMaze(y, x, i, j)
    drawTreasureCount(n)
    drawMoved(y, x, movements)
    time.sleep(waitTime)
    if (i < 0 or j < 0 or i >= y or j >= x or invalid(maze[i][j])):
        return(0)
    aux = maze[i][j]
    now, d = score(maze[i][j]), 0
    for k in range(4):
        moved[movements] = [k, n + now]
        maze[i][j] = getMove(k)
        d = max(d, go(y, x, i + dy[k], j + dx[k], n + score(aux), movements + 1))
    maze[i][j] = aux
    return(now + d)

arguments = sys.argv
f = open("./realMaze/%d.in" % (int(arguments[1])), "r")
y, x = map(int, f.readline().split())
maze = []
for i in range(y):
    k = list(f.readline())
    maze += [k[:x]]
backUp = maze.copy()
printMaze(maze)
while (True):
    ans = go(y, x, 0, 0, 0, 0)
    clear()
    drawTreasureCount(ans)
    time.sleep(5)
    maze = backUp.copy()


    # for k in range(360):
    #     forward(2*pi*(0.7 * size / 2) / 360)
    #     right(1)