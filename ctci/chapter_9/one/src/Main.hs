{-# LANGUAGE UnicodeSyntax #-}
-- | A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
-- | Implement a method to count how many possible ways the child can run up the stairs.

module Main where

  count ∷ Int → Int
  count n
    | n == 0    = 0
    | n == 1    = 1
    | n == 2    = 2
    | n == 3    = 3
    | n < 0     = 0
    | otherwise = count (n - 1) + count (n - 2) + count (n - 3)

  main ∷ IO ()
  main = print (count 10)
