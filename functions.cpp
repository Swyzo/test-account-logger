#include "functions.h"

void clearCin () {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void clearConsole() {
	for (int i = 0; i <= 50; i++) {
		cout << endl;
	}
}

bool lengthValidate (string entry) {
	if (entry.length() == 0) {
		return false;
	}
	return true;
}

void newUser(const char* userNameFailedInsert, const char* passwordFailedInsert,
		const char* loginURLFailedInsert, const char* usernameRepeat) {

	string userName, passWord, loginURL, inputString;
	fstream outputFile, inputFile;
	char userPromptChar;
	vector<string>previousUsernames;

	inputFile.open("accounts.txt", ios::in);
	getline(inputFile, inputString, '\t');
	previousUsernames.push_back(inputString);

	while(userPromptChar != 'N' || userPromptChar != 'n') {
		cout << endl << "Please enter user name: ";
		getline(cin, userName);

		while(!inputFile.eof()) {
			getline(inputFile, inputString, '\n');
			getline(inputFile, inputString, '\t');
			previousUsernames.push_back(inputString);
		}//while loop to create a log of usernames that are registered.

		while(find(previousUsernames.begin(), previousUsernames.end(), userName) !=
				previousUsernames.end()) {
			cout << usernameRepeat;
			getline(cin, userName);
		}//while loop to make sure of no duplicate entries of new users.


		while(lengthValidate(userName) != true) {
			cout << userNameFailedInsert;
			getline(cin, userName);
			lengthValidate(userName);
		}//While loop to check length of userName, throw error if empty

		inputFile.close();

		cout << endl << "Please enter the password: ";
		getline(cin, passWord);

		while(lengthValidate(passWord) != true) {
			cout << passwordFailedInsert;
			getline(cin, passWord);
			lengthValidate(passWord);
		}//while loop to check length of password, throw error if empty

		//"Clear" the console for "security"
		clearConsole();

		outputFile.open("accounts.txt", ios::app);
		outputFile << userName << '\t' << passWord << endl;
		outputFile.close();

		//Create a unique profile.txt to hold that profile's logins
		string AccountFile = userName + ".txt";
		outputFile.open(AccountFile, ios::out);

		cout << "Enter where this login is used: ";
		getline(cin, loginURL);

		while(lengthValidate(loginURL) != true) {
			cout << loginURLFailedInsert;
			getline(cin, loginURL);
			lengthValidate(loginURL);
		}//while loop to check loginURL length, throw error if empty

		cout << "Enter your first log-in username: ";
		getline(cin, userName);

		while(lengthValidate(userName) != true) {
			cout << userNameFailedInsert;
			getline(cin, userName);
			lengthValidate(userName);
		}//while loop to check userName length, throw error if empty

		cout << "Enter the password for the username " << userName << ": ";
		getline(cin, passWord);

		while(lengthValidate(passWord) != true) {
			cout << passwordFailedInsert;
			getline(cin, passWord);
			lengthValidate(passWord);
		}//while loop to check password length, throw error if empty

		//Send the inputed data to the profile.txt
		//Format: URL, username, password
		outputFile << loginURL << '\t' << userName << '\t' << passWord << endl;

		//check if the user is done inserting logins or not
		cout << "Do you need to enter a new login? (Y/N): ";
		cin >> userPromptChar;
		clearCin();

		//bound check for finish adding log-ins
		if (userPromptChar == 'n' || userPromptChar == 'N') {
			break;
		}//if for bound check for add-action termination
	}//while loop to check if the user is done adding new logins or not

	//Close the profile.txt
	outputFile.close();
}//New User Routine

void returningUser(const char* userNameFailedInsert, const char* passwordFailedInsert,
		const char* loginURLFailedInsert, const char* nullAccount,
		const char* invalidPW, const char* findAddChoice) {
	string userName, passWord, loginURL, inputString, userPrompt;
	fstream outputFile, inputFile;
	char userPromptChar;
	vector<string>previousUsernames;
	vector<string>previousPasswords;

	inputFile.open("accounts.txt", ios::in);
	getline(inputFile, inputString, '\t');
	previousUsernames.push_back(inputString);
	getline(inputFile, inputString, '\n');
	previousPasswords.push_back(inputString);

	while(!inputFile.eof()) {
		getline(inputFile, inputString, '\t');
		previousUsernames.push_back(inputString);
		getline(inputFile, inputString, '\n');
		previousPasswords.push_back(inputString);
	}//while loop to create a log of usernames that are registered.

	for(unsigned int i= 0; i < previousPasswords.size(); i++) {
		cout << previousPasswords[i] << endl;
	}

	cout << endl << "Please enter your user name: ";
	getline (cin, userName);

	while (lengthValidate(userName) != true) {
		cout << userNameFailedInsert;
		getline(cin, userName);
		lengthValidate(userName);
	}//while loop to check username length, throw error if empty.

	//If the user is in the inputString, get their password.
	if (find(previousUsernames.begin(), previousUsernames.end(), userName) !=
			previousUsernames.end()) {
		cout << "Please enter " << userName << "'s password: ";
		getline(cin, passWord);

		while (lengthValidate(passWord) != true) {
			cout << passwordFailedInsert;
			getline(cin, passWord);
			lengthValidate(passWord);
		}

//		getline(inputFile, inputString, '\n');
		if (find(previousPasswords.begin(), previousPasswords.end(), passWord) !=
				previousPasswords.end()) {
			inputFile.close();
			inputFile.open(userName+".txt", ios::in);

			cout << "Welcome back, " << userName << "." << endl;
			cout << "Are you here to find or add a new login?: ";
			getline(cin, userPrompt);

			if (userPrompt == "add" || userPrompt == "Add") {
				while(userPromptChar != 'N' || userPromptChar != 'n') {
					cout << "Enter where this login is used: ";
					getline(cin, loginURL);

					while(lengthValidate(loginURL) != true) {
						cout << loginURLFailedInsert;
						getline(cin, loginURL);
						lengthValidate(loginURL);
					}

					cout << "Enter your first log-in username: ";
					getline(cin, userName);

					while(lengthValidate(userName) != true) {
						cout << userNameFailedInsert;
						getline(cin, userName);
						lengthValidate(userName);
					}

					cout << "Enter the password for the username " << userName << ": ";
					getline(cin, passWord);

					while(lengthValidate(passWord) != true) {
						cout << passwordFailedInsert;
						getline(cin, passWord);
						lengthValidate(passWord);
					}//while loop to check if the password length is not empty

					outputFile << loginURL << '\t' << userName << '\t' << passWord << endl;
					cout << "Do you need to enter a new login? (Y/N): ";
					cin >> userPromptChar;
					clearCin();

					if (userPromptChar == 'n' || userPromptChar == 'N') {
						break;
					}//check if user is done with adding logins or not
				}//while the user is not done adding logins
			}//if the user chose to add new logins
			else if (userPrompt == "find" || userPrompt == "Find") {
				cout << "Please enter the location where the login is used: ";
				getline(cin, loginURL);

				while(!inputFile.eof()) {
					getline(inputFile, inputString, '\t');
					if (inputString == loginURL) {
						getline(inputFile, inputString, '\n');
						break;
					}
				}
				cout << "Username/Password" << endl;
				cout << "=================" << endl;
				cout << inputString << endl;
			}//if the user chose to find a username-login pair
			else {
				cout << findAddChoice;
				getline(cin, userPrompt);

				while((userPrompt != "find" || userPrompt != "Find") || (userPrompt != "add" || userPrompt != "Add")) {
					cout << findAddChoice;
					getline(cin, userPrompt);
				}//while loop to check if the user entered either find or add

			}//error check if the user entered something other than "find" or "add"
		}//if the password is the correct input as recorded from accounts.txt
		else {
			cout << invalidPW;
			getline(cin, passWord);

			int timesAttempted = 1;
			while (passWord != inputString) {
				cout << invalidPW;
				getline(cin, passWord);
				timesAttempted++;

				if (timesAttempted >= 3) {
					return;
				}//if the times attempted is more than or equal to 3, exit.
			}//while loop to check and re-enter the password until the password is correct.
		}//if the password is incorrect as recorded from accounts.txt
	}//if the username is the correct input as recorded from accounts.txt
	else {
		cout << nullAccount;
		getline(cin, userName);

		while (userName != inputString) {
			cout << nullAccount;
			getline(cin,userName);
		}//while loop to check and re-enter the username until the correct username is inserted
	}//If the username is not the correct one as recorded from the accounts.txt
	inputFile.close();


}

string printPrompt () {
	string userPrompt;
	cout << "Is this the first time using the program? (Y/N). Enter end to end program: ";
	getline(cin, userPrompt);

	return userPrompt;
}
