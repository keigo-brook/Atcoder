f :: [Int] -> Int
f a = let a1 = filter (/= 0) a
      in  ceiling $ (fromIntegral (sum a1) :: Double) / (fromIntegral (length a1) :: Double)

main :: IO ()
main = do
    n <- getLine
    a <- fmap (map read . words) getLine
    print $ f a