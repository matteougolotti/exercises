{-# LANGUAGE UnicodeSyntax #-}
module Main where

import           Data.Functor
import qualified Data.Map.Strict as M
import           Data.Maybe

step ∷ Int → Int
step n
  | n > 0     = 1
  | otherwise = 0

count ∷ String → (Int, Int)
count word = countR word M.empty
  where
    countR ∷ String → M.Map Char Int → (Int, Int)
    countR [] cache = do
      let keyvalues = M.assocs cache
      let threes = step $ length $ filter (\ (k, v) → v == 3) keyvalues
      let twos   = step $ length $ filter (\ (k, v) → v == 2) keyvalues
      (twos, threes)
    countR (x:xs) cache =
      case M.lookup x cache of
        Just n  → countR xs (M.insert x (n + 1) cache)
        Nothing → countR xs (M.insert x 1 cache)

match ∷ String → String → Maybe String
match w w' = do
  let substr = fst <$> filter (uncurry (==)) (zip w w')
  if length substr == (length w - 1) then Just substr
                                     else Nothing

parttwo ∷ [String] → String
parttwo words =
  fromMaybe "" $ foldr (\ w result → case result of
                        Just s  → Just s
                        Nothing → foldr (\ w' result' → case result' of
                                                          Just s  → Just s
                                                          Nothing → match w w')
                                        Nothing words)
                        Nothing words

partone ∷ [String] → Int
partone words = do
  let (twos, threes) = foldr (\ (twos, threes) (twos', threes') → (twos + twos', threes + threes'))
                         (0, 0) (count <$> words)
  twos * threes

main ∷ IO ()
main = do
  content <- readFile "input"
  let words = lines content
  print $ partone words
  print $ parttwo words

