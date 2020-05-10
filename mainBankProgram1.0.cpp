//(1) The name of the program: Program #3 (Banking Account Balance Software)//
//(2) The name of the programmer: John Wilson//
//(3) The date of the program: 29 Apr 2019//
//(4) A brief description of the purpose of the program: Make an efficient banking software that ensures:
// no transaction is completed or process more than 5 times; limit reached shut down.
// all entries are positive
// a fee of $2.50 is added to deposit over $50
// a fee of $.25 is deducted after each withdrawal
// each transaction can be processed based on the balance
// Report negative balances; limit reached shut down services
// no more than $1000.00 is withdrawn during any daily transaction; limit reached shut down services
// Alerts the user to the number of times all transactions were completed upon exiting (remember, available balance)
// no account has more than $3495.99 in it at any given time; limit reached shut down services
// place an extra selection for user to access a statement that show date, user name, transactions and amounts.

#include <iostream>         //library that defines the standard input/output stream objects
#include <ostream>          //library that provides the standard output stream class
#include <fstream>          //library that provides file stream classes
#include <iomanip>          //library providing parametric manipulators
#include <sstream>          //library providing string stream classes
#include <ctime>            //library for definitions of functions to get and manipulate date and time information
#include <string>           //library to introduce string types, character traits and a set of converting functions
#include <cctype>           //library to use toupper function
#include <stdio.h>          //library to perform Input/Output operations


using namespace std;
#include "ComputerDateFunction.cpp"
#include "ShowMenuFunction.cpp"
#include "BankingAccountFunction.cpp"


ifstream inFile ("infoIn.txt");
ofstream outFile ("infoOut.txt");

void showMenu(ofstream &);
void introScreen(ofstream &);


