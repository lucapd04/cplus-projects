/************************************************************************
                   BIRTHDAY ASSIGNMENT - BY LUCA DUARTE
                    ICS4U1 - MS. MEDD 26/04/2022
 *************************************************************************/
#include <iostream>
#include <ctime>
using namespace std;
#include <ctype.h>
#include <string.h>

int main() {

//declare variables to access date/time structure
time_t now = time(0);
int curYear, curMonth, curDay;
    tm *ltm = localtime(&now);

//save year, month, and date into int variables
curYear = 1900 + ltm->tm_year;
curMonth = 1 + ltm->tm_mon;
curDay = ltm->tm_mday;

bool valid_input = true;
string day, month, year;
char birthday[9]; //char array to store the birthdate in

while (valid_input == true) { //while loop starts here
cout<<"What day, month and year were you born in(type in DDMMYYYY, no spaces)? ";
fgets(birthday, 9, stdin); //user input which stores the birthdate into the char array
fflush(stdin);

	for (int i = 0; i < 2; i++){ //sets first two characters as the day
		day = day + birthday[i];
	}

	for (int i = 2; i < 4; i++){ //sets next pair of characters as the month
		month = month + birthday[i];
	}

	for (int i = 4; i < 8; i++){ //sets last set of characters as the birthday
		year = year + birthday[i];
	}

	//types out the day, month and year acquired from the input
	cout<<"Day: "<<day<<endl; 
	cout<<"Month: "<<month<<endl;
	cout<<"Year: "<<year<<endl;

	if (stoi(day) > curDay && stoi(month) > curMonth && stoi(year) == curYear) { //condition to check if the input comes after current date in the current year
		cout<<"This date is not available as it is in the future!"<<endl;
		day = "";
		month = "";
		year = "";
	}

	else if (stoi(year) > curYear) { //condition to check if the date is in a future year or not
		cout<<"This date is not available as it is in the future!"<<endl;
		day = "";
		month = "";
		year = "";
	}
	
	else if (stoi(month) == 2 && stoi(day) > 29 && stoi(year) % 4 == 0) { //checks if the month is february in a leap year, if so then checks if the day is over 29 or not
		cout<<"There is not more than 29 days in february at the year "<<year<<endl;
		day = "";
		month = "";
		year = "";
	}

	else if (stoi(month) == 2 && stoi(day) > 28 && stoi(year) % 4 != 0) { //checks if the month is february and not in a leap year, if so then checks if the day is over 28 or not
		cout<<"There is not more than 28 days in february at the year "<<year<<endl;
		day = "";
		month = "";
		year = "";
	}

	else if (stoi(day) <= 0 || stoi(day) > 31) { //checks if the user inputed 0 or a number over the maximum number of days in a month
		cout<<day<<" is not a valid day."<<endl;
		day = "";
		month = "";
		year = "";
	}

	else if (stoi(month) == 4 ||
			stoi(month) == 6 ||
			stoi(month) == 9 ||
			stoi(month) == 11 &&
			stoi(day) > 30) { //checks if the month has 30 days in it, if yes then checks if the day is over 30 or not
		cout<<"There is not more than 30 days in that month."<<endl;
		day = "";
		month = "";
		year = "";
	}

	else if (stoi(month) <= 0 || stoi(month) > 12) { //checks if user inputed a month that does not exist
		cout<<month<<" is not a valid month.\n"<<endl;
		day = "";
		month = "";
		year = "";
	}

	else if (stoi(year) < curYear - 120) { //checks if your age is believeable or not
		cout<<"I doubt you are over 120 years old!\n"<<endl;
		day = "";
		month = "";
		year = "";
	}

	else if (birthday == NULL) { //checks if it is NULL result or not
		cout<<"Error: reading string.\n"<<endl;
		day = "";
		month = "";
		year = "";
	}

	/*
	each
	cout<<"Error: reading string.\n"<<endl;
		day = "";
		month = "";
		year = "";
	is a code which resets the variables which form the birthday after an invalid input. After each invalid input the while-loop reaches its end and resets
	*/

	else { //condition that breaks the while-loop if the input passes all the conditions
		valid_input = false;
	}
}

cout<<"Your birthday is: "<<day<<"/"<<month<<"/"<<year<<endl; //line which types back the user's birthday

return 0;
        
}


