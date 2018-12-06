{-# LANGUAGE UnicodeSyntax #-}
module Main where

import           Data.Map.Strict as M
import           Data.Maybe

findFrequency ∷ Int → [Int] -> [Int] → M.Map Int Int → Int
findFrequency frequency [] l cache = findFrequency frequency l l cache 
findFrequency frequency (x:xs) l cache = do
  let f = frequency + x
  fromMaybe (findFrequency f xs l (M.insert f f cache))
   (M.lookup f cache)

main ∷ IO ()
main = do
  content <- readFile "input"
  let numbers = readInt <$> lines (Prelude.filter (/='+') content)
  print $ findFrequency 0 numbers numbers (M.insert 0 0 M.empty)
  where
    readInt = read :: String → Int
