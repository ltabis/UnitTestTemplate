module Lib
    ( cleanStr, roundF, convertToFloat
    ) where

import Text.Read

cleanStr::String->String->String
cleanStr str to_rem = [x | x <- str, not(x `elem` to_rem)]

roundF::Float->Float
roundF nb = fromIntegral $ round nb

convertToFloat::String->Float
convertToFloat to_float = case readMaybe to_float :: Maybe Float of
                  Just to_float -> to_float
                  Nothing -> (-1)