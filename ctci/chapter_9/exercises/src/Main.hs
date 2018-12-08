{-# LANGUAGE UnicodeSyntax #-}

module Main where

  import qualified Control.Monad.State.Strict as ST
  import qualified Data.Map.Strict            as M
  import Data.Maybe

  -- | 9.2
  -- | Imagine a robot sitting on the upper left corner of an X by Y grid.
  -- | The robot can only move in two directions, right and down. How many
  -- | paths are there for the robot to go from (0, 0) to (X, Y) ?

  set :: (Int, Int) → Int → ST.State (M.Map (Int, Int) Int) ()
  set k v = ST.state (\ st → ((), M.insert k v st))

  get :: (Int, Int) → ST.State (M.Map (Int, Int) Int) (Maybe Int)
  get k = ST.state (\ st → (M.lookup k st, st))

  countPaths :: Int                                 -- Initial X position
              → Int                                 -- Initial Y position
              → ST.State (M.Map (Int, Int) Int) Int -- Cache with number of paths
  countPaths x y = countPathsWithCache x y Nothing
    where
      countPathsWithCache :: Int                                 -- Current X position
                           → Int                                 -- Current Y position
                           → Maybe Int                           -- Cached solution at current position
                           → ST.State (M.Map (Int, Int) Int) Int -- Cache with number of paths
      countPathsWithCache x y c
        | x < 0 || y < 0   = return 0
        | x == 0 && y == 0 = return 0
        | x == 0 && y == 1 = return 1
        | x == 1 && y == 0 = return 1
        | otherwise = case c of
                        Just x  → return x
                        Nothing → do
                          cr    ← get (x - 1, y)
                          cd    ← get (x, y - 1)
                          right ← countPathsWithCache (x - 1) y cr
                          down  ← countPathsWithCache x (y - 1) cd
                          let paths = right + down
                          set (x, y) paths
                          return (right + down)

  main :: IO ()
  main = print (fst $ ST.runState (countPaths 2 2) M.empty)
