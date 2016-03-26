import Control.Monad

f :: (Int, Int) -> Int -> [Int] -> Int
f p _ [] = snd p - fst p
f p t (x:xs) = if snd p > x 
               then f (fst p, x + t) t xs
               else snd p - fst p + f (x, x + t) t xs

main :: IO ()
main = do
    [n, t] <- fmap (map read . words) getLine
    a <- replicateM n $ fmap read getLine
    print $ f (head a, head a + t) t (tail a)