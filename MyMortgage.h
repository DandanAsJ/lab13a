#ifndef MYMORTGAGE_H
#define MYMORTGAGE_H

class MyMortgage{
    private:
        double  loanAmount;  
        double annualInterestRate;
        int numberOfYears;
        
    public:
        MyMortgage(){};
        
        void setLoanAmount(double);
        void setAnnualInterestRate(double);
        void setLength(int);
      
        double getMonthlyPay();
        
        double calcTotalPay();

        void displayInfo();
        void outputPaymentSchedule();
};
#endif