import Data.List

findMenor :: [Int] -> Int
findMenor [x] = x
findMenor (a:as) =
    if (a < findMenor as) then
    a
    else
    findMenor as

selectionSort :: [Int] -> [Int]
selectionSort [] = []
selectionSort (a:as) = [theMenor] ++ selectionSort (delete theMenor (a:as))
  where theMenor = findMenor(a:as)
