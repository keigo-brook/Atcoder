f :: Int -> String -> String -> Int
f n (x:xs) (y:ys) 
    | x == 'b' && y == 'b' = f (n+1) xs ys
    | x == 'c' && y == 'a' = f (n+1) xs ys
    | x == 'a' && y == 'c' = f (n+1) xs ys
    | otherwise = -1
f n [] [x] = if x == 'b' then n else -1
f _ _ _ = -1

main :: IO ()
main = do
    n <- fmap read getLine
    s <- getLine
    if n `mod` 2 == 0 then putStrLn "-1"
    else
        let half = n `div` 2
        in print $ f 0 (take half s) (reverse $ drop half s)
