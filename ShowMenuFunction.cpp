#include "ShowMenuFunction.h"

//ShowMenuFunction::ShowMenuFunction()
//{
//    //ctor
//}
//
//ShowMenuFunction::~ShowMenuFunction()
//{
//    //dtor
//}
//
//ShowMenuFunction::ShowMenuFunction(const ShowMenuFunction& other)
//{
//    //copy ctor
//}
//
//ShowMenuFunction& ShowMenuFunction::operator=(const ShowMenuFunction& rhs)
//{
//    if (this == &rhs) return *this; // handle self assignment
//    //assignment operator
//    return *this;
//}

void ShowMenuFunction::showMenu(ofstream &outFile)
{
    cout<< "Please make a choice below: \n";
    cout << "For Deposits, Enter [1]. \n";
    cout << "For Withdrawals, Enter [2]. \n";
    cout << "For ATM Withdrawals, Enter [3]. \n";
    cout << "For Banking Fees, Enter [4]. \n";
    cout << "For Banking Statement, Enter [5]. \n";
    cout << "To Exit, Enter [6]. \n\n";
}
void ShowMenuFunction::PrintIntroScreen(ofstream &outFile)
{
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++++++++++++++  ++++++++++++++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++++++++++          ++++++++++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++++++                  ++++++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++                          ++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++                                  ++++++++++++++++++++\n";
    cout<<"++++++++++++++++                                          ++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<"++====================Welcome to the Bank of Thieves====================++\n";
    cout<<"++========Where paying loans is as easy as robbing your neighbor========++\n";
    cout<<"++======================================================================++\n";
    cout<<"++==If you need to contact us please cal or email us at the info below==++\n";
    cout<<"++==========Phone(555)867-9305==email-Thieves@stealurmoney.com==========++\n";
    cout<<"++======================================================================++\n";
    cout<<"++====Please follow the instructions on the next screen to continue=====++\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++                                          ++++++++++++++++\n";
    cout<<"++++++++++++++++++++                                  ++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++                          ++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++++++                  ++++++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++++++++++          ++++++++++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++++++++++++++  ++++++++++++++++++++++++++++++++++++\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    outFile<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++++++++++++++  ++++++++++++++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++++++++++          ++++++++++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++++++                  ++++++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++                          ++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++                                  ++++++++++++++++++++\n";
    outFile<<"++++++++++++++++                                          ++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    outFile<<"++====================Welcome to the Bank of Thieves====================++\n";
    outFile<<"++========Where paying loans is as easy as robbing your neighbor========++\n";
    outFile<<"++======================================================================++\n";
    outFile<<"++==If you need to contact us please cal or email us at the info below==++\n";
    outFile<<"++==========Phone(555)867-9305==email-Thieves@stealurmoney.com==========++\n";
    outFile<<"++======================================================================++\n";
    outFile<<"++====Please follow the instructions on the next screen to continue=====++\n";
    outFile<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++                                          ++++++++++++++++\n";
    outFile<<"++++++++++++++++++++                                  ++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++                          ++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++++++                  ++++++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++++++++++          ++++++++++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++++++++++++++  ++++++++++++++++++++++++++++++++++++\n";
    outFile<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}


