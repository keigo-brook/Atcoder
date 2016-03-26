f a b = let h = if a >= 12 then a - 12 else a
            l = 30.0 * h + (b / 2.0) 
            s = 6.0 * b
            ls = abs(l - s)
        in if ls > 180 then 360 - ls else ls

main :: IO ()
main = do
    -- [n, m] <- fmap (\s -> map read $ words s :: [Double]) getLine
    [a, b] <- fmap (map (read :: String -> Double) . words) getLine
    print $ f a b