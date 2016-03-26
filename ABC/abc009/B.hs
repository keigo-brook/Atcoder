import Control.Monad
import Data.List

f :: [Int] -> Int
f x = reverse (nub $ sort x) !! 1

main :: IO ()
main = do
    n <- fmap read getLine
    a <- replicateM n $ fmap read getLine
    print $ f a