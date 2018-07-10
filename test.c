function shellSort(size is int, arr is array[] of int) {
  h is int
  h = size / 3
  repeat while (h > 0) {
    i is int
    repeat (i = h to (size - 1)) {
      temp, j is int
      temp = arr[i]
      repeat while (j >= h && arr[j - h] > temp) {
        arr[j] = a[j - h]
        j = j - h
      }
      arr[j] = temp
    }
    h /= 2
  }
}

@isEntryPoint
function main() {
  i, size is int
  size = lineIn() as int
  arr is array[size] of int
  line is array[size] of string
  line = split(lineIn(), ' ')
  repeat (i = 0 to size - 1) {
    arr[i] = line[i] as int
  }
  shellSort(size, arr)
}