module MainProgramSpec
    ( spec
    ) where

import Test.Hspec
import System.Exit

import MainProgram

spec :: Spec
spec = do
    describe "dispRound" $do
        it "dispRound with bad value" $ dispRound ["toto"] `shouldThrow` (==ExitFailure 84)
        -- it "dispRound with good value" $ dispRound ["1.2"] `` (==ExitFailure 84)
