import Data.Char

f :: [String] -> String
f [x, y]
    | toLower (head x) == head y = "Yes"
    | otherwise = "No"
    

main :: IO ()
main = do
    s <- fmap words getLine
    putStrLn $ f s