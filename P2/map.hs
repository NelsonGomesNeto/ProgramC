import Data.Array

myMap :: (Int -> Int) -> [Int] -> [Int]
myMap f [] = []
myMap f (a:as) = [f a] ++ myMap f as

square :: Int -> Int
square a = a * a

exe :: [Int]
exe myMap square [1,2,3,4,5]
