f :: String -> String
f [] = "YES"
f [x]
    | x /= 'o' && x /= 'k' && x /= 'u' = "NO"
    | otherwise = "YES"
f (x:y:xs) = case x of
    'o' -> f (y:xs)
    'k' -> f (y:xs)
    'u' -> f (y:xs)
    'c' -> if y == 'h' then f xs else "NO"
    _   -> "NO"

main :: IO ()
main = do
    x <- getLine
    putStrLn $ f x