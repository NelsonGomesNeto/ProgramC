import Data.Array

soma :: [Int] -> Int
soma [] = 0
soma (a : as) = a + soma as
