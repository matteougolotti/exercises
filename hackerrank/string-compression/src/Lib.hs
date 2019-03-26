{-# LANGUAGE UnicodeSyntax #-}
module Lib
    ( compress
    ) where

compress ∷ String → String
compress []     = []
compress (x:xs) = compressRec xs x 1
  where
    compressRec ∷ String → Char → Int → String
    compressRec [] repeated repetitions
      | repetitions > 1 = repeated : show repetitions
      | otherwise       = [repeated]
    compressRec (x:xs) repeated repetitions
      | x == repeated   = compressRec xs repeated (repetitions + 1)
      | repetitions > 1 = repeated : show repetitions ++ compressRec xs x 1
      | otherwise       = repeated : compressRec xs x 1
