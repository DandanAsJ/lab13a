#include "MyMortgage.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    MyMortgage *mortgage = new MyMortgage();
    double loan, interest;
    int years;
    char answer;

    cout << "Enter the amount of your loan: ";
    cin >> loan;
    mortgage->setLoanAmount(loan);
    
    cout << "Enter the annual interest rate in decimal form(example: 0.075): ";
    cin >> interest;
    mortgage->setAnnualInterestRate(interest);
   
    cout << "Enter the length of the loan in years: ";
    cin >> years;
    cin.ignore();
    mortgage->setLength(years);
    
    mortgage->outputPaymentSchedule();
    
    mortgage->displayInfo();

    cout << "Do you wish to process another loan?(answer Y for yes, N for no) ";
    cin >> answer;
    
    while(answer == 'Y' || answer == 'y'){
        
        cout << "Enter the amount of your loan: ";
        cin >> loan;
        mortgage->setLoanAmount(loan);
        cout << "Enter the annual interest rate in decimal form(example: 0.075): ";
        cin >> interest;
        mortgage->setAnnualInterestRate(interest);
        cout << "Enter the length of the loan in years: ";
        cin >> years;
        cin.ignore();
        mortgage->setLength(years);

        mortgage->outputPaymentSchedule();
        mortgage->displayInfo();

        cout << "Do you wish to process another loan?(answer Y for yes, N for no) ";
        cin >> answer;
        
    }
    delete mortgage;
    mortgage = nullptr;

    return 0;
}