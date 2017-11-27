def countSort(array):
  biggest = max(array)
  count = [0] * (biggest + 1)
  for i in array:
    count[i] += 1
  #array = []
  for i in range(0, biggest + 1):
    for j in range(count[i]):
      print(i)
    #array += [i] * count[i]
  #return(array)

array = list(map(int, input().split()))
array = countSort(array)
#print(array)
#for i in array:
  #print(i)
