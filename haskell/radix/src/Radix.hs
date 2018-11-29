{-# LANGUAGE UnicodeSyntax #-}

module Radix(radix) where

  listToBuckets ∷ [Int] → Int → Int → [[Int]]
  listToBuckets numbers base iteration =
    let numberWithDigit = (\ n → (n, (n `quot` (base ^ iteration)) `mod` base)) <$> numbers
    in [ fst <$> filter (\ (number, digit) → digit == bucket) numberWithDigit | bucket ← [0..base] ]

  radix ∷ [Int] → [Int]
  radix []      = []
  radix numbers = do
    let base = 10
    let m = maximum (abs <$> numbers)
    reverse ((\ x → -x) <$> rsort ((\ x → -x) <$> filter (<0) numbers) m 0)
      ++ rsort (filter (>=0) numbers) m 0
    where
      rsort ∷ [Int] → Int -> Int -> [Int]
      rsort n m' it
        | null n       = []
        | 10 ^ it > m' = n
        | otherwise    = rsort (concat (listToBuckets n 10 it)) m' (it + 1)
