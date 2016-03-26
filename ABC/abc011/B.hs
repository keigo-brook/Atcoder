import Data.Char

f :: String -> String
f (x:xs) = toUpper x : map toLower xs
f [] = []

main :: IO ()
main = do
    s <- getLine
    putStrLn $ f s