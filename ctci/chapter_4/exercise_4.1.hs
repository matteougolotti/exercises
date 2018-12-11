-- | 4.1 Implement a function to check if a binary tree is balanced.
-- |     For the purposes of this question, a balanced tree is defined to be
-- |     a tree such that the heights of the two subtrees of any node never differ.

{-# LANGUAGE UnicodeSyntax #-}
module Main where

data Tree a = Leaf a | Branch (Tree a) (Tree a)

symmetric ∷ Tree a → Bool
symmetric tree = snd $ explore tree 0
  where
    explore ∷ Tree a → Int → (Int, Bool)
    explore (Leaf _) depth     = (depth, True)
    explore (Branch l r) depth = do
      let (ld, lr)  = explore l (depth + 1)
      let (rd, rr)  = explore r (depth + 1)
      (max ld rd , lr && rr && abs (ld - rd) < 1)

main ∷ IO ()
main = do
  let asymmetricTree = Branch (Branch (Leaf 1) (Leaf 2)) (Leaf 3)
  let symmetricTree  = Branch (Branch (Leaf 1) (Leaf 2)) (Branch (Leaf 3) (Leaf 4))
  print $ "Should be False => " ++ show (symmetric asymmetricTree)
  print $ "Should be True  => " ++ show (symmetric symmetricTree)
