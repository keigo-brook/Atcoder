import Data.Bits

checkBits :: Int -> Int -> Bool
checkBits x n = shiftR x n .&. 1 == 1

f :: Int -> Int -> [Int] -> [Int]
f _ _ [] = []
f n x (a:as) = (if checkBits x n then a else 0) : f (n + 1) x as


main :: IO ()
main = do
    [n, x] <- fmap (map read . words) getLine
    a <- fmap (map read . words) getLine
    print $ sum $ f 0 x a