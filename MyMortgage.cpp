#include "MyMortgage.h"
#include <ios>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

void MyMortgage::setLoanAmount(double loan){
    loanAmount = loan;
}
void MyMortgage::setAnnualInterestRate(double r){
    annualInterestRate = r;
}
void MyMortgage::setLength(int n){
    numberOfYears = n;
}


double MyMortgage::getMonthlyPay(){
    double powerFactor, monthlyPay;
    powerFactor = pow((1+annualInterestRate/12), numberOfYears*12);
    monthlyPay = (loanAmount*(annualInterestRate/12)*powerFactor)/(powerFactor-1);
    return monthlyPay;
}

double MyMortgage::calcTotalPay(){
    return (this->getMonthlyPay())*12*numberOfYears;
}
void MyMortgage::displayInfo(){
    
    cout << "\nLoan Amount: $" <<loanAmount <<endl;
    cout << "Annual Interest Rate: "<<annualInterestRate <<endl;
    cout << "Years to pay: " <<numberOfYears <<endl;
    cout << setprecision(2) << fixed << showpoint;
    cout << "Monthly Payment: $"<<this->getMonthlyPay() <<endl;
    cout << "Total Pay Back: $"<<this->calcTotalPay() <<endl;
    cout << endl;
}
void MyMortgage::outputPaymentSchedule(){
    ofstream outFile;
    string fileName;
    cout << "Enter output file name: ";
    getline(cin, fileName);
    outFile.open(fileName);
    double interest, contribute_to_principle, remainingBalance;
    remainingBalance = loanAmount;
    
    
    outFile << setw(4) << "Pmt#" << setw(15) << "Payment Amount" << setw(10) << "Interest"
            << setw(22) <<"Contrib to principle" << setw(20) << "Remaining balance" << endl;
    for(int i = 1; i <= numberOfYears * 12; i++){
        interest = (annualInterestRate/12)*remainingBalance;
        contribute_to_principle = this->getMonthlyPay() - interest;
       
        outFile << setprecision(2) << fixed << showpoint;
        
        outFile << setw(4) << i << setw(15) << this->getMonthlyPay() << setw(10) << interest
            << setw(22) <<contribute_to_principle << setw(20) << remainingBalance-contribute_to_principle << endl; 
        remainingBalance -= contribute_to_principle;
    }
}