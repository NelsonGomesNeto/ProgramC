import Data.Array

findTam :: [Int] -> Int
findTam [] = 0
findTam (a : as) = 1 + findTam as
