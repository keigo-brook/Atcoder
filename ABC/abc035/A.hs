f :: Int -> Int -> String
f w h
    | fromIntegral h / fromIntegral w == 0.75 = "4:3"
    | otherwise = "16:9"

main :: IO ()
main = do
    [w, h] <- fmap (map read . words) getLine
    putStrLn $ f w h