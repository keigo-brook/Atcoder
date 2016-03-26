count :: String -> Char -> Int
count s c = length $ filter (== c) s

f :: String -> [Int]
f s = foldr (\x acc -> count s x : acc) [] (take 6 ['A'..])

main :: IO ()
main = do
    s <- getLine
    putStrLn $ unwords $ map show $ f s