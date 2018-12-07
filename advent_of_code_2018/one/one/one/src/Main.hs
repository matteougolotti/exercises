{-# LANGUAGE UnicodeSyntax #-}
module Main where

main ∷ IO ()
main = do
  content <- readFile "input"
  print (length content)
  let numbers = readInt <$> lines (filter (/='+') content)
  print $ sum numbers
  where
    readInt = read :: String → Int
