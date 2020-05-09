//(1) The name of the program: Program #2 (Banking Account Balance Software)//
//(2) The name of the programmer: John Wilson//
//(3) The date of the program: 08 Apr 2019//
//(4) A brief description of the purpose of the program: Make an efficient banking software that shows balance//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <string>
#include <stdio.h>

using namespace std;

//++==These are the string statements used for the class functions or other function in the main section.==++//
    std::string choice;

	std::string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", //++Needed for the date function to operate.++//
                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    std::string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri",    //++Needed for the date function to operate.++//
                      "Sat"};

//////+++++++++++Function pulls date from the computer.++++++++++++++++++/////////////
    class Date
    {

    private:                          //++Private Members++//
        std::string month;
        std::string day;
        int date;
        int year;

    public:                           //++Default Constructor++//

        Date()
        {
                const int BASE_YEAR = 1900;
                time_t timer;
                tm * time;
                std::time(&timer);
                time = localtime(&timer);
                date = time->tm_mday;
                month = months[time->tm_mon];
                day = days[time->tm_wday];
                year = time->tm_year + BASE_YEAR;
        }
        void printDate()
        {
            std::cout << "=+=+=+=+=+=+=+=+=+=+=+=Todays Date: "
                      << this->month << " " << this->day << " "
                      << this->date  << " " << this->year <<"=+=+=+=+=+=+=+=+=+=+=+=\n\n";
        }

        ~Date() {}                    //++Destructor
    };

//++==This is a user defined data hub that holds specific functions.==++//
    class BankingAccount
    {
//++==anything created in the public area can be used outside the class.==++//
        public:

            BankingAccount()
            {
                depAmount = 0;
                depTally = 0;
                withAmount = 0;
                withTally = 0;
                ATMAmount = 0;
                ATMFee = 3.00;
                ATMTally = 0;
                mnthFee = 12.50;
                mnthTally = 0;
                runBalance;
                totalFees = 0;
                staTally = 0;
                totTally = 0;
                acctBalance = 0;
            }
//++==all of these voids specific functions built for the program.==++//
            void initbalance(float W) {runBalance = W;}
            void calcDep (float);
            void calcWith (float);
            void calcATM (float);
            void calcFees (float);
            void calcBal (float);
            void calcMnthFee (float);
            void displayATMFee ();
            void displayFees ();
            void displayBalance ();
            void displaySummary ();
            void showMenu();
            void balAlert ();

//++==anything in this area cannot be used outside of the class.==++//
        private:

            char name;
            float runBalance = 1576.36 , totalFees, ATMAmount, ATMFee = 3.00, mnthFee = 12.50, depAmount, withAmount, acctBalance, num, num1, num2, num3;
            int depTally, withTally, ATMTally, mnthTally, staTally, totTally;

	};
