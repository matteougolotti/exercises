{-# LANGUAGE UnicodeSyntax #-}

import           Test.QuickCheck.Arbitrary.Generic
import           Test.Tasty
import           Test.Tasty.HUnit
import           Test.Tasty.QuickCheck             as QC

import           Radix

import           Data.List
import           Data.Ord

main = defaultMain tests

tests ∷ TestTree
tests = testGroup "Tests" [properties]

properties ∷ TestTree
properties = testGroup "Properties" [radixProps]

radixProps = testGroup "Test properties"
  [
    QC.testProperty "sort == radix" $
      \list -> sort (list :: [Int]) == Radix.radix list
  ]
