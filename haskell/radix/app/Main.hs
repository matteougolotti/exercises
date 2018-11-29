module Main where
  
  import Criterion.Main
  import Data.List
  import Radix
  import System.Random

  randomlist :: Int -> StdGen -> [Int]
  randomlist n = take n . unfoldr (Just . random)

  main :: IO ()
  main = do
    seed <- newStdGen
    let numbers10 = (`quot` 1000) <$> randomlist 10 seed
    let numbers100 = (`quot` 1000) <$> randomlist 100 seed
    let numbers1000 = (`quot` 1000) <$> randomlist 1000 seed
    let numbers10000 = (`quot` 1000) <$> randomlist 10000 seed
    let numbers1000000 = (`quot` 1000) <$> randomlist 1000000 seed
    defaultMain [ bgroup "10" [ bench "radix" $ whnf radix numbers10
                              , bench "sort"  $ whnf sort numbers10 ]
                , bgroup "100" [ bench "radix" $ whnf radix numbers100
                               , bench "sort" $ whnf sort numbers100 ]
                , bgroup "1000" [ bench "radix" $ whnf radix numbers1000
                                , bench "sort" $ whnf sort numbers1000 ]
                , bgroup "10000" [ bench "radix" $ whnf radix numbers10000
                                 , bench "sort" $ whnf sort numbers10000 ]
                , bgroup "1000000" [ bench "radix" $ whnf radix numbers1000000
                                   , bench "sort" $ whnf sort numbers1000000 ]
      ]
