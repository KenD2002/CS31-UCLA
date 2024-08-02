#include <iostream>
#include <string>
using namespace std;

bool isValidVendingMachineString( string vendingstring )
{
    // commands
    const char DEPOSIT   = 'D';
    const char PURCHASE  = 'P';
    const char RETURN    = 'R';
    const char MOBILEPAY = 'M';
    
    // coin currency
    const char DIME    = 'd';
    const char PENNY   = 'p';
    const char QUARTER = 'q';
    const char NICKEL  = 'n';
    const char DOLLAR  = '$';
    
    // allowed rows
    const char ROWA  = 'A';
    const char ROWB  = 'B';
    const char ROWC  = 'C';
    const char NOROW = ' ';
    
    // row costs
    int ROWACOST = 1;  // 1 dollar
    int ROWBCOST = 2;  // 2 dollars
    int ROWCCOST = 3;  // 3 dollars
    
    // items
    const char ZERO  = '0';
    const char ONE   = '1';
    const char TWO   = '2';
    const char THREE = '3';
    const char FOUR  = '4';
    const char FIVE  = '5';
    const char SIX   = '6';
    const char SEVEN = '7';
    const char EIGHT = '8';
    const char NINE  = '9';
    
    // state
    bool isDepositing    = false;
    bool isPurchasing    = false;
    bool isRow           = false;
    bool isMobilePay     = false;
    char rememberedRow   = NOROW;
    
    // item counting
    int  item = 0;
    double  itemCost = 0;   // cost of the item selected
    // deposited value in pennies
    double  value = 0;
    
    bool result = true;
    // can the string end right now based on where we are??
    bool finalStateIsValid = false;
    
    size_t pos = 0;
    if (vendingstring.empty())
    {
        result = false;
    }

    while( result && pos < vendingstring.size() )
    {
        char cmd = vendingstring.at( pos );
        switch( cmd )
        {
            case DEPOSIT:
                if (!isDepositing)
                {
                    isDepositing = true;
                    finalStateIsValid = false;
                }
                else
                {
                    // string is not valid so no sense in proceeding any further
                    result = false;
                }
                break;
                
            case PURCHASE:
                if (value != 0)
                {
                    isPurchasing = true;
                    finalStateIsValid = false;
                }
                else
                {
                    // string is not valid so no sense in proceeding any further
                    result = false;
                }
                break;
                
            case RETURN:
                if (isDepositing || isMobilePay || isPurchasing)
                {
                    result = false;
                }
                else
                {
                    value = 0;
                    finalStateIsValid = true;
                }
                break;
                
            case MOBILEPAY:
                if (!isMobilePay)
                {
                    isMobilePay = true;
                    finalStateIsValid = false;
                }
                else
                {
                    // string is not valid so no sense in proceeding any further
                    result = false;
                }
                break;
                
            case DIME:
            case PENNY:
            case QUARTER:
            case NICKEL:
            case DOLLAR:
                if (isDepositing or isMobilePay)
                {
                    if (cmd == PENNY)
                    {
                        value += 0.01;
                    }
                    else if (cmd == NICKEL)
                    {
                        value += 0.05;
                    }
                    else if (cmd == DIME)
                    {
                        value += 0.10;
                    }
                    else if (cmd == QUARTER)
                    {
                        value += 0.25;
                    }
                    else if (cmd == DOLLAR)
                    {
                        value += 1.00;
                    }
                    isDepositing = false;
                    isMobilePay = false;
                    finalStateIsValid = false;
                }
                else
                {
                    // string is not valid so no sense in proceeding any further
                    result = false;
                }
                break;
                
            case ROWA:
            case ROWB:
            case ROWC:
                if (isPurchasing)
                {
                    isRow = true;
                    rememberedRow = cmd;
                    finalStateIsValid = false;
                }
                else
                {
                    // string is not valid so no sense in proceeding any further
                    result = false;
                }
                break;
                
            case ZERO:
            case ONE:
            case TWO:
            case THREE:
            case FOUR:
            case FIVE:
            case SIX:
            case SEVEN:
            case EIGHT:
            case NINE:
                if (isPurchasing && isRow)
                {
                    // are there enough funds?
                    if (rememberedRow == ROWA)
                    {
                        itemCost = ROWACOST;
                    }
                    else if (rememberedRow == ROWB)
                    {
                        itemCost = ROWBCOST;
                    }
                    else if (rememberedRow == ROWC)
                    {
                        itemCost = ROWCCOST;
                    }
                    if (value >= itemCost)
                    {
                        item += 1;
                        value -= itemCost;
                        isPurchasing = false;
                        isRow = false;
                        finalStateIsValid = true;
                        rememberedRow = NOROW;
                    }
                    else
                    {
                        // not enough money for the purchase
                        // string is not valid so no sense in proceeding any further
                        result = false;
                    }
                }
                else
                {
                    // string is not valid so no sense in proceeding any further
                    result = false;
                }
                break;
                
            default:
                // string is not valid so no sense in proceeding any further
                result = false;
                break;
        }
        pos = pos + 1;
    }
    
    return( result && finalStateIsValid );
}


