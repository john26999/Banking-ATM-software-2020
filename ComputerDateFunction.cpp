// This function will derive the date of the computer and display it to the console and out file
// Written by author: John Wilson
// Written 29 Apr 2019

#include <iostream>
#include <fstream>
#include <iomanip>
#include "ComputerDateFunction.h"


using namespace std;

//Consructor with no parameters
//Pre: None
//Post: will grab the date and time of the computer
Date::Date()
{
    const int BASE_YEAR = 1900;                 //sets int Base_YEAR as const and initialize.
    time_t timer;
    tm * time;                                  //declares time as a pointer variable
    std::time(&timer);                          //sets time pointer to be used as reference
    time = localtime(&timer);                   //sets equal to localtime with parameter passed by reference
    date = time->tm_mday;                       //sets private date eqaul to time-> tm_mday
    month = months[time->tm_mon];               //sets private month equal to array months [time->tm_mon]
    day = days[time->tm_wday];                  //sets private days equal to array days [time->tm_wday]
    year = time->tm_year + BASE_YEAR;           //sets private year equal to year time->tm_mon + BASE_YEAR
}

// Destructor
//Pre: None
//Post: will deallocate object memory.
Date::~Date()
{
    //destroys object();               // calls private destroy Object function
    //std::cout << setw(32) << "Object (Date) is destroyed..." << endl << endl; // demonstration only
}

//Prints out date to the console and outFile
//Pre: declares ofstream outFile by reference
//Post: Function will prints date to the console and outFile
void Date::printDate(ofstream& outFile)
{
    cout << setfill(' ')
         << right
         << setw(21) << "Current Date: "
         << setw(2) << this->month << ""
         << setw(2) << this->date << ", "
         << setw(2)<< this->year
         <<"\n\n";
    outFile << setfill(' ')
         << right
         << setw(21) << "Current Date: "
         << setw(2) << this->month << " "
         << setw(2) << this->date << ", "
         << setw(2)<< this->year
         <<"\n\n";
}
