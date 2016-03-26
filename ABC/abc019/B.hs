import Data.List
main :: IO ()
main = do
    s <- getLine
    putStrLn $ concatMap (\x -> head x : show (length x)) (group s)