shakerSort :: Ord a => [a] -> [a]
shakerSort s = if isSorted s then s else shakerSort (shake s)

shake :: Ord a => [a] -> [a]
shake [] = []
shake [x] = [x]
shake (x:y:xs)
    | x > y = y : shake (x:xs)
    | otherwise = x : shake (y:xs)

isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x:y:xs) = (x <= y) && isSorted(y:xs)

main :: IO ()
main = print $ shakerSort [41, 51, 31, 11, 21, 91]