//++==This is where the program lies.==++//
int main ()
{
Date a;
//ShowMenuFunction  b;
BankingAccountFunction c;
//++==These are the question strings i used to help the make the functions run a little bit more smoothly (hopefully).==++//
    char question1 [] = "What is your first name? ";
    string question2 = "What is your last name? ";
    char answer1 [25];
    string answer2;
    char question2a [] = "You have put in a negative number please try again. \n";
    string answer2a [25];
    char questionc3a [] = "Using your ATM card will cost an additional $3.00 to you transaction. \n";
    string questionc3b = "Would you like to continue? [Yes or No]? ";
    string questionc3c = "How much do you want to Withdraw from your account? \n";
    char answerc3a;
    string answerc3b;
    char questionAB [] = "You have reached your ACCOUNT BALANCE limit of $3495.99; therefore, this banking session will terminate. Thank you for believing in Thieves Bank!! \n";

//++==These name the type of variables like char, int, float.==++//
    char choice, answer, customerName, firstName [25], lastName[25];
    int option, next, totTally, t = 0, tally;
    char Y, N, y, n, YES, NO, Yes, No, yes, no, c3;
	double initialAmount, displayBalance, amount = 0.0, DA = 0.00, AA = 0.00, WA = 0.00, answer5 [5];
	double  DPL = 10000.00, DL = 1000.00, IB = 2372.36, AF = 3.00, MF = 12.50, RB = 0.00, AB = IB + RB;
//++==This is the function giving the classes a variable to identify and tie the specific class functions.==++//

//++==This is the function that prints the date at the top of the program.==++//
    a.printDate (outFile);
    introScreen (outFile);

//++==This is the beginning of the choice process for the program.==++//
        cout <<question1;
        cin  >>answer1;
        cout <<question2;
        cin  >>answer2;
        cout <<"Welcome to the Bank of Thieves "<<answer1 <<" "<< answer2<< "\n\n";

    for (tally = 1; tally < 6; tally = tally ++) //This is the beginning of the control loop that will only allow 5 transactions per session.
    {
        showMenu(outFile);
        cout << "Please enter a choice: ";
        cin>> next;
        cout << "You have a total of five transactions for this session before the program involuntarily shuts down. \n";
        cout << "You have completed " << tally <<" of 5 transactions thus far. \n";
        tally++;

//++==this is the case option string that will allow the user to choose what they want to do.==++//
        switch (next)
        {
//++==This is the deposit case and it ties to the functions within the Banking Account Class. ==++//
            case 1:
                cout << "\n [[[DEPOSIT]]] \n";
                cout << "\n How much would you like to deposit? \n";
                cin >> DA;
                if (DA < 0) //beginning of a negative number while loop.
                {
                    cout << question2a << "\n";
                }
                else if (DA > 3495.99)
                {
                    cout <<questionAB << "\n";
                }
                else if (DA < 3495.99)
                {
                    c.calcDep(DA); c.displayBalance(); a.printDate(outFile);
                    cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? Yes or No [Y/N]? \n";
                    cin >> answer;
                }

                if (answer == 'Y' && answer == 'y')
                {
                    continue;
                }

                if (answer == 'N' && answer == 'n')
                {
                    break;
                }
                break;

//++==This is the withdraw case and it ties to the functions within the Banking Account Class. ==++//
            case 2:
                cout << "\n [[[WITHDRAW]]] \n";
                cout << "\n How much would you like to withdraw? \n";
                cin >> WA;
                if (AB < WA)
                {
                cout << "This transaction exceeds the total balance you have in the account of: " <<AB<<" !!\n\n";
                cout <<"Please make another selection!!\n\n";
                break;
                };

                if (WA < 0) //beginning of a negative number while loop.
                {
                    cout << question2a << "\n\n";
                }
                else if (WA > 0 )
                {
                    c.calcWith(WA); c.displayBalance(); a.printDate(outFile);
                    cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? Yes or No [Y/N]? \n";
                    cin >> answer;
                }

                else if (answer == 'Y' && answer == 'y' && answer == 'Yes' && answer == 'YES')
                {
                    continue;
                }
                break;

//++==This is the ATM Withdraw case and it ties to the functions within the Banking Account Class. ==++//
            case 3:
                cout << "\n [[[ATM Withdraw]]] \n";
                cout <<questionc3a;
                cout <<questionc3b;
                cin >> answer;
                while (answer == 'Y' || answer == 'y') //++== beginning of the decision 'if else' statement.==++//
                {
                        cout <<questionc3c;
                        cin >> AA;

                if (AB < AA)
                {
                cout << "This transaction exceeds the total balance you have in the account of: " <<AB<<" !!\n\n";
                cout <<"Please make another selection!!\n\n";
                break;
                }

                if (AA < 0) //beginning of a negative number while loop.
                {
                    cout << question2a << "\n\n";
                }
                else if (AA > 0 )
                {
                        c.calcATM(AA); c.displayBalance(); a.printDate(outFile);
                        cin.clear();
                        cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? Yes or No [Y/N]? \n";
                        cin >> answer;
                }
                    if (answer == 'Y' && answer == 'y') //++== beginning of the decision 'if else' statement.==++//
                {
                   break;
                }
                    }
                break;

//++==This is the Banking Fees case and it ties to the functions within the Banking Account Class. ==++//
            case 4:
                cout << "\n [[[Banking Fees]]] \n";
                c.calcFees(amount); c.displayFees (); a.printDate(outFile);
                cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? Yes or No [Y/N]? \n";
                cin >> answer;
                if (answer == 'Y' && answer == 'y') //++== beginning of the decision 'if else' statement.==++//
                {
                continue;
                }
                else if (answer && 'N' || answer && 'n')
                {
                    cout << "Thank you for stopping by Thieves Bank "<< answer1<< " " << answer2 << "! \n\n";
                    cout << "We hope you have a wonderful day! \n\n";
                    continue;
                }
                break;
//++==This is the Banking balance case and it ties to the functions within the Banking Account Class. ==++//
            case 5:
                cout <<"\n [[[Banking Statement]]] \n";
                cout <<"Your banking statement is listed below "<<answer1 <<" "<<answer2 << ". \n";
                 c.calcDep(DA); c.calcWith(WA); c.calcATM(AA); c.displayFees(); c.displayBalance (); a.printDate(outFile);
                cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? Yes or No [Y/N]? \n";
                cin >> answer;
                if (answer == 'Y' && answer == 'y') //++== beginning of the decision 'if else' statement.==++//
                {
                    continue;
                }
                else if (answer == 'N' && answer == 'n')
                {
                    cout << "Thank you for stopping by Thieves Bank "<< answer1<< " " << answer2 << "! \n\n";
                    cout << "We hope you have a wonderful day! \n\n";
                }
                break;
//++==This is the Exit case and exits the choice menu. ==++//
            case 6:
                cout << "[[[Exit]]] \n";
                cout << " Are you sure you want to exit "<< answer1<< " " <<answer2 << "? Yes or No [Y/N]? \n\n";
                cin >> answer;
                 if (answer == 'Y' || answer == 'y') //++== beginning of the decision 'if else' statement.==++//
                {
                    cout << "Thank you for stopping by "<< answer1<< " " << answer2 << ". \n";
                    c.displayBalance (); a.printDate(outFile);
                    break;
                }

                else if (answer == 'N' && answer == 'n')
                {
                    continue;
                }

//++==This is the default statement case and is the statement that pops up if you make a wrong entry. ==++//
            default:
                cout << "Invalid selection. Please, try again." << endl << endl;
                break;
    }
}
        cout << answer1<< " " << answer2 << ", you have reached your session limit of five. \n";
        cout << "So 'END OF LINE' (famous quote from the movie TRON (1982), which means your session was terminated.) \n";
        cout << "Here is a summary of your transactions: \n";
        c.calcDep(DA); c.calcWith(WA); c.calcATM(AA); c.displayFees(); c.displayBalance (); a.printDate(outFile);
        outFile.close ();
        return 0;
}

void showMenu(ofstream &outFile)
{
    cout<< "Please make a choice below: \n";
    cout << "For Deposits, Enter [1]. \n";
    cout << "For Withdrawals, Enter [2]. \n";
    cout << "For ATM Withdrawals, Enter [3]. \n";
    cout << "For Banking Fees, Enter [4]. \n";
    cout << "For Banking Statement, Enter [5]. \n";
    cout << "To Exit, Enter [6]. \n\n";
}
void introScreen(ofstream &outFile)
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
