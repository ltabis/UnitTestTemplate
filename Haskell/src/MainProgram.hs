module MainProgram
    ( dispRound
    ) where

import System.Exit
import System.IO
import Lib

dispRound::[String]->IO ()
dispRound args
    | toConvert == -1 = exitWith (ExitFailure 84)
    | otherwise = putStrLn $ show $ roundF toConvert
    where toConvert = convertToFloat (args !! 0)