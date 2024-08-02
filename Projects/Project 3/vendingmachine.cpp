#include <iostream>
#include <cassert>
#include <string>

using namespace std;

bool isValidVendingMachineString(string vendingstring);
double amountSpent(string vendingstring);
double changeReturned(string vendingstring);
int howManyItemsBought(string vendingstring);
bool isInStrList(string vendingstring, string strList);
bool isInCharList(char chr, string strList);
bool isEnough(size_t idx, size_t tempIdx, string vendingstring);
double amountDeposited(string vendingstring);
double amountSpent(string vendingstring);
double substrAmountSpent(string vendingstring);

int main()
{
    assert( isValidVendingMachineString("R") == true );
    assert( isValidVendingMachineString("    ") == false );
    assert( howManyItemsBought( "" ) == -1 );
    assert( howManyItemsBought( "      " ) == -1 );
    assert( howManyItemsBought( "DpMqDqMqDqPA3" ) == 1 );
    assert( std::to_string( amountSpent( "DpMqDqMqDqPA3" ) ) == "1.000000" );
    assert( std::to_string( changeReturned( "DpMqDqMqDqPA3" ) ) == "0.010000" );

    return 0;
}

bool isValidVendingMachineString(string vendingstring)
{
    //Cannot be an empty string
    if(vendingstring == "")
    {
        return false;
    }
    
    //Can contain only the uppercase letters D, M, P, R, A, B, C, the lowercase letters p, n, d, q and $ as well as digit characters 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9
    if(!isInStrList(vendingstring, "DMPRABCpndq$0123456789"))
    {
        return false;
    }
    
    //Must start with the uppercase letter D, M or R
    if(vendingstring.at(0) != 'M' && vendingstring.at(0) != 'D' && vendingstring.at(0) != 'R')
    {
        return false;
    }
    
    //Must end with a purchase or refund
    if(!isdigit(vendingstring.at(vendingstring.length()-1)) && ((vendingstring.at(vendingstring.length()-1)) != 'R'))
    {
        return false;
    }
    
    //Can only allow a single p, n, d, q or $ following a D or M
    for(size_t i = 0; i < vendingstring.length(); i++)
    {
        if(vendingstring.at(i) == 'D' || vendingstring.at(i) == 'M')
        {
            if(!isInCharList(vendingstring.at(i+1), "pndq$") || isInCharList(vendingstring.at(i+2), "pndq$"))
            {
                return false;
            }
        }
    }
    
    //p, n, d, q or $ can only be put after D or M
    for(size_t i = 0; i < vendingstring.length(); i++)
    {
        if(isInCharList(vendingstring.at(i), "pndq$"))
        {
            if(vendingstring.at(i-1) != 'D' && vendingstring.at(i-1) != 'M')
            {
                return false;
            }
        }
    }
    
    //Each row contains only ten items, valued 0 thru 9, as in A0, A1, A2, A3, A4, A5, A6, A7, A8 and A9
    for(size_t i = 0; i < vendingstring.length(); i++)
    {
        if(vendingstring.at(i) == 'A' || vendingstring.at(i) == 'B' || vendingstring.at(i) == 'C')
        {
            if(!isdigit(vendingstring.at(i+1)))
            {
                return false;
            }
            if((i < (vendingstring.length() - 3)))
            {
                if(isdigit(vendingstring.at(i+2)))
                {
                    return false;
                }
            }
        }
    }
    
    //An item must be chosen to complete any purchase
    for(size_t i = 0; i < vendingstring.length(); i++)
    {
        if(vendingstring.at(i) == 'P')
        {
            if(vendingstring.at(i+1) != 'A' && vendingstring.at(i+1) != 'B' && vendingstring.at(i+1) != 'C')
            {
                return false;
            }
        }
    }
    
    //Digits can only be put after A or B or C
    for(size_t i = 0; i < vendingstring.length(); i++)
    {
        if(isdigit(vendingstring.at(i)))
        {
            if(vendingstring.at(i-1) != 'A' && vendingstring.at(i-1) != 'B' && vendingstring.at(i-1) != 'C')
            {
                return false;
            }
        }
    }
    
    //Enough money must be deposited prior to a purchase.  Row A items cost $1.00.  Row B items cost $2.00.  Row C items cost $3.00
    size_t tempIdx = 0;
    for(size_t i = 0; i < vendingstring.length(); i++)
    {
        if(vendingstring.at(i) == 'P')
        {
            if(!isEnough(i, tempIdx, vendingstring))
            {
                return false;
            }
        }
        else if(vendingstring.at(i) == 'R')
        {
            tempIdx = i;
        }
    }
    
    return true;
}


