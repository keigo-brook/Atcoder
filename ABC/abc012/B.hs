f :: Int -> String

main :: IO ()
main = do
    n <- fmap read getLine
    print $ f a