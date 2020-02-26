module LibSpec
    ( spec
    ) where

import Test.Hspec
import System.Exit

import Lib

spec :: Spec
spec = do
    describe "cleanStr" $ do
        it "Remove . and $" $ do cleanStr "to.t$$o" ".$" `shouldBe` "toto"
        it "Nothing to remove" $ do cleanStr "titi" "" `shouldBe` "titi"
    describe "roundF" $ do
        it "Round a float to lower" $ do roundF 1.3 `shouldBe` 1.0
        it "Round a float to greater" $ do roundF 1.8 `shouldBe` 2.0
    describe "convertToFloat" $ do
        it "Convert a good float" $ do convertToFloat "2.3" `shouldBe` 2.3
        it "Convert a bad float" $ do convertToFloat "toto" `shouldBe` -1
