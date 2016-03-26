import Data.List

f :: [String] -> Int -> Int
f s t = if t == 1 then f1 s else f2 s

d s l (x, y) = case s of
    'L' -> (x - l, y)
    'R' -> (x + l, y)
    'U' -> (x, y + l)
    'D' -> (x, y - l)

q acc l = if fst acc > 0 then (fst acc + l, snd acc) else (fst acc - l, snd acc)

count acc x = if head x == '?' 
    then q acc (length x)
    else d (head x) (length x) acc

q' acc l
    | l == 0 = acc
    | otherwise = 
        if fst acc > 0 
        then q' (fst acc - 1, snd acc) (l-1)
        else 
            if fst acc < 0 
            then q' (fst acc + 1, snd acc) (l-1)
            else 
                if snd acc > 0
                then q' (fst acc, snd acc - 1) (l-1)
                else q' (fst acc, snd acc + 1) (l-1)



count' acc x = if head x == '?'
               then q' acc (length x)
               else d (head x) (length x) acc

f1 s = let p = foldl count (0, 0) s in abs (fst p) + abs (snd p)
f2 s = let p = foldl count' (0, 0) s in abs (fst p) + abs (snd p)


main :: IO ()
main = do
    s <- getLine
    t <- fmap read getLine
    print $ f (group (sortBy (flip compare) s)) t