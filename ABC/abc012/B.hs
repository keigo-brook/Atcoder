show02d :: Int -> String
show02d n = if n < 10 then "0" ++ show n else show n

f :: Int -> String
f n = let s = n `mod` 60
          m = n `div` 60 `mod` 60
          h = n `div` 60 `div` 60
      in  show02d h ++ ":" ++ show02d m ++ ":" ++ show02d s

main :: IO ()
main = do
    n <- fmap read getLine
    putStrLn $ f n