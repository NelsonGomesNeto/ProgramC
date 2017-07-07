import Data.Array

pot :: Int -> Int -> Int
pot _ 0 = 1
pot 0 _ = 0
pot x y = x * pot x (y - 1)
