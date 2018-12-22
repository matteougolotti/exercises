-- | https://www.hackerrank.com/challenges/save-the-prisoner/problem

module Main where

  count :: [Int] -> Int
  count (n:m:s:_) = if a == 0 then n
                    else a
                    where a = (m + s - 1) `mod` n
  count _         = 0

  main :: IO ()
  main = interact $ (concat . (fmap ((++"\n") . show)) . (fmap count) . (fmap (\s -> fmap read s)) . (fmap words) . tail . lines)


