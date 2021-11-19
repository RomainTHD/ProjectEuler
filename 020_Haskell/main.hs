module ProjectEuler_020 where
import Test.QuickCheck

-- Sum the digits of an arbitrary number
sumDigits :: Integer -> Integer
sumDigits n | n >= 10 = n `mod` 10 + sumDigits (n `div` 10)
            | otherwise = n

-- Smart product of two numbers, avoiding overflow by simplifying trailing zeroes
-- FIXME: Maybe simplify the function using some recursive mod & div ?
prod :: Integer -> Integer -> Integer
prod n m  -- Return 0 if a number is 0
         | n == 0 = 0
         | m == 0 = 0
         -- Return the other number if multiplied by 1
         | n == 1 = m 
         | m == 1 = n
         -- Handle negatives numbers
         | n < 0 = - prod (-n) m 
         | m < 0 = - prod n (-m)
         -- Remove trailing zeroes from the multiplication with a power of 10
         | n `mod` 10 == 0 = prod (n `div` 10) m
         | m `mod` 10 == 0 = prod n (m `div` 10)
         -- Product between an even number and a number divisible by 5
         | even n && m `mod` 5 == 0 = prod (n `div` 2) (m `div` 5)
         | n `mod` 5 == 0 && even m = prod (n `div` 5) (m `div` 2)
         -- Base situation
         | otherwise = n * m

-- Factorial helper
factHelper :: Integer -> (Integer -> Integer -> Integer) -> Integer
factHelper n times | n == 0 = 1
                   | n > 0 = n `times` factHelper (n - 1) times
                   | otherwise = error "factorial: negative argument"

-- True factorial
tFactorial :: Integer -> Integer
tFactorial n = factHelper n (*)

-- Our "fake" factorial
factorial :: Integer -> Integer
factorial n = factHelper n prod

-- Quickcheck property
prop_sumDigits :: Integer -> Bool
prop_sumDigits n | n < 0 = True
                 | otherwise = sumDigits (factorial n) == sumDigits (tFactorial n)

-- Main
main :: IO()
main = print (sumDigits (factorial 100))
