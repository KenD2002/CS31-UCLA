//
//  Score.cpp
//  Bunco
//
//  Created by Howard Stahl on 2/21/22.
//  Copyright © 2022 Howard Stahl. All rights reserved.
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

// TODO comparing the played move to the answer move,
//      build the ANSWER array of this Score
Score::Score( Move move, Move answer )
{
    //set the default to be "_____"
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
    
    //if two same letter are in the same position, change this position of ANSWER array to RIGHT
    std::string temp1 = move.to_string();
    std::string temp2 = answer.to_string();
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        if((temp1.at(i) == temp2.at(i) && (temp1.at(i) != '\0')))
        {
            array[i] = RIGHT;
            temp1.at(i) = '\0';
            temp2.at(i) = '\0';
        }
    }
    
    //after check same letter same position, if there are still any same letter different position, change this position of ANSWER array to MAYBE
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        for( int j = 0; j < REQUIREDLENGTH; j ++)
        {
            if((temp1.at(i) == temp2.at(j) && (temp1.at(i) != '\0')))
            {
                array[i] = MAYBE;
                temp1.at(i) = '\0';
                temp2.at(j) = '\0';
            }
        }
    }
}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const
{
    //if any position does not match, then not exactly match
    for(int i = 0; i < REQUIREDLENGTH; i ++)
    {
        if(array[i] != RIGHT)
        {
            return false;
        }
    }
    //otherwise everything is matched exactly
    return( true );
}

}
