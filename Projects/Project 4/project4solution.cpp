//
//  main.cpp
//  Project4
//

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;



string majorityElement( const string array[ ], int n )
{
    string result = "";
    if (n > 0)
    {
         for (int i = 0; i < n; i++)
         {
             int count = 0;
             string majorityCandidate = array[ i ];
             for (int j = 0; j < n; j++)
             {
                 if (array[ j ] == majorityCandidate)
                 {
                     count = count + 1;
                 }
             }
             if (count > n / 2)
             {
                 result = majorityCandidate;
                 break;
             }
         }
    }
    return( result );
}




int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill )
// replace every occurrence of letterToReplace with
//     letterToFill in every item.
// return -1 if the array has no elements
// otherwise return how many letters were replaced
{
    int result = -1;
    
    if (n > 0)
    {
        result = 0;
        for (int i = 0; i < n; i++)
        {
            string element = array[ i ];
            for (size_t j = 0; j < element.size(); j++)
            {
                if (element[j] == letterToReplace)
                {
                    element[ j ] = letterToFill;
                    result++;
                }
            }
            array[ i ] = element;
        }
    }
    return( result );
}


// verify that like values are right next to each other
// 1 2 3 1 5  false
// 1 1 1 2 3  true
// 2 3 1 1 1  true
bool matchingValuesTogether( const string array[ ], int n )
{
    bool result( true );
    bool matchingLocated( false );
    string valueToMatch( "" );
    
    // with nothing to evaluate, the answer should be false
    if (n <= 0)
    {
        result = false;
    }
    for( int i = 0; i < n; i++ )
    {
        matchingLocated = false;
        int slot = i;
        valueToMatch = array[ i ];
        for (int j = i+1; j < n; j++)
        {
            if (array[ j ] == valueToMatch)
            {
                if (slot + 1 == j)
                {
                    matchingLocated = true;
                    slot = j;
                }
                else
                {
                    result = false;
                    break;
                }
            }
        }
    }
    return( result );
}

// find the position of the biggest one
int locateMaximum( const string array[ ], int n )
{
    int result( -1 );
    string maximum( "" );
    
    // at first, the maximum item will be in position 0, if the array has any elements
    if (n > 0)
    {
        maximum = array[ 0 ];
        result = 0;
    }
    for( int i = 1; i < n; i++ )
    {
        if (array[i] > maximum)
        {
            maximum = array[ i ];
            result = i;
        }
    }
    return( result );
}

// find last occurrence of target in the array
int findLastOccurrence( const string array[ ], int n, string target )
{
    int result( -1 );
    if (n > 0)
    {
        for( int i = n-1; i >= 0; i-- )
        {
            if (array[ i ] == target)
            {
                result = i;
                break;
            }
        }
    }
    return( result );
}

// verify that the string array has duplicated values
bool hasDuplicates( const string array[ ], int n )
{
    bool result( false );

    for( int i = 0; i < n; i++ )
    {
        string lookingFor = array[ i ];
        // this inner loop can really start from i+1, not 0
        // because earlier iterations would have found the duplicate already, if it exists
        for( int j = i+1; j < n; j++ )
        {
            if (array[ j ] == lookingFor)
            {
                result = true;
                break;
            }
        }
        // why keep looping if we already know the answer is true?
        if (result)
        {
            break;
        }
    }
    return( result );
}


// supports +1.4  -3.4   3.4
// supports 555555 5555.
int countFloatingPointValues( const string array[ ], int n )
{
    int result = -1;
    if (n > 0)
    {
        result = 0;
        for (int i = 0; i < n; i++)
        {
            bool isInteger = true;
            bool startsWithPlusOrMinusOrNone = true;
            int  countDecimalPoint = 0;
            string element = array[ i ];
            for (size_t j = 0; j < element.size(); j++)
            {
                // + or - only at the start
                if (element[j] == '+' || element[j] == '-')
                {
                    if (j == 0)
                    {
                        startsWithPlusOrMinusOrNone = true;
                    }
                    else
                    {
                        startsWithPlusOrMinusOrNone = false;
                        break;
                    }
                }
                else if (element[j] == '.')
                {
                    countDecimalPoint++;
                }
                else if (!isdigit( element[j] ))
                {
                    isInteger = false;
                    break;
                }
            }
            // the decimal point is optional but can
            // be found only once
            if (isInteger && startsWithPlusOrMinusOrNone && (countDecimalPoint == 0 || countDecimalPoint == 1))
            {
                result = result + 1;
            }
        }
    }
    return( result );
}

// reverses a string
string reverse(string str)
{
    string result = "";
    if (str.length() > 0)
    {
       for (size_t i = str.length() - 1; i >= 0; --i)
       {
         result += str.at( i );
         if (i == 0)
         {
            break;
         }
       }
    }
    return( result );
}


// verify that the string array has a value that is the reverse of an existing value
bool hasReverse( const string array[ ], int n )
{
    bool result( false );

    for( int i = 0; i < n; i++ )
    {
        string lookingFor = reverse( array[ i ] );
        // this inner loop can really start from i+1, not 0
        // because earlier iterations would have found the duplicate already, if it exists
        for( int j = i+1; j < n; j++ )
        {
            if (array[ j ] == lookingFor)
            {
                result = true;
                break;
            }
        }
        // why keep looping if we already know the answer is true?
        if (result)
        {
            break;
        }
    }
    return( result );
}


