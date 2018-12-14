/*Author: Alex Ly 100548033
Feb 20 2015
 Lab #5
This program prompts the user for either a month or a year calendar.
Regardless, the user is asked for a year and if the user picked month
calendar, they are prompted for a month. The program would then display the
calendar of that month in the year the user picked. If the user picked a
year calendar, the program would display the calendar of the months of the
year that the user picked
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
using std::vector;

void printYear(int year);

void printMonth(int month, int year);

void printDayOfWeek();

int main(){

	int choice;
	int month;
	int year;
	cout << "Do you want a month calendar or a year calendar?" << endl;
	cout << "Enter 1 for month and 2 for year" << endl;
	cin >> choice;
	if (choice == 1){
		cout << "Enter month in number form: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		cout << endl;
		if (month < 1 || month > 12){
			cout << "Invalid month" << endl;
		} else {
			printMonth(month, year);
		}
	} else if (choice == 2){
		cout << "Enter year: ";
		cin >> year;
		printYear(year);
	} else {
		cout << "Invalid" << endl;
	}
	return 0;
}

/*
printDayOfWeek

this function prints out the weekdays of the calendar
*/

void printDayOfWeek(){
	vector<string> dayOfWeek;
	dayOfWeek.push_back("Su ");
	dayOfWeek.push_back("M  ");
	dayOfWeek.push_back("T  ");
	dayOfWeek.push_back("W  ");
	dayOfWeek.push_back("Th ");
	dayOfWeek.push_back("F  ");
	dayOfWeek.push_back("Sa ");

  for (int i=0;i<dayOfWeek.size();i++){
		cout << dayOfWeek[i];
	}
	cout << endl;
}

/*
printMonth

this function will print out the calendar of the specified month

@param month, the month
@param year, the year
*/

void printMonth(int month, int year){
	int startMonth;
	int calendarMonth;
	int day;

	if (month == 1 && year % 4 == 0 && year % 100 != 0 ||//leap year
		month == 1 && year % 400 == 0){
		calendarMonth = 6;
		day = 31;
	} else if (month == 2 && year % 4 == 0 && year % 100 != 0 ||
		month == 2 && year % 400 == 0){//leap year
		calendarMonth = 2;
		day = 29;
	} else if (month == 1 && year % 4 != 0 || month == 1 && year % 4 == 0 &&
		year % 100 == 0 && year % 400 != 0){//not a leap year
		calendarMonth = 0;
		day = 31;
	} else if (month == 2 && year % 4 != 0 || month == 2 && year % 4 == 0 &&
		year % 100 == 0 && year % 400 != 0){//not a leap year
		calendarMonth = 3;
		day = 28;
	} else if (month == 3){
		calendarMonth = 3;
		day = 31;
	} else if (month == 4){
		calendarMonth = 6;
		day = 30;
	} else if (month == 5){
		calendarMonth = 1;
		day = 31;
	} else if (month == 6){
		calendarMonth = 4;
		day = 30;
	} else if (month == 7){
		calendarMonth = 6;
		day = 31;
	} else if (month == 8){
		calendarMonth = 2;
		day = 31;
	} else if (month == 9){
		calendarMonth = 5;
		day = 30;
	} else if (month == 10){
		calendarMonth = 0;
		day = 31;
	} else if (month == 11){
		calendarMonth = 3;
		day = 30;
	} else if (month == 12){
		calendarMonth = 5;
		day = 31;
	}

	int century = year / 100;

	if ((century) % 4 == 0){ //determining what day the month starts at
		startMonth = (1 + calendarMonth + (year % 100) + (year % 100 / 4) + 6) % 7;
	} else if ((century - 1) % 4 == 0){
		startMonth = (1 + calendarMonth + (year % 100) + (year % 100 / 4) + 4) % 7;
	} else if ((century - 2) % 4 == 0){
		startMonth = (1 + calendarMonth + (year % 100) + (year % 100 / 4) + 2) % 7;
	} else if ((century - 3) % 4 == 0){
		startMonth = (1 + calendarMonth + (year % 100) + (year % 100 / 4)) % 7;
	}

	vector <int> days;
	for (int i = 0; i< startMonth + day; i++){
		days.push_back(0);
	}
	for (int i = 0; i< startMonth + day; i++){
		if (i < startMonth){
			days[i] = 0;
		} else {
			days[i] = i - startMonth + 1;
		}
	}

	if (month == 1){
		cout << "January ";
	} else if (month == 2){
		cout << "February ";
	} else if (month == 3){
		cout << "March ";
	} else if (month == 4){
		cout << "April ";
	} else if (month == 5){
		cout << "May ";
	} else if (month == 6){
		cout << "June ";
	} else if (month == 7){
		cout << "July ";
	} else if (month == 8){
		cout << "August ";
	} else if (month == 9){
		cout << "September ";
	} else if (month == 10){
		cout << "October ";
	} else if (month == 11){
		cout << "November ";
	} else if (month == 12){
		cout << "December ";
	}

	cout << year << endl;

	cout << endl;

	printDayOfWeek();
	for (int i = 0; i<startMonth + day; i++){
		if (days[i] == 0){
			cout << "   ";
		}
		if (i == 6 || i == 13 || i == 20 || i == 27 || i == 34){//end of week
			cout << days[i] << endl;
		}
		if (days[i] > 0 && days[i] < 10 && i != 6 && i != 13 && i != 20 && i != 27
			&& i != 34){
			cout << days[i] << "  ";
		}
		if (days[i] > 9 && i != 6 && i != 13 && i != 20 && i != 27 && i != 34){
			cout << days[i] << " ";
		}
	}
	cout << endl;
}

/*
printYear

this function will print out the calendar of the specified year (all months)

@param year, the year
*/

void printYear(int year){
	int month = 1;
	while (month < 13){//prints every month of the year
		printMonth(month, year);
		cout << endl;
		month++;
	}
}
