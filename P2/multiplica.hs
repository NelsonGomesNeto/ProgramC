import Data.Array

mult :: [Int] -> Int
mult [] = 1
mult (a : as) = a * mult as