//++==These functions list the instructions for later use in the main area.==++//
                void showMenu()
        {
            cout<< "Please make a choice below: \n";
            cout << "For Deposits, Enter [1]. \n";
            cout << "For Withdrawals, Enter [2]. \n";
            cout << "For ATM Withdrawals, Enter [3]. \n";
            cout << "For Banking Fees, Enter [4]. \n";
            cout << "For Banking Balance, Enter [5]. \n";
            cout << "To Exit, Enter [6]. \n\n";
            }

        void BankingAccount::calcDep(float amount)
        {
            runBalance +=amount;
            ++depTally;
            ++totTally;
        }

        void BankingAccount::calcWith (float amount)
        {
            runBalance -=amount;
            ++withTally;
            ++totTally;
        }
        void BankingAccount::calcATM(float amount)
        {
            runBalance -=amount - ATMFee;
            ++ATMTally;
            ++totTally;
        }

        void BankingAccount::calcMnthFee(float amount)
        {
            runBalance -=amount - mnthFee;
            ++mnthTally;
            ++totTally;
        }

        void BankingAccount::calcFees(float amount)
        {
            mnthFee += (int (depTally));
            ATMFee += (int (ATMTally));

            cout << endl  << endl << "Bank fees include: " << endl;
            cout << "$12.50 Monthly Banking Fee." << endl;
            cout << "$3.00 ATM Fee." << endl << endl;

            cout << "So far, you've made " << depTally << " deposits, in the amount of $" << depAmount << "." << endl;
            cout << "You've made " << withTally << " check withdrawals, in the amount of $" << withAmount << "." << endl;
            cout << "You've made " << ATMTally << " ATM withdrawals, ATM Fees in the amount of $ " << ATMFee << "." << endl;
            cout << "You've made " << mnthTally << " Paid monthly banking fees, in the amount of $ " << mnthFee << "." <<endl;

            totalFees =+ ATMFee + mnthFee + depAmount +withAmount;
            cout << "In total, you've made " << totTally << " transactions, amounting in $" << totalFees << " in banking fees." << endl << endl;
        }
        void BankingAccount::displayFees()
        {
            cout << "Total Banking Fee Balance: " << setprecision(2) << fixed << runBalance << endl << endl;
        }
        void BankingAccount::displayBalance()
        {
            cout << "Total Balance: " << setprecision(2) << fixed << runBalance << endl << endl;
        }
        void BankingAccount::displaySummary()
        {
            cout << "Thank you for stopping by Thieves Bank! Here is a summary of your transactions." <<endl;
            cout << "you were deduced " <<totTally<< " in bank fees.";
        }
        void BankingAccount::balAlert()
        {
        for (num = 1000; num <= 1000; num++)
            cout << "Your account balance is below $1000.00. \n";
            cout <<"Please make another choice. \n";

        for (num1 = 500; num1 <= 500; num1++)
            cout << "Your account balance is below $500.00. \n";
            cout <<"Please make another choice. \n";

        for (num2 = 250; num2 <= 250; num2++)
            cout <<"Your account balance is below $250.00. \n";
            cout <<"Please make another choice. \n";

        for (num3 = 0; num3 <= 0; num3++)
            cout <<"Your account balance is below $0. \n";
            cout <<"Please make another choice. \n";
        }

