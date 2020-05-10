#include "BankingAccountFunction.h"

//BankingAccountFunctionFunction::BankingAccountFunctionFunction()
//{
//    //ctor
//}
//
//BankingAccountFunctionFunction::~BankingAccountFunctionFunction()
//{
//    //dtor
//}
//
//BankingAccountFunctionFunction::BankingAccountFunctionFunction(const BankingAccountFunctionFunction& other)
//{
//    //copy ctor
//}
//
//BankingAccountFunctionFunction& BankingAccountFunctionFunction::operator=(const BankingAccountFunctionFunction& rhs)
//{
//    if (this == &rhs) return *this; // handle self assignment
//    //assignment operator
//    return *this;
//}

void BankingAccountFunction::calcDep(double DA)
{
    if (DA <= 50.00)
    {
        AB += DA;
        cout << "You made a deposit of: (+)$"<< DA << "\n";
        ++depTally;
        ++totTally;
    }
    else if (DA > 50.00)
    {
       AB += DA - DF;
        cout << "You made a deposit of: (+)$"<< DA << "\n";
        cout << "and a deposit fee(s) of (-)$" << DF << " was subtracted from the account balance because it was over $50.00. \n\n";
        ++depTally;
        ++totTally;
    }
}

void BankingAccountFunction::calcWith (double WA)
{
    AB -= WA + WF;
    cout << "Withdrawal of: (-)$"<< WA <<"\n";
    cout << "Plus a withdrawal fee of: (-)$"<<WF<<"\n";
    ++withTally;
    ++totTally;
    ++WA;

    if (AB < 999.99 && AB > 500.00)
    {
        cout << "Your account balance is below $1000.00. \n";
    }

    else if (AB < 499.99 && AB > 250.00)
    {
        cout << "Your account balance is below $500.00. \n";
    }

    else if (AB < 249.99 && AB > .01)
    {
        cout <<"Your account balance is below $250.00. \n";
    }

    else if (AB == 0)
    {
        cout <<"Your account balance is below $0 and therefore broke. \n";
    }
}

void BankingAccountFunction::calcATM(double AA)
{
    AB -= AA + AF;
    cout << "ATM Withdraw (-) of: $"<< AA <<"\n";
    ++ATMTally;
    ++totTally;

     if (AB < 999.99 && AB > 500.00)
    {
        cout << "Your account balance is below $1000.00. \n";
    }

    else if (AB < 499.99 && AB > 250.00)
    {
        cout << "Your account balance is below $500.00. \n";
    }

    else if (AB < 249.99 && AB > .01)
    {
        cout <<"Your account balance is below $250.00. \n";
    }

    else if (AB == 0)
    {
        cout <<"Your account balance is below $0 and therefore broke. \n";
    }
}

void BankingAccountFunction::calcMnthFee(double MA)
{
    AB -= MA + MF;
    cout << "ATM Withdraw (-) of: $"<< MA <<"\n\n";
    ++mnthTally;
    ++totTally;

     if (AB < 999.99 && AB > 500.00)
    {
        cout << "Your account balance is below $1000.00. \n";
    }

    else if (AB < 499.99 && AB > 250.00)
    {
        cout << "Your account balance is below $500.00. \n";
    }

    else if (AB < 249.99 && AB > .01)
    {
        cout <<"Your account balance is below $250.00. \n";
    }

    else if (AB == 0)
    {
        cout <<"Your account balance is below $0 and therefore broke. \n";
    }
}

void BankingAccountFunction::calcFees(double amount)
{
    mnthFee += (int (depTally));
    ATMFee += (int (ATMTally));

    cout << endl  << endl << "Bank fees include: " << endl;
    cout << "$12.50 Monthly Banking Fee." << endl << endl;
    cout << "$3.00 ATM Fee." << endl << endl;
    cout << "$2.20 Fee for deposits over $50." << endl << endl;
    cout << "$0.25 Fee for each withdrawal." << endl << endl;
    cout << "You've made " << depTally << " deposit(s), in the amount of $" << DA <<", and recurring deposit(s) fees in the amount of $"<< DF << " for your deposit(s) over $50.00." << endl;
    cout << "You've made " << withTally << " withdrawal(s), in the amount of $" << WA << ", and recurring withdrawal(s) fees in the amount of $"<< WF << " " << endl;
    cout << "You've made " << ATMTally << " ATM withdrawal(s), in the amount of $" << AA << " with an additional ATM Fee(s) in the amount of $ " << AF << "." << endl;
    cout << "You've made " << mnthTally << " paid monthly banking fee(s), in the amount of $ " << MF << "." <<endl;
    cout << "In total banking fee(s), you've made " << totTally << " transaction(s), amounting in banking fee(s) of $" << totalFees << "." << endl << endl;
    totalFees += AF + MF + WF +DF;
}

void BankingAccountFunction::displayFees()
{
    cout << "Your Monthly Banking Fees are listed below: \n\n";
    cout << "Total Monthly Banking Fee is $" << MF << "." << endl;
    cout << "Total Deposit Fees are $" << DF << " if deposit is over $50." << endl;
    cout << "Withdraw Fees are $" << WF << "." << endl;
    cout << "ATM Fees are: $"<< AF << " for each ATM withdraw." << endl;

}
void BankingAccountFunction::displayBalance()
{
    cout << "New Account Balance is: " << AB << endl << endl;

    if (AB < 999.99 && AB > 500.00)
    {
        cout << "Your account balance is below $1000.00. \n";
    }

    else if (AB < 499.99 && AB > 250.00)
    {
        cout << "Your account balance is below $500.00. \n";
    }

    else if (AB < 249.99 && AB > .01)
    {
        cout <<"Your account balance is below $250.00. \n";
    }

    else if (AB == 0)
    {
        cout <<"Your account balance is below $0 and therefore broke. \n";
    }
}

void BankingAccountFunction::displaySummary()
{
    cout << "Thank you for stopping by Thieves Bank! Here is a summary of your transactions." <<endl;
    cout << "you were deduced " <<MF<< " in bank fees.";
}
