#include "../include/LoginWindow.h"


void LWhandleChoice()
{
	cout << "Welcome \n";
	cout << "Enter Your Choice \n";
	cout << "To Login, Enter \"1\" \n";
	cout << "To Close Program, Enter \"0\" \n";
	
	// Handling User Input
	short int UserEnter;
	bool CheckUserEnter = false;
	do{

		// Validate that it is not a text
		if ( !(cin >> UserEnter) )
		{
			cout << "You have entered a text, Please Enter a valid number \n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		// Validate it is the range
		else if (UserEnter != 0 && UserEnter != 1)
		{
			cout << "Please Enter 0 or 1 \n";
		}
		else
		{
			CheckUserEnter = true;
		}
	} while (!CheckUserEnter);

	cout << "You have entered " << UserEnter << '\n';

	// Looping to Action based on User Enter
	if (UserEnter == 0)
	{
		return;
	}
	else
	{
		LWlogin();
	}
}

/* 
This functions allows user to login
by username and password Then Looping to Admin Mode
Only 3 trials to Login, if access denied 3 times program will Exit
*/
void LWlogin() 
{

	// Define string variables to Read from User and File
	string UsernameInput;
	string PasswordInput;
	string UsernameTest;
	string PasswordTest;

	// Open Admin File

	fstream AdminFile;
	AdminFile.open("Admin.txt", ios::in);

	if (!AdminFile.is_open()) 
	{
		cout << "Error: Can not open file! \n";
		return;
	}

	bool loginAccess = false;
	short int trialCounter = 0;

	while (trialCounter < 3 && loginAccess == false)
	{
		
		// Allow User to Enter Username and Password

		cout << "Please Enter your Username \n";
		cin >> UsernameInput;
		cout << "Please Enter your Password \n";
		cin >> PasswordInput;

		// Check Entered Username and Password

		AdminFile.clear(); // Reset EOF and fail flags
		AdminFile.seekg(0, ios::beg); // Move pointer to beginning
		while ( (AdminFile >> UsernameTest >> PasswordTest) && (loginAccess == false) )
		{

			if ((UsernameInput == UsernameTest) && (PasswordInput == PasswordTest))
			{
				loginAccess = true;
				break;
			}
		}

		if (loginAccess == false)
		{
			trialCounter++;
			if (trialCounter < 3)
			{
				cout << "Access Denied, Please Try again \n";
			}
		}
	}

	// Check Access Statues : Denied or Successful
	if (loginAccess == true)
	{
		// Entered Admin Mode

		cout << "Login Success" << endl;

		// Call Admin Mode
		AdminHandleChoice(UsernameTest);

	}

	// Access Denied
	else
	{
		cout << "You have entered wrong Username or Password 3 times, Please Try again Later \n ";
	}
}