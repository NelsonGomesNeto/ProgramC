merge :: [Int] -> [Int] -> [Int]
merge arrayA [] = arrayA
merge [] arrayB = arrayB
merge (a:as) (b:bs) =
    if (a <= b) then
    a : (merge as (b:bs))
    else
    b : (merge (a:as) bs)

comeco :: [Int] -> [Int]
comeco x = take (length x `div` 2) x

fim :: [Int] -> [Int]
fim x = drop (length x `div` 2) x

mergeSort :: [Int] -> [Int]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort x = merge (mergeSort(comeco x)) (mergeSort(fim x))
