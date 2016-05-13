import Control.Monad

stot :: [String] -> (Int, Int)
stot [s1, s2] = (read s1 :: Int, read s2 :: Int)

replace :: String -> Int -> Int -> String
replace s l r = let s1 = splitAt r s
                    s2 = splitAt (l-1) (fst s1)
                in fst s2 ++ reverse (snd s2) ++ snd s1

f :: String -> Int -> [(Int, Int)] -> String
f s n xs = foldl (\ s x -> uncurry (replace s) x) s xs

main :: IO ()
main = do
    s <- getLine
    n <- fmap read getLine
    lr <- replicateM n $ fmap (stot . words) getLine
    putStrLn $ f s n lr