//============================================================================
// Name        : test.cpp
// Author      : Joshua Suizo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
OUTLINE:
	On the first init, this will prompt for a username-password sign in to store passwords and logins
	This will create a .txt/.bin to store profiles, then on those profiles, create a profile specific .txt/.bin for their logins
*/



/*	NOTES:
 * 		Starting to notice that it's becoming more difficult to create username-password pairs without using std::pair
 * 		Investigate if can make an array/vector of pairs
 * 		-> it is possible. try reconstructing the program to operate on an array/vector of pairs
 *
 */
#include "functions.h"

const char* searchError = "Error Code 39: Profile not Found";
const char* newInit = "No previous saves found. Creating a new page.";
const char* userNameFailedInsert = "Error 34: Username field is empty. Please re-enter a username: ";
const char* passwordFailedInsert = "Error 35: Password field is empty. Please re-enter a password: ";
const char* loginURLFailedInsert = "Error 36: Login location is empty. Please re-enter a location: ";
const char* insertFailed = "Error 69: Insertion of New Profile Information Failed";
const char* invalidChoice = "Error 1111: Invalid choice. Please re-enter: ";
const char* nullAccount = "Error 64: Profile does not exist. Please re-enter the username: ";
const char* invalidPW = "Error 65: Incorrect password. You have up to 3 attempts. Please re-enter the password: ";
const char* findAddChoice = "Error 121: Find/Add was not entered. Please enter again: ";
const char* usernameRepeat = "Error 37: Username is already in use. Please enter a new one or login: ";

int main() {

	string userPrompt;	//Should just be an insert account, find account, or delete account
	//char userPromptChar;
	string userName;
	string passWord;
	string inputString;
	string loginURL;
	fstream inputFile, outputFile;

	userPrompt = printPrompt();
	while(userPrompt != "end" || userPrompt != "End") {
		if (userPrompt == "Y" || userPrompt == "y") {
			newUser(userNameFailedInsert, passwordFailedInsert,
					loginURLFailedInsert, usernameRepeat);
			clearConsole();
			userPrompt = printPrompt();
		}
		else if (userPrompt == "N" || userPrompt == "n") {
			returningUser(userNameFailedInsert, passwordFailedInsert,
					loginURLFailedInsert, nullAccount,
					invalidPW, findAddChoice);
			clearConsole();
			userPrompt = printPrompt();
		}
		else if(userPrompt == "End" || userPrompt == "end") {
			break;
		}
		else {
			cout << invalidChoice;
			getline(cin, userPrompt);
		}
	}
	cout << "Thank you for using me. Now ending..." << endl; // prints Thank you for using me. Now ending...
	return 0;

}