bool isInStrList(string vendingstring, string strList)
{
    for(size_t i = 0; i < vendingstring.length(); i++)
    {
        if(strList.find(vendingstring.at(i)) == std::string::npos)
        {
            return false;
        }
    }
    return true;
}

bool isInCharList(char chr, string strList)
{
    for(size_t j = 0; j < strList.length(); j++)
    {
        if(chr == strList.at(j))
        {
            return true;
        }
    }
    
    return false;
}

bool isEnough(size_t idx, size_t tempIdx, string vendingstring)
{
    string subVendStr = vendingstring.substr(tempIdx,idx+1-tempIdx);
    double depositAmount = 0.0;
    double cost = 0.0;
    
    for(size_t i = 0; i < subVendStr.length()-1; i++)
    {
        if(subVendStr.at(i) == 'D' || subVendStr.at(i) == 'M')
        {
            switch(subVendStr.at(i+1))
            {
                case '$':
                    depositAmount += 1;
                    break;
                case 'q':
                    depositAmount += 0.25;
                    break;
                case 'd':
                    depositAmount += 0.1;
                    break;
                case 'n':
                    depositAmount += 0.05;
                    break;
                case 'p':
                    depositAmount += 0.01;
                    break;
            }
        }
        else if(subVendStr.at(i) == 'R')
        {
            depositAmount = 0;
        }
    }
    
    for(size_t j = 0; j < subVendStr.length(); j++)
    {
        if(subVendStr.at(j) == 'P')
        {
            switch(vendingstring.at(j+1))
            {
                case 'A':
                    cost += 1;
                    break;
                case 'B':
                    cost += 2;
                    break;
                case 'C':
                    cost += 3;
                    break;
            }
        }
    }
    
    if(depositAmount < cost)
    {
        return false;
    }
        
    return true;
}

double amountDeposited(string vendingstring)
{
    double deposit = 0.0;
    for(size_t i = 0; i < (vendingstring.length() - 1); i++)
    {
        if(vendingstring.at(i) == 'D' || vendingstring.at(i) == 'M')
        {
            switch(vendingstring.at(i+1))
            {
                case '$':
                    deposit += 1;
                    break;
                case 'q':
                    deposit += 0.25;
                    break;
                case 'd':
                    deposit += 0.1;
                    break;
                case 'n':
                    deposit += 0.05;
                    break;
                case 'p':
                    deposit += 0.01;
                    break;
            }
        }
    }
    
    return deposit;
}

double amountSpent(string vendingstring)
{
    double cost = 0.0;
    if(isValidVendingMachineString(vendingstring))
    {
        for(size_t i = 0; i < (vendingstring.length() - 1); i++)
        {
            if(vendingstring.at(i) == 'P')
            {
                switch(vendingstring.at(i+1))
                {
                    case 'A':
                        cost += 1;
                        break;
                    case 'B':
                        cost += 2;
                        break;
                    case 'C':
                        cost += 3;
                        break;
                }
            }
        }
        return cost;
    }

    return -1.00;
}

double substrAmountSpent(string vendingstring)
{
    double cost = 0.0;
    for(size_t i = 0; i < (vendingstring.length() - 1); i++)
    {
        if(vendingstring.at(i) == 'P')
        {
            switch(vendingstring.at(i+1))
            {
                case 'A':
                    cost += 1;
                    break;
                case 'B':
                    cost += 2;
                    break;
                case 'C':
                    cost += 3;
                    break;
            }
        }
    }
    
    return cost;
}

double changeReturned(string vendingstring)
{
    double refund = 0.00;
    size_t idx = 0;
    if(isValidVendingMachineString(vendingstring))
    {
        if(vendingstring == "R")
        {
            return 0.00;
        }
        else if(vendingstring.at(vendingstring.length()-1) == 'R')
        {
            for(size_t i = 0; i < vendingstring.length()-1; i++)
            {
                if(vendingstring.at(i) == 'R')
                {
                    idx = i;
                }
            }
        }
        else
        {
            for(size_t i = 0; i < vendingstring.length(); i++)
            {
                if(vendingstring.at(i) == 'R')
                {
                    idx = i;
                }
            }
        }
        string vendingsubstr = vendingstring.substr(idx,(vendingstring.length()-1));
        refund = amountDeposited(vendingsubstr) - substrAmountSpent(vendingsubstr);
        return refund;
    }
    
    return -1.00;
}

int howManyItemsBought(string vendingstring)
{
    if(isValidVendingMachineString(vendingstring))
    {
        int numItem = 0;
        for(size_t i = 0; i < vendingstring.length(); i++)
        {
            if(vendingstring.at(i) == 'A' || vendingstring.at(i) == 'B' || vendingstring.at(i) == 'C')
            {
                numItem++;
            }
        }
        return numItem;
    }
    
    return -1;
}