//++==This is where the program lies.==++//
int main ()
{

//++==These are the question strings i used to help the make the functions run a little bit more smoothly (hopefully).==++//
    char question1 [] = "What is your first name? ";
    string question2 = "What is your last name? ";
    char answer1 [25];
    string answer2;
    string questionc3c = "How much do you want to Withdraw from your account? \n";
    char answerc3a;
    string answerc3b;

//++==These name the type of variables like char, int, float.==++//
    char choice, answer, customerName, firstName [25], lastName[25];
    int option, next;
    char Y, N, y, n, YES, NO, Yes, No, yes, no;
	float initialAmount, displayBalance, num, num1, num2, num3;
	float amount, runBalance;
//++==This is the function giving the classess a variable inorder to identify and tie the specific class functions.==++//
        Date d;
        BankingAccount b;
//++==This is the function that prints the date at the top of the program.==++//
        d.printDate();
//++==This is the introduction screen I tried to make pleasing to the eye.==++//
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout<<"++====================Welcome to the Bank of Thieves====================++\n";
        cout<<"++========Where paying loans is as easy as robbing your neighbor========++\n";
        cout<<"++======================================================================++\n";
        cout<<"++==If you need to contact us please cal or email us at the info below==++\n";
        cout<<"++==========Phone(555)867-9305==email-Thieves@stealurmoney.com==========++\n";
        cout<<"++======================================================================++\n";
        cout<<"++====Please follow the instructions on the next screen to continue=====++\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

//++==This is the beginning of the choice process for the program.==++//
        cout <<question1;
        cin  >>answer1;
        cout <<question2;
        cin  >>answer2;
        cout <<"Welcome to the Bank of Thieves "<<answer1 <<" "<< answer2<< "\n\n";

    do //++==This is the beginning of a loop statement for the choice menu. I did this to help the user make a yes or no decision as to make another transaction.==++//
    {
        showMenu ();
        cout << "Please enter a choice: ";
        cin>> next;
//++==this is the case option string that will allow the user to choose what they want to do.==++//
            switch (next)
            {
//++==This is the deposit case and it ties to the functions within the Banking Account Class. ==++//
                case 1:
                    cout << "\n [[[DEPOSIT]]] \n";
                    cout << "\n How much would you like to deposit? "<< answer1<< " " << answer2 << "\n";
                    cin >> amount;
                    b.calcDep(amount); b.displayBalance();
                    cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? [Y/N]? \n";
                    cin >> answer;
                    if (answer == 'Y' || answer == 'y' || answer == 'Yes' || answer == 'YES')
                    {
                        break;
                    }
                break;

//++==This is the withdraw case and it ties to the functions within the Banking Account Class. ==++//
                case 2:
                    cout << "\n [[[WITHDRAW]]] \n";
                    cout << "\n How much would you like to withdraw? "<< answer1<< " " << answer2 << "\n";
                    cin >> amount;
                    b.calcWith(amount); b.displayBalance();

                    if (b.acctBalance == 1000.00, b.acctBalance <= 1000.00, b.acctBalance++)
                        cout << "Your account balance is below $1000.00." <<"Please make another choice. \n";

                    else if (num1 == 500.00, num1 <= 500.00, num1++)
                        cout << "Your account balance is below $500.00." <<"Please make another choice. \n";

                    else if (num2 == 250.00, num2 <= 250.00, num2++)
                        cout <<"Your account balance is below $250.00." <<"Please make another choice. \n";

                    else if (num3 == 0.00, num3 <= 0.00, num3++)
                        cout <<"Your account balance is below $0." <<"Please make another choice. \n";
                        break;

                    cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? [Y/N]? \n";
                    cin >> answer;
                    if (answer == 'Y' || answer == 'y' || answer == 'Yes' || answer == 'YES') //++== beginning of the decision 'if else' statement.==++//
                    {
                        break;
                    }
                break;

//++==This is the ATM Withdraw case and it ties to the functions within the Banking Account Class. ==++//
                case 3:
                    cout << "\n [[[ATM Withdraw]]] \n";
                    cout <<questionc3c << answer1<< " " << answer2 << "\n";
                    cin >> amount;
                    b.calcATM(amount); b.displayBalance();
                    cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? [Y/N]? \n";
                    cin >> answer;
                    if (answer == 'Y' || answer == 'y' || answer == 'Yes' || answer == 'YES') //++== beginning of the decision 'if else' statement.==++//
                    {
                       break;
                    }
                break;

//++==This is the Banking Fees case and it ties to the functions within the Banking Account Class. ==++//
                case 4:
                    cout << "\n [[[Banking Fees]]] \n";
                    cout <<"\n Here is the list of your Banking Fees "<< answer1<< " " << answer2 << "\n";
                    b.calcFees(amount); b.displayFees ();
                    cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? [Y/N]? \n";
                    cin >> answer;
                    if (answer == 'Y' || answer == 'y' || answer == 'Yes' || answer == 'YES') //++== beginning of the decision 'if else' statement.==++//
                    {
                    break;
                    }
                break;

//++==This is the Banking balance case and it ties to the functions within the Banking Account Class. ==++//
                case 5:
                    cout <<"\n [[[Banking Balance]]] \n";
                    cout <<" Here is your Banking Fees "<< answer1<< " " << answer2 << "\n";
                    b.displayBalance();
                    cout << "Would you like to make another transaction "<< answer1<< " " << answer2 << "? [Y/N]? \n";
                    cin >> answer;
                    if (answer == 'Y' || answer == 'y' || answer == 'Yes' || answer == 'YES') //++== beginning of the decision 'if else' statement.==++//
                    {
                        break;
                    }
                 break;
//++==This is the Exit case and exits the choice menu. ==++//
                case 6:
                    cout << "[[[Exit]]] \n";
                    cout << "Thank you for stopping by "<< answer1<< " " << answer2 << "! Here is a summary of your transactions. \n";
                    b.displayBalance ();
                break;

//++==This is the default statement case and is the statement that pops up if you make a wrong entry. ==++//
                default:

                    cout << "Invalid selection. Please, try again." << endl << endl;
        }

	}while (answer != 'N'); //++==This if the end of the loop statement.==++//


        (next == 'Y' || next == 'y');


	if (next == 'N' || next == 'n')
	{
		cout << "Report ending balance, total deposits, total withdrawals, and total fees.";
	}
	return 0;
            }

