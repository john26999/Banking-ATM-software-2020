// ComputerDateFunction.h (class header file)
// This function will derive the date of the computer and display it to the console and out file
// Written by author: John Wilson
// Written 29 Apr 2019

#ifndef COMPUTERDATEFUNCTION_H_INCLUDED
#define COMPUTERDATEFUNCTION_H_INCLUDED

// string months as an array with the months spelled out
std::string months[] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
// string days as an array with the weekdays spelled out
std::string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
                      "Saturday"};
//////+++++++++++Class that pulls date from the computer.++++++++++++++++++/////////////
class Date
{
   public:
        Date();             //Default Constructor with no parameters
        ~Date();            //Destructor
        void printDate(ofstream& );   //Print function to print the date

    private:                          //Private Members
        std::string month;  //Local string variable for the Months
        std::string day;    //Local string variable for the days of the week
        int date;           //Local int variable for the date
        int year;           //Local int variable for the year
};
#endif // COMPUTERDATEFUNCTION_H_INCLUDED
