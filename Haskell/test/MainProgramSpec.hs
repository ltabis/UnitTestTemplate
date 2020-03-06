module MainProgramSpec
    ( spec
    ) where

import Test.Hspec
import System.Exit
import System.IO.Silently

import MainProgram

spec :: Spec
spec = do
    describe "dispRound" $do
        it "dispRound with bad value" $ dispRound ["toto"] `shouldThrow` (==ExitFailure 84)
        -- (output, _) <- capture (putStr "wookies!")
        -- (output, _) <- capture $ dispRound ["1.2"]
        -- it "dispRound with good value" $ output `shouldBe` "1.0"
        it "dispRound with good value" $ dispRound ["1.2"] `shouldReturn` ()
