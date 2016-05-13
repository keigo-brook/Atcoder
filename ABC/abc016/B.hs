f :: Int -> Int -> Int -> String
f a b c
    | a + b == c && a - b == c = "?"
    | a - b == c = "-"
    | a + b == c = "+"
    | otherwise = "!"

main :: IO ()
main = do
    [a, b, c] <- fmap (map read .  words) getLine
    putStrLn $ f a b c