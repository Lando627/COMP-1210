/* FILE NAME: project1_Holloway_lah0084.cpp
* AUTHOR: Landon Holloway (lah0084)
 * Compiled in AU Terminal by g++ project1_Holloway_lah0084.cpp
 * Follow with ./a.out command which brings you to user input. 
 * I spoke with Thomas Jackson in the class about currentMonth implementation. 
 * I used a google search to learn some of the language of C++ since I'm not super familiar with it. 
 * 
 */
 
#include <iostream>
using namespace std;
 
int main() {
 // VARIABLE INITIALIZATION
   double loan, interestRate, monthlyPaid, monthlyInterest, principal;
   double interestTotal = 0.0;
   double interestRateC; 
   int currentMonth = 0;
  
 // CURRENCY FORMATTING
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
  
 // USER INPUT
 // NOTE: For valid input, the loan, interest, and monthly payment must
 // be positive. The monthly payment must also be large enough to
 // terminate the loan.
   cout << "\nLoan Amount: ";
   cin >> loan;
   while (loan <= 0) {
      cout << "\nLoan Amount must be a positive value. \n\nLoan Amount: ";
      cin >> loan;
   }
 
   cout << "Interest Rate (% per year): ";
   cin >> interestRate;
   while (interestRate <= 0) { 
   cout << "\nInterest rate must be a positive value. \n\nInterest Rate (% per year): ";
   cin >> interestRate;
   }
 
 
 
 // GET PROPER INTEREST RATES FOR CALCULATIONS
   interestRate /= 12;
   interestRateC = interestRate / 100;
   cout << "Monthly Payments: ";
   cin >> monthlyPaid;
   while (monthlyPaid <= 0) {
      cout << "\nMonthly payment must be a positive value and large enough to pay off the loan. \n\nMonthly Payments: ";
      cin >> monthlyPaid;
   }
   
   if (loan * (1 + interestRateC) < monthlyPaid) {
      monthlyPaid = loan * (1 + interestRateC);

   }
 
 cout << endl;
  
 // AMORTIZATION TABLE
   cout << "*****************************************************************\n"
      << "\tAmortization Table\n"
      << "*****************************************************************\n"
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
 
 // LOOP TO FILL TABLE
   while (loan > 0) {
      monthlyInterest = loan * interestRateC;
      principal = monthlyPaid - monthlyInterest;
      interestTotal += monthlyInterest;
      loan -= principal; 
      cout << ++currentMonth << "\t$" << loan;
      
      if (loan < 1000) cout << "\t";
      cout << "\t$" << monthlyPaid << "\t" << interestRate << "\t$";
      cout << monthlyInterest << "\t\t$" << principal << endl;
   }
   cout << "****************************************************************\n";
   cout << "\nIt takes " << currentMonth << " months to pay off "
      << "the loan.\n"
      << "Total interest paid is: $" << interestTotal;
   cout << endl << endl; 
   return 0;
}