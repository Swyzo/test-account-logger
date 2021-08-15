/*
 * functions.h
 *
 *  Created on: Jun 11, 2021
 *      Author: Josh
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void searchDB(string targetUser);

void clearCin ();

void clearConsole ();

bool lengthValidate (string entry);

void returningUser(const char* userNameFailedInsert, const char* passwordFailedInsert,
		const char* loginURLFailedInsert, const char* nullAcccount,
		const char* invalidPW, const char* findAddChoice);

void newUser(const char* userNameFailedInsert, const char* passwordFailedInsert,
		const char* loginURLFailedInsert, const char* usernameRepeat);

string printPrompt ();

#endif /* FUNCTIONS_H_ */
