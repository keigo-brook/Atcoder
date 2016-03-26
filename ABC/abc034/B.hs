f a = if a `mod` 2 == 0 then a - 1 else a + 1

main :: IO ()
main = do
    a <- fmap (read :: String -> Int) getLine
    print (f a)