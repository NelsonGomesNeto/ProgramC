quickSort :: [Int] -> [Int]
quickSort [] = []
quickSort (a:as) = quickSort [x | x <- as, x < a]
                   ++ [a] ++
                   quickSort [x | x <- as, x >= a]
