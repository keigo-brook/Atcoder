import Data.List

f :: Int -> Int -> Int -> Int -> [Int] -> String
f n a b k p
    | a `elem` p || b `elem` p = "NO"
    | otherwise = if maximum (map length (group $ sort p)) > 1 then "NO" else "YES"

main :: IO ()
main = do
    n <- fmap read getLine
    [a, b] <- fmap (map read . words) getLine
    k <- fmap read getLine
    p <- fmap (map read . words) getLine
    putStrLn $ f n a b k p