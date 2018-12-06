{-# LANGUAGE UnicodeSyntax #-}
-- | A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
-- | Implement a method to count how many possible ways the child can run up the stairs.

module Main where

  import qualified Control.Monad.State.Strict as ST
  import qualified Data.Map.Strict            as M
  import Data.Maybe

  set :: Int → ST.State (M.Map Int Int) ()
  set n = ST.state (\ st → ((), M.insert n n st))

  get :: Int → ST.State (M.Map Int Int) (Maybe Int)
  get k = ST.state (\ st → (M.lookup k st, st))

  count :: Int → ST.State (M.Map Int Int) Int
  count n = countWithCache n Nothing
    where
      countWithCache ∷ Int → Maybe Int → ST.State (M.Map Int Int) Int
      countWithCache n c
        | n == 1    = return 1
        | n == 2    = return 2
        | n == 3    = return 3
        | n <= 0    = return 0
        | otherwise = case c of
                        Just x  → return x
                        Nothing → do
                          c1 ← get (n - 1)
                          c2 ← get (n - 2)
                          c3 ← get (n - 3)
                          n1 ← countWithCache (n - 1) c1 
                          n2 ← countWithCache (n - 2) c2
                          n3 ← countWithCache (n - 3) c3
                          return (n1 + n2 + n3)

  main ∷ IO ()
  main = print (fst $ ST.runState (count 10) M.empty)
