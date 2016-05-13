f :: Int -> [Int] -> Int
f _ [] = 0
f n (x:xs) = f n xs + if x `mod` 3 == 0 
                      then if x `mod` 2 == 0
                           then 3
                           else 0
                      else if x `mod` 3 == 1
                           then if x `mod` 2 == 0
                                then 1
                                else 0
                      else if x `mod` 2 == 0
                           then 1
                           else 2

main :: IO ()
main = do
    n <- fmap read getLine
    a <- fmap (map read . words) getLine
    print $ f n a