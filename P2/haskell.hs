import Data.Array
import Data.List

--Gerador de Array
a tam = array (0,tam) [(i, i) | i <- [0..tam]] --Array
b tam = [0..tam] --Lista

myMap :: (Int -> Int) -> [Int] -> [Int]
myMap f [] = []
myMap f (a:as) = [f a] ++ myMap f as

square :: Int -> Int
square a = a * a


soma :: [Int] -> Int
soma [] = 0
soma (a : as) = a + soma as


mult :: [Int] -> Int
mult [] = 1
mult (a : as) = a * mult as


fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci(n - 1) + fibonacci(n - 2)


findTam :: [Int] -> Int
findTam [] = 0
findTam (a : as) = 1 + findTam as


pot :: Int -> Int -> Int
pot _ 0 = 1
pot 0 _ = 0
pot x y = x * pot x (y - 1)


binToDecimal :: [Int] -> Int
binToDecimal [] = 0
binToDecimal (a:as) = a * pot 2 (findTam as) + binToDecimal as


binSearch :: Array Int Int -> Int -> Int -> Int -> Int
binSearch array begin end target
  | begin > end = -1
  | target > array!middle = binSearch array (middle + 1) end target
  | target < array!middle = binSearch array begin (middle - 1) target
  | otherwise = middle
  where middle = (begin + end) `div` 2


seqSearch :: [Int] -> Int -> Int
seqSearch [] x = -1
seqSearch (a:as) x =
    if (x == a) then
    1
    else
    if ((seqSearch as x) > 0) then
    1 + seqSearch as x
    else
    -1

--Array, tamanho e target
linSearch :: [Int] -> Int -> Int -> Int
linSearch [] tam target = - tam - 1
linSearch (a:as) tam target =
    if (target == a) then
    0
    else
    1 + linSearch as tam target


findMenor :: [Int] -> Int
findMenor [x] = x
findMenor (a:as) =
    if (a < findMenor as) then
    a
    else
    findMenor as

achaMenor :: [Int] -> Int -> Int
achaMenor [] menor = menor
achaMenor (a:as) menor =
    if (a < menor) then
    achaMenor as a
    else
    achaMenor as menor

selectionSort :: [Int] -> [Int]
selectionSort [] = []
selectionSort (a:as) = [theMenor] ++ selectionSort (delete theMenor (a:as))
  where theMenor = achaMenor (a:as) a
  --where theMenor = minimum(a:as) --Seria findMenor(a:as)


merge :: [Int] -> [Int] -> [Int]
merge arrayA [] = arrayA
merge [] arrayB = arrayB
merge (a:as) (b:bs) =
    if (a <= b) then
    [a] ++ (merge as (b:bs))
    else
    [b] ++ (merge (a:as) bs)

comeco :: [Int] -> [Int]
comeco x = take (length x `div` 2) x

fim :: [Int] -> [Int]
fim x = drop (length x `div` 2) x

mergeSort :: [Int] -> [Int]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort x = merge (mergeSort(comeco x)) (mergeSort(fim x))


quickSort :: [Int] -> [Int]
quickSort [] = []
quickSort (a:as) = quickSort [x | x <- as, x < a]
                   ++ [a] ++
                   quickSort [x | x <- as, x >= a]


inserir :: Int -> [Int] -> [Int]
inserir x [] = [x]
inserir x (a:as) =
    if (x < a) then
    [x] ++ (a:as)
    else
    [a] ++ inserir x as

insertionSort :: [Int] -> [Int]
insertionSort [] = []
insertionSort (a:as) = inserir a (insertionSort as) --devia ser inserir