double  amountSpent( string vendingstring )
{
    double result = -1;
    // once we know the string is valid, we don't have to be strictly checking everything
    if (isValidVendingMachineString(vendingstring))
    {
        // rows
        const char ROWA  = 'A';
        const char ROWB  = 'B';
        const char ROWC  = 'C';
        const char NOROW = ' ';
        
        // row costs
        int ROWACOST = 1;  // 1 dollar
        int ROWBCOST = 2;  // 2 dollars
        int ROWCCOST = 3;  // 3 dollars
        
        // items
        const char ZERO  = '0';
        const char ONE   = '1';
        const char TWO   = '2';
        const char THREE = '3';
        const char FOUR  = '4';
        const char FIVE  = '5';
        const char SIX   = '6';
        const char SEVEN = '7';
        const char EIGHT = '8';
        const char NINE  = '9';
        
        // state
        char rememberedRow   = NOROW;
        
        double  itemCost = 0;   // cost of the item selected
        
        size_t pos = 0;

        while( pos < vendingstring.size() )
        {
            char cmd = vendingstring.at( pos );
            switch( cmd )
            {
                case ROWA:
                case ROWB:
                case ROWC:
                    rememberedRow = cmd;
                    break;
                    
                case ZERO:
                case ONE:
                case TWO:
                case THREE:
                case FOUR:
                case FIVE:
                case SIX:
                case SEVEN:
                case EIGHT:
                case NINE:
                    if (rememberedRow == ROWA)
                    {
                        itemCost += ROWACOST;
                    }
                    else if (rememberedRow == ROWB)
                    {
                        itemCost += ROWBCOST;
                    }
                    else if (rememberedRow == ROWC)
                    {
                        itemCost += ROWCCOST;
                    }
                    rememberedRow = NOROW;
                    break;
                    
                default:
                    break;
            }
            pos = pos + 1;
        }
        result = itemCost;
    }
    return( result );
}

double  changeReturned( string vendingstring )
{
    double result = -1;
    // once we know the string is valid, we don't have to be so strict checking everything
    if (isValidVendingMachineString(vendingstring))
    {
        // commands
        const char RETURN  = 'R';
        
        // coin currency
        const char DIME    = 'd';
        const char PENNY   = 'p';
        const char QUARTER = 'q';
        const char NICKEL  = 'n';
        const char DOLLAR  = '$';
        
        // rows
        const char ROWA  = 'A';
        const char ROWB  = 'B';
        const char ROWC  = 'C';
        const char NOROW = ' ';
        
        // row costs
        int ROWACOST = 1;  // 1 dollar
        int ROWBCOST = 2;  // 2 dollars
        int ROWCCOST = 3;  // 3 dollars
        
        // items
        const char ZERO  = '0';
        const char ONE   = '1';
        const char TWO   = '2';
        const char THREE = '3';
        const char FOUR  = '4';
        const char FIVE  = '5';
        const char SIX   = '6';
        const char SEVEN = '7';
        const char EIGHT = '8';
        const char NINE  = '9';
       
        // state
        char rememberedRow   = NOROW;
        
        // item counting
        double  itemCost = 0;   // cost of the item selected
        // deposited value in pennies
        double  value = 0;
                
        size_t pos = 0;
        // since it is already valid, we can loosen these checks...
        while(pos < vendingstring.size() )
        {
            char cmd = vendingstring.at( pos );
            switch( cmd )
            {
                    
                case RETURN:
                    result = value;
                    value = 0;
                    break;
                    
                case DIME:
                case PENNY:
                case QUARTER:
                case NICKEL:
                case DOLLAR:
                    if (cmd == PENNY)
                    {
                        value += 0.01;
                    }
                    else if (cmd == NICKEL)
                    {
                        value += 0.05;
                    }
                    else if (cmd == DIME)
                    {
                        value += 0.10;
                    }
                    else if (cmd == QUARTER)
                    {
                        value += 0.25;
                    }
                    else if (cmd == DOLLAR)
                    {
                        value += 1.00;
                    }
                    break;
                    
                case ROWA:
                case ROWB:
                case ROWC:
                    rememberedRow = cmd;
                    break;
                    
                case ZERO:
                case ONE:
                case TWO:
                case THREE:
                case FOUR:
                case FIVE:
                case SIX:
                case SEVEN:
                case EIGHT:
                case NINE:
                    if (rememberedRow == ROWA)
                    {
                        itemCost = ROWACOST;
                    }
                    else if (rememberedRow == ROWB)
                    {
                        itemCost = ROWBCOST;
                    }
                    else if (rememberedRow == ROWC)
                    {
                        itemCost = ROWCCOST;
                    }
                    if (value >= itemCost)
                    {
                        value -= itemCost;
                        rememberedRow = NOROW;
                    }
                    // if the string ends at this point...
                    result = value;
                    break;
                    
                default:
                    break;
            }
            pos = pos + 1;
        }
    }
    return( result );
}

