import           Control.Monad

stot :: [String] -> (String, Int)
stot [s, i] = (s, read i :: Int)

roundNum :: Int -> Int -> (String, Int) -> (String, Int)
roundNum a b n
    | snd n < a = (fst n, a)
    | snd n > b = (fst n, b)
    | otherwise = n

getSum :: Int -> Int -> [(String, Int)] -> Int
getSum a b s = let rounds = map (roundNum a b) s
               in  foldl (\acc x -> if fst x == "East" then acc + snd x else acc - snd x) 0 rounds

showAns :: Int -> String
showAns n
    | n == 0 = "0"
    | n < 0  = "West " ++ show (-n)
    | otherwise = "East " ++ show n

main :: IO ()
main = do
    [n, a, b] <- fmap (map (read :: String -> Int) . words) getLine
    s <- replicateM n $ fmap (stot . words) getLine
    putStrLn $ showAns  $ getSum a b s
