//
//  main.cpp
//  Project2
//

#include <iostream>
#include <string>
using namespace std;

void   promptForData( string & plan, string & type, string & days, string & facilities, string & autopay, string & paperless );
bool   validateData( string plan, string type, string days, string facilities, string autopay, string paperless  );
double calculateCost( string plan, string type, string days, string facilities, string autopay, string paperless  );
void   output( string plan, double price );

int main()
{
    string plan       = "";
    string type       = "";
    string days       = "";
    string facilities = "";
    string autopay    = "";
    string paperless  = "";
    
    double price = 0;
    promptForData( plan, type, days, facilities, autopay, paperless );
    if (validateData( plan, type, days, facilities, autopay, paperless  ))
    {
        price = calculateCost(  plan, type, days, facilities,  autopay,  paperless  );
        output( plan, price );
    }
    
    return( 0 );
}


void   promptForData( string & plan, string & type, string & days, string & facilities, string & autopay, string & paperless )
{
    cout << "What kind of gym membership plan do you want to buy? ";
    getline( cin, plan );
    cout << "What type of gym membership do you want to buy? ";
    getline( cin, type );
    cout << "Which days do you want to workout? ";
    getline( cin, days );
    cout << "Which facilities do you want to access to? ";
    getline( cin, facilities );
    cout << "Are you on autopay? ";
    getline( cin, autopay );
    cout << "Are you on paperless billing? ";
    getline( cin, paperless );
}

bool   validateData( string plan, string type, string days, string facilities, string autopay, string paperless  )
{
    bool result = true;
    
    // plans
    const string KIND_EXECUTIVE = "Executive";
    const string KIND_BASIC     = "Basic";
    
    // type
    const string TYPE_CHILD  = "Child";
    const string TYPE_ADULT  = "Adult";
    const string TYPE_SENIOR = "Senior";
    
    // days
    const string ODD      = "Odd";
    const string EVEN     = "Even";
    const string EVERYDAY = "Everyday";
    
    // facilities
    const string JUSTONE  = "Just One";
    const string REGIONAL = "Regional";
    const string NATIONAL = "National";
    
    // answers
    const string YES = "Yes";
    const string NO  = "No";
    
    // validate data entry
    if (plan != KIND_EXECUTIVE && plan != KIND_BASIC)
    {
        cout << "Your kind of membership plan is not valid!" << endl;
        result = false;
    }
    else if (type != TYPE_CHILD && type != TYPE_ADULT && type != TYPE_SENIOR)
    {
        cout << "Your type of membership is not valid!" << endl;
        result = false;
    }
    else if (days != ODD && days != EVEN && days != EVERYDAY)
    {
        cout << "Your membership days are not valid!" << endl;
        result = false;
    }
    else if (facilities != JUSTONE && facilities != REGIONAL && facilities != NATIONAL)
    {
        cout << "Your facilities choice is not valid!" << endl;
        result = false;
    }
    else if (autopay != YES && autopay != NO )
    {
        cout << "Your autopay is not valid!" << endl;
        result = false;
    }
    else if (paperless != YES && paperless != NO)
    {
        cout << "Your paperless billing is not valid!" << endl;
        result = false;
    }
    return( result );
}

double  calculateCost( string plan, string type, string days, string facilities, string autopay, string paperless  )
{
    double price = 0;
    
    // plans
    const string KIND_EXECUTIVE = "Executive";
    const string KIND_BASIC     = "Basic";
    
    // type
    const string TYPE_CHILD  = "Child";
    const string TYPE_ADULT  = "Adult";
    const string TYPE_SENIOR = "Senior";
    
    // days
    const string ODD      = "Odd";
    const string EVEN     = "Even";
    const string EVERYDAY = "Everyday";
    
    // facilities
    const string JUSTONE  = "Just One";
    const string REGIONAL = "Regional";
    const string NATIONAL = "National";
    
    // answers
    const string YES = "Yes";
    const string NO  = "No";
    
    // discounts
    const int AUTOPAY    = 2;
    const int PAPERLESS  = 3;
    
    // costs
    const int EXECUTIVE_PLAN_COST      = 100;
    const int BASIC_PLAN_COST          = 50;
    const int EVERYDAY_COST            = 25;
    const int REGIONAL_FACILITIES_COST = 30;
    const int NATIONAL_FACILITIES_COST = 50;

    // determine cost
    if (plan == KIND_BASIC)
    {
        price = BASIC_PLAN_COST;
    }
    else if (plan == KIND_EXECUTIVE)
    {
        price = EXECUTIVE_PLAN_COST;
    }
    
    // upgrades
    if (days == EVERYDAY)
    {
        price += EVERYDAY_COST;
    }
    if (facilities == REGIONAL)
    {
        price += REGIONAL_FACILITIES_COST;
    }
    else if (facilities == NATIONAL)
    {
        price += NATIONAL_FACILITIES_COST;
    }
    
    // discounts
    if (type == TYPE_CHILD)
    {
        price = price / 2.0;     // 50% discount
    }
    if (type == TYPE_SENIOR)
    {
        price -= price / 4.0;    // 25% discount
    }
    if (autopay == YES)
    {
        price -= AUTOPAY;
    }
    if (paperless == YES)
    {
        price -= PAPERLESS;
    }
    return( price );
}

void   output( string plan, double price )
{
    // output doubles as dollars and cents
    cout.setf( ios::fixed );
    cout.setf( ios::showpoint );
    cout.precision( 2 );
    cout << "Your " << plan << " gym membership costs $" << price << endl;
}