int   howManyItemsBought( string vendingstring )
{
    // items
    const char ZERO  = '0';
    const char ONE   = '1';
    const char TWO   = '2';
    const char THREE = '3';
    const char FOUR  = '4';
    const char FIVE  = '5';
    const char SIX   = '6';
    const char SEVEN = '7';
    const char EIGHT = '8';
    const char NINE  = '9';
    
    // item counting
    int  item = 0;

    // because the string is valid, we can just look for digits
    if (isValidVendingMachineString(vendingstring))
    {
        size_t pos = 0;

        while(pos < vendingstring.size() )
        {
            char cmd = vendingstring.at( pos );
            switch( cmd )
            {
                    
                case ZERO:
                case ONE:
                case TWO:
                case THREE:
                case FOUR:
                case FIVE:
                case SIX:
                case SEVEN:
                case EIGHT:
                case NINE:
                    item += 1;
                    break;
                    
                default:
                    break;
            }
            pos = pos + 1;
        }
    }
    else
    {
        item = -1;
    }
    return( item );
}


void testone(int n)
{
    switch (n)
    {
        case  1:
            assert( !isValidVendingMachineString( "" ) );
            break;
        case  2:
            assert( !isValidVendingMachineString( "     " ) );
            break;
        case  3:
            assert( !isValidVendingMachineString("DMPR") );
            break;
        case  4:
            assert( !isValidVendingMachineString("ABC") );
            break;
        case  5:
            assert( !isValidVendingMachineString("pndq$") );
            break;
        case  6:
            assert( !isValidVendingMachineString("R ") );
            break;
        case  7:
            assert( !isValidVendingMachineString("DqD$Dn") );
            break;
        case  8:
            assert( !isValidVendingMachineString("MqM$Mn") );
            break;
        case  9:
            assert( !isValidVendingMachineString("Dpndq$" ) );
            break;
        case 10:
            assert( !isValidVendingMachineString("Mpndq$") );
            break;
        case 11:
            assert( !isValidVendingMachineString("DpDpDpPA1") );
            break;
        case 12:
            assert( !isValidVendingMachineString( "D$DpDpPB1" ) );
            break;
        case 13:
            assert( !isValidVendingMachineString("D$D$DdDnPC2") );
            break;
        case 14:
            assert( !isValidVendingMachineString("D$D$PA12"));
            break;
        case 15:
            assert( !isValidVendingMachineString("MnMnMnPA3") );
            break;
        case 16:
            assert( !isValidVendingMachineString("M$MnDnDnPB4") );
            break;
        case 17:
            assert( !isValidVendingMachineString("M$M$DnDnPC5") );
            break;
        case 18:
            assert( !isValidVendingMachineString("M$M$MnPB23") );
            break;
        case 19:
            assert( !isValidVendingMachineString("M$M$M$MqPC34"));
            break;
        case 20:
            assert( !isValidVendingMachineString("M$MpPA1PA2") );
            break;
        case 21:
            assert( !isValidVendingMachineString("M$D$PB3PC4") );
            break;
        case 22:
            assert( !isValidVendingMachineString("DqD$D$D$PC5PA1")  );
            break;
        case 23:
            assert( !isValidVendingMachineString("DqD$RPA1") );
            break;
        case 24:
            assert( !isValidVendingMachineString("MqM$M$RPB6") );
            break;
        case 25:
            assert( !isValidVendingMachineString("Mq0Dn1") );
            break;
        case 26:
            assert( !isValidVendingMachineString("MqDnP1A") );
            break;
        case 27:
            assert( !isValidVendingMachineString("DnMqR      ") );
            break;
        case 28:
            assert( !isValidVendingMachineString("DnD$D$PA1RPB6") );
            break;
        case 29:
            assert( isValidVendingMachineString("M$PA9") );
            break;
        case  30:
            assert( isValidVendingMachineString("DqDqDqDqDpM$PB8R") );
            break;
        case  31:
            assert( isValidVendingMachineString("DqD$M$M$PC7") );
            break;
        case  32:
            assert( isValidVendingMachineString("DqRM$M$PB6") );
            break;
        case  33:
            assert( isValidVendingMachineString("D$D$PA5PA4") );
            break;
        case  34:
            assert( isValidVendingMachineString("D$D$RMqMqMqMqPA4") );
            break;
        case 35:
            assert( isValidVendingMachineString("D$D$D$D$D$D$PA1PB2PC3") );
            break;
        case  36:
            assert( isValidVendingMachineString("M$M$M$PA1PA2") );
            break;
        case  37:
            assert( howManyItemsBought("") == -1);
            break;
        case  38:
            assert( howManyItemsBought("     ") == -1);
            break;
        case 39:
            assert( howManyItemsBought("DMPR") == -1);
            break;
        case 40:
            assert( howManyItemsBought( "ABC" ) == -1 );
            break;
        case 41:
            assert( howManyItemsBought( "pndq$" ) == -1 );
            break;
        case 42:
            assert( howManyItemsBought( "R " ) == -1 );
            break;
        case 43:
            assert( howManyItemsBought( "DqD$Dn" ) == -1  );
            break;
        case 44:
            assert( howManyItemsBought( "MqM$Mn" ) == -1 );
            break;
        case 45:
            assert( howManyItemsBought( "Dpndq$" ) == -1 );
            break;
        case 46:
            assert( howManyItemsBought("Mpndq$") == -1 );
            break;
        case 47:
            assert( howManyItemsBought( "DpDpDpPA1" ) == -1 );
            break;
        case 48:
            assert( howManyItemsBought( "D$DpDpPB1" ) == -1);
            break;
        case 49:
            assert( howManyItemsBought( "D$D$DdDnPC2" ) == -1);
            break;
        case 50:
            assert( howManyItemsBought( "D$D$PA12" ) == -1 );
            break;
        case 51:
            assert( howManyItemsBought("MnMnMnPA3") == -1 );
            break;
        case 52:
            assert( howManyItemsBought( "M$MnDnDnPB4" ) == -1 );
            break;
        case 53:
            assert( howManyItemsBought( "M$M$DnDnPC5" ) == -1 );
            break;
        case 54:
            assert( howManyItemsBought( "M$M$MnPB23" ) == -1 );
            break;
        case 55:
            assert( howManyItemsBought( "M$M$M$MqPC34" ) == -1 );
            break;
        case 56:
            assert( howManyItemsBought( "M$MpPA1PA2" ) == -1 );
            break;
        case 57:
            assert( howManyItemsBought("M$D$PB3PC4") == -1 );
            break;
        case 58:
            assert( howManyItemsBought( "DqD$D$D$PC5PA1" ) == -1 );
            break;
        case 59:
            assert( howManyItemsBought( "DqD$RPA1" ) == -1 );
            break;
        case 60:
            assert( howManyItemsBought( "MqM$M$RPB6" ) == -1 );
            break;
        case  61:
            assert( howManyItemsBought( "Mq0Dn1" ) == -1 );
            break;
        case 62:
            assert( howManyItemsBought( "MqDnP1A" ) == -1 );
            break;
        case 63:
            assert( howManyItemsBought("DnMqR      ")  == -1);
            break;
        case  64:
            assert( howManyItemsBought( "DnD$D$PA1RPB6" ) == -1 );
            break;
        case  65:
            assert( howManyItemsBought( "M$PA9" ) == 1 );
            break;
        case  66:
            assert( howManyItemsBought( "DqDqDqDqDpM$PB8R" ) == 1);
            break;
        case  67:
            assert( howManyItemsBought( "DqD$M$M$PC7" ) == 1 );
            break;
        case 68:
            assert( howManyItemsBought( "DqRM$M$PB6" ) == 1 );
            break;
        case  69:
            assert( howManyItemsBought( "D$D$PA5PA4" ) == 2 );
            break;
        case 70:
            assert( howManyItemsBought("D$D$RMqMqMqMqPA4") == 1 );
            break;
        case  71:
            assert( howManyItemsBought( "D$D$D$D$D$D$PA1PB2PC3" ) == 3 );
            break;
        case  72:
            assert( howManyItemsBought( "M$M$M$PA1PA2" ) == 2 );
            break;
        case 73:
            assert( howManyItemsBought( "M$M$M$R" ) == 0 );
            break;
        case 74:
            assert( std::to_string( amountSpent( "" ) ) == "-1.000000" );
            break;
        case 75:
            assert( std::to_string( amountSpent( "     " ) ) == "-1.000000" );
            break;
        case 76:
            assert( std::to_string( amountSpent("DMPR") ) == "-1.000000" );
            break;
        case 77:
            assert( std::to_string( amountSpent("ABC") ) == "-1.000000" );
            break;
        case 78:
            assert( std::to_string( amountSpent("pndq$") ) == "-1.000000" );
            break;
        case 79:
            assert( std::to_string( amountSpent("M$PA9") ) == "1.000000" );
            break;
        case 80:
            assert( std::to_string( amountSpent("DqDqDqDqDpM$PB8R")) == "2.000000" );
            break;
        case 81:
            assert( std::to_string( amountSpent("DqD$M$M$PC7")) == "3.000000" );
            break;
        case 82:
            assert( std::to_string( amountSpent("DqRM$M$PB6")) == "2.000000" );
            break;
        case 83:
            assert( std::to_string( amountSpent("D$D$PA5PA4")) == "2.000000" );
            break;
        case 84:
            assert( std::to_string( amountSpent("D$D$RMqMqMqMqPA4")) == "1.000000" );
            break;
        case 85:
            assert( std::to_string( amountSpent("D$D$D$D$D$D$PA1PB2PC3")) == "6.000000" );
            break;
        case 86:
            assert( std::to_string( amountSpent("M$M$M$PA1PA2") ) == "2.000000" );
            break;
        case 87:
            assert( std::to_string( amountSpent("M$M$M$R") ) == "0.000000" );
            break;
        case 88:
            assert( std::to_string( changeReturned("R ") ) == "-1.000000" );
            break;
        case 89:
            assert( std::to_string( changeReturned("DqD$Dn") ) == "-1.000000" );
            break;
        case 90:
            assert( std::to_string( changeReturned("MqM$Mn")) == "-1.000000" );
            break;
        case 91:
            assert( std::to_string( changeReturned("Dpndq$" ) ) == "-1.000000" );
            break;
        case 92:
            assert( std::to_string( changeReturned("DqD$Dn") ) == "-1.000000" );
            break;
        case 93:
            assert( std::to_string( changeReturned("DpDpDpPA1") ) == "-1.000000" );
            break;
        case 94:
            assert( std::to_string( changeReturned("M$PA9") ) == "0.000000" );
            break;
        case 95:
            assert( std::to_string( changeReturned("DqDqDqDqDpM$PB8R")) == "0.010000" );
            break;
        case 96:
            assert( std::to_string( changeReturned("DqD$M$M$PC7")) == "0.250000" );
            break;
        case 97:
            assert( std::to_string( changeReturned("DqRM$M$PB6")) == "0.000000" );
            break;
        case 98:
            assert( std::to_string( changeReturned("D$D$PA5PA4")) == "0.000000" );
            break;
        case 99:
            assert( std::to_string( changeReturned("D$D$RMqMqMqMqPA4")) == "0.000000" );
            break;
        case 100:
            assert( std::to_string( changeReturned("D$D$D$D$D$D$PA1PB2PC3")) == "0.000000" );
            break;
        default:
            cout << "Bad argument" << endl;
            break;
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed!" << endl;
        return( 0 );
}
