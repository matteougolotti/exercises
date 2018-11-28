{-# LANGUAGE UnicodeSyntax #-}

module Radix(radix) where

  listToBuckets ∷ [Int] → Int → Int → [[Int]]
  listToBuckets numbers base iteration =
    let numberWithDigit = (\ n → (n, (n `quot` (base ^ iteration)) `mod` base)) <$> numbers
    in [ fst <$> filter (\ (number, digit) → digit == bucket) numberWithDigit | bucket ← [0..base] ]

  radix ∷ [Int] → Int → [Int]
  radix [] _         = []
  radix numbers base = do
    let m = maximum (abs <$> numbers)
    reverse ((\ x → -x) <$> rsort ((\ x → -x) <$> filter (<0) numbers) m 0)
      ++ rsort (filter (>=0) numbers) m 0
    where
      rsort ∷ [Int] → Int -> Int -> [Int]
      rsort n m' it
        | null n         = []
        | base ^ it > m' = n
        | otherwise      = rsort (concat (listToBuckets n base it)) m' (it + 1)
