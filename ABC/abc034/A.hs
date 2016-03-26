f :: (Ord a) => a -> a -> String
f a b = if a < b then "Better" else "Worse"

main :: IO ()
main = do
    [a, b] <- fmap (map (read :: String -> Int) . words) getLine
    putStrLn $ f a b