def test1(matrix, bl, bc, el, ec):
  for i in range(bl, el+1):
    for j in range(bc, ec+1):
      if(matrix[i][j] == 0):
        return False
  return True

def test0(matrix, bl, bc, el, ec):
  for i in range(bl, el+1):
    for j in range(bc, ec+1):
      if(matrix[i][j] == 1):
        return False
  return True

def bitmap(ma, supl, infl, supc, infc):
  end = ""
  if (supl > infl or supc > infc):
    return end
  if(test1(ma, supl, supc, infl, infc)):
    end += "1"
    return end
  elif(test0(ma, supl, supc, infl, infc)):
    end += "0"
    return end
  else:
    end += "D"
    mL = (supl+infl)//2
    mC = (supc+infc)//2
    end += bitmap(ma,supl, mL, supc, mC)
    end += bitmap(ma,supl, mL, mC+1, infc)
    end += bitmap(ma,mL+1, infl, supc, mC)
    end += bitmap(ma,mL+1, infl, mC+1, infc)
  return end


n = int(input())
for i in range(n):

  l, c = map(int, input().split())
  matrix = [[0 for x in range(c)] for y in range(l)]

  for i in range(l):
    s = input()
    for j in range(len(s)):
      matrix[i][j] = int(s[j])
  result = bitmap(matrix, 0, l-1, 0, c-1)
  #print(result)
  for i in range(len(result)):
    if (i and i%50 == 0):
      print('')
    print(result[i], end ="")
  print('')