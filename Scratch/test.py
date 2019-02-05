def buildMatrix(count,mString,rowBegin,rowEnd,colunmBegin,colunmEnd):

    if len(mString) == count or rowEnd == rowBegin or colunmEnd == colunmBegin:
        return count

    lengthRow = rowEnd - rowBegin
    lengthColunm = colunmEnd-colunmBegin

    if mString[count] == 'D':

        count+=1
        if count == (mString):
            return count

        if lengthRow == 1:
            newColunmEnd = lengthColunm//2 + colunmBegin + (lengthColunm % 2)
            count = buildMatrix(count,mString,rowBegin,rowEnd,colunmBegin,newColunmEnd) #First quadrant
            count = buildMatrix(count,mString,rowBegin,rowEnd,newColunmEnd,colunmEnd) #Second quadrant
        elif lengthColunm == 1:
            newRowEnd = lengthRow//2 + rowBegin + (lengthRow%2)
            count = buildMatrix(count,mString,rowBegin,newRowEnd,colunmBegin,colunmEnd) # First quadrant
            count = buildMatrix(count,mString,newRowEnd,rowEnd,colunmBegin,colunmEnd) #Third quadrant
        else:
            newRowEnd = lengthRow//2 + rowBegin + (lengthRow%2)
            newColunmEnd = lengthColunm//2 + colunmBegin + (lengthColunm % 2)
            count = buildMatrix(count,mString,rowBegin,newRowEnd,colunmBegin,newColunmEnd) #First quadrant
            count = buildMatrix(count,mString,rowBegin,newRowEnd,newColunmEnd,colunmEnd) #Second quadrant
            count = buildMatrix(count,mString,newRowEnd,rowEnd,colunmBegin,newColunmEnd) #Third quadrant
            count = buildMatrix(count,mString,newRowEnd,rowEnd,newColunmEnd,colunmEnd) #Fourth quadrant
        
        return count

    elif mString[count] == '1':
        for i in range(rowBegin,rowEnd):
            for j in range(colunmBegin,colunmEnd):
                matrix[i][j] = 1
    
    count+=1
    return count


def printM():
    for i in range(nm[0]):
        print(*matrix[i], sep='')


inputs = int(input())
while(inputs > 0):
    nm = list(map(int,input().split()))
    matrix = [[0]*nm[1] for i in range(nm[0])]
    mString = list(input())
    count = buildMatrix(0,mString,rowBegin=0,rowEnd=nm[0],colunmBegin=0,colunmEnd=nm[1])
    printM()
    if inputs != 1:
        print()
    inputs -= 1
