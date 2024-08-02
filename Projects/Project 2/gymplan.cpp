#include <iostream>
#include <string>

using namespace std;

int main(){
    string kindOfPlan;
    string typeOfDiscount;
    string everydayAccess;
    string facilitiesAccess;
    string autopay;
    string paperlessBilling;
    double cost;
    double discountAmount;
    
    cout << "What kind of gym membership plan do you want to buy? ";
    getline(cin, kindOfPlan);
    cout << "What type of gym membership do you want to buy? ";
    getline(cin, typeOfDiscount);
    cout << "Which days do you want to workout? ";
    getline(cin, everydayAccess);
    cout << "Which facilities do you want to access to? ";
    getline(cin, facilitiesAccess);
    cout << "Are you on autopay? ";
    getline(cin, autopay);
    cout << "Are you on paperless billing? ";
    getline(cin, paperlessBilling);
    
    if (kindOfPlan != "Executive" && kindOfPlan != "Basic") {
        cout << "Your kind of membership plan is not valid!" << endl;
        return(0);
    } else {
        if (kindOfPlan == "Executive") {
            cost = 100;
        } else {
            cost = 50;
        }
    }
    
    if (typeOfDiscount != "Adult" && typeOfDiscount != "Child" && typeOfDiscount != "Senior") {
        cout << "Your type of membership is not valid!" << endl;
        return(0);
    } else {
        if (typeOfDiscount == "Adult") {
            discountAmount = 0;
        } else if (typeOfDiscount == "Child") {
            discountAmount = 0.5;
        } else {
            discountAmount = 0.25;
        }
    }
    
    if (everydayAccess != "Odd" && everydayAccess != "Even" && everydayAccess != "Everyday") {
        cout << "Your membership days are not valid!" << endl;
        return(0);
    } else {
        if (everydayAccess == "Everyday") {
            cost += 25;
        }
    }
    
    if (facilitiesAccess != "Just One" && facilitiesAccess != "Regional" && facilitiesAccess != "National") {
        cout << "Your facilities choice is not valid!" << endl;
        return(0);
    } else {
        if (facilitiesAccess == "Regional") {
            cost += 30;
        } else if (facilitiesAccess == "National") {
            cost += 50;
        }
    }
    
    cost *= (1 - discountAmount);
    
    if (autopay != "No" && autopay != "Yes") {
        cout << "Your autopay is not valid!" << endl;
        return(0);
    } else {
        if (autopay == "Yes") {
            cost -= 2;
        }
    }
    
    if (paperlessBilling != "No" && paperlessBilling != "Yes") {
        cout << "Your paperless billing is not valid!" << endl;
        return(0);
    } else {
        if (paperlessBilling == "Yes") {
            cost -= 3;
        }
    }

    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);
    
    cout << "Your " << kindOfPlan << " gym membership costs $" << cost << endl;
    
    return(0);
}
