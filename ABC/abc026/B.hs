import Control.Monad
import Data.List

area :: Int -> Double
area r = fromIntegral (r * r) * pi

f :: [Int] -> Double
f [] = 0
f [x] = area x
f (x:y:xs) = area x - area y + f xs

main :: IO ()
main = do
    n <- fmap (read :: String -> Int) getLine
    r <- replicateM n $ fmap (read :: String -> Int) getLine
    print $ f (sortBy (flip compare) r)