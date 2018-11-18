-- | https://www.hackerrank.com/challenges/lambda-march-compute-the-area-of-a-polygon/problem

{-# LANGUAGE UnicodeSyntax #-}

module Main where

import           System.IO

toDouble ∷ String → Double
toDouble s = read s :: Double

area ∷ [(Double, Double)] → Double
area points = do
    let coords = unzip points
    let n = length points - 1
    let x = fst coords
    let y = snd coords
    let first  = sum [ x!!i * y!!(i + 1) | i ← [ 0 .. n - 1 ] ] + (x!!n * y!!0)
    let second = sum [ x!!(i + 1) * y!!i | i ← [ 0 .. n - 1 ] ] + (x!!0 * y!!n)
    (1 / 2) * abs (first - second)

main ∷ IO ()
main = do
  c ← getContents
  let l = fmap words (tail (lines c))
  let points = fmap (\ [x, y] → (toDouble x, toDouble y)) l
  print (area points)
