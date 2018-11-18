-- | https://www.hackerrank.com/challenges/area-under-curves-and-volume-of-revolving-a-curv/problem

{-# LANGUAGE UnicodeSyntax #-}

import           Data.List
import           Text.Printf (printf)

toDouble ∷ Real a ⇒ a → Double
toDouble x = fromRational $ toRational x

integral ∷ (Double → Double) → Double → Double → Double
integral f l r = sum [ f x * dx | x ← [l, l + dx .. r] ]
    where dx = 0.001

polynomial ∷ [Double] → [Double] → Double → Double
polynomial as bs x = sum [ a * x ** b | (a, b) ← zip as bs ]

rotate ∷ Floating a ⇒ (p → a) → (p → a)
rotate f x = pi * r ** 2
    where r = f x

area ∷ (Double → Double) → Double → Double → Double
area f l r = integral f

volume ∷ (Double → Double) → Double → Double → Double
volume f l r = integral (rotate f)

solve ∷ Int → Int → [Int] → [Int] → [Double]
solve l r a b = do
    let a' = toDouble <$> a
    let b' = toDouble <$> b
    let l' = toDouble l
    let r' = toDouble r
    [ area (polynomial a' b') l' r', volume (polynomial a' b') l' r' ]

main ∷ IO ()
main = getContents >>= mapM_ (printf "%.1f\n"). (\[a, b, [l, r]] -> solve l r a b). map (map read. words). lines
