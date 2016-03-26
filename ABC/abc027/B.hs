g :: Int -> [Int] -> Int
g _ [] = -1
g n [x] = if x == 0 then n else -1
g n (x:y:xs) = if x == 0 then g n (y:xs) else g (n+1) (x+y:xs)

f :: Int -> [Int] -> Int
f n a = let ave = sum a `div` n
            newa = map (ave -) a
        in  g 0 newa

main :: IO ()
main = do
    n <- fmap (read :: String -> Int) getLine
    a <- fmap (map (read :: String -> Int) . words) getLine
    print $ f n a