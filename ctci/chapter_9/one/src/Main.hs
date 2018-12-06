{-# LANGUAGE UnicodeSyntax #-}
-- | A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
-- | Implement a method to count how many possible ways the child can run up the stairs.

module Main where

  import qualified Control.Monad.State.Strict as ST
  import qualified Data.Map.Strict            as M

  set :: Int -> State (M.Map Int Int) ()
  set n = state (\ st -> ((), M.insert n n st))

  get :: Int -> State (M.Map Int Int) (Maybe Int)
  get k = state (\ st -> (M.lookup k st, st))

  count ∷ Int → Int
  count n
    | n == 1 = 1
    | n == 2 = 2
    | n == 3 = 3
    | n <= 0 = 0
    | otherwise = count (n - 1) + count (n - 2) + count (n - 3)

  main ∷ IO ()
  main = print (count 10)
