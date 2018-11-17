-- | https://www.hackerrank.com/challenges/between-two-sets/problem

{-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields #-}

module Main where

import Control.Monad
import Data.List
import Data.List.Split

import System.Environment
import System.IO

(|>) :: a -> (a -> b) -> b
(|>) x f = f x

getTotalX :: [Int] -> [Int] -> Int
getTotalX a b = [maximum a..minimum b]
    |> filter (\ x -> fmap (\ y -> x `mod` y) a |> sum == 0)
    |> filter (\ x -> fmap (\ y -> y `mod` x) b |> sum == 0)
    |> length

readMultipleLinesAsStringArray :: Int -> IO [String]
readMultipleLinesAsStringArray 0 = return []
readMultipleLinesAsStringArray n = do
    line <- getLine
    rest <- readMultipleLinesAsStringArray(n - 1)
    return (line : rest)

main :: IO()
main = do
    outputPath <- getEnv "OUTPUT_PATH"
    fptr <- openFile outputPath WriteMode

    nmTemp <- getLine
    let nm = words nmTemp
    let n = read (nm !! 0) :: Int
    let m = read (nm !! 1) :: Int
    aTemp <- getLine
    let a = Data.List.map (read :: String -> Int) . words $ aTemp
    bTemp <- getLine
    let b = Data.List.map (read :: String -> Int) . words $ bTemp

    let total = getTotalX a b
    
    hPutStrLn fptr $ show total

    hFlush fptr
    hClose fptr
