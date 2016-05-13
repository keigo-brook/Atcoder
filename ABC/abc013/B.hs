f :: Int -> Int -> Int
f a b = let n = 10 - abs (a - b)
        in  min n (10 - n)

main :: IO ()
main = do
    a <- fmap read getLine
    b <- fmap read getLine
    print $ f a b