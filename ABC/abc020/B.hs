main :: IO ()
main = do
    [a, b] <- fmap words getLine
    print (read (a++b) * 2)