module Main where

import System.Environment
import System.Exit
import System.IO

import MainProgram

main::IO ()
main = do
    args <- getArgs
    if (length args == 1) then dispRound args else exitWith (ExitFailure 84)
    return()
