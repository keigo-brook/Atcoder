import Control.Monad
f :: [String] -> Int
f = foldl (\acc x -> if 'r' `elem` x then acc + 1 else acc) 0

main :: IO ()
main = do
    s <- replicateM 12 getLine
    print $ f s