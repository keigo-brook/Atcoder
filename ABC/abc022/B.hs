import Data.List
import Control.Monad

f :: [Int] -> Int
f a = sum $ map ((+(-1)) . length) $ group . sort $ a

main :: IO ()
main = do
    n <- fmap read getLine
    a <- replicateM n $ fmap read getLine
    print $ f a