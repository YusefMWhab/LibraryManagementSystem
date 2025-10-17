#include "../include/Admin.h"


// Function to Handle Admin Window Choice
void AdminHandleChoice(string admin)
{
	cout << "Welcome " << admin << " to Admin Mode" << endl;

	// Check Book File or create in if not created
	fstream BooksFile;
	if (!(AdminOpenBookFile(BooksFile)))
		return;
	else
		BooksFile.close();  // Close file to reopen it again in each function


	bool EndSession = false;

	while (!EndSession)
	{
		short int AdminEnter;
		bool CheckAdminEnter = false;

		// Options for Admin Mode

		cout << "Options: \n";
		cout << "Add a Book    -> 1 \n";
		cout << "Delete a Book -> 2 \n";
		cout << "Borrow a Book -> 3 \n";
		cout << "Return a Book -> 4 \n";
		cout << "Show a Book   -> 5 \n";
		cout << "Logout        -> 0 \n";

		do
		{
			if (!(cin >> AdminEnter))
			{
				cout << "You have entered a text, Please Enter a valid number. \n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if ((AdminEnter < 0) || (AdminEnter > 5))
			{
				cout << "Please Enter a valid Option. \n";
			}
			else
			{
				CheckAdminEnter = true;
			}
		} while (!CheckAdminEnter);

		// Switch on Options

		switch (AdminEnter)
		{
		case 0:
			cout << "Log out. \n";
			return;
			break;
		case 1:
			// Add Book Function
			cout << "Add a Book. \n";
			AdminAddBook(BooksFile);
			break;
		case 2:
			// Delete Book Function
			cout << "Delete a Book. \n";
			AdminDeleteBook(BooksFile);
			break;
		case 3:
			// Borrow Book Function
			cout << "Borrow a Book. \n";
			AdminBorrowBook(BooksFile);
			break;
		case 4:
			// Return Book Function
			cout << "Return a Book. \n";
			AdminReturnBook(BooksFile);
			break;
		case 5:
			// Show a Book Function
			cout << "Show Library Books. \n";
			AdminShowBook(BooksFile);
			break;
		}



		// Check for End Session

		cout << "Do you want to perform another action? \n";
		cout << "No   -> 0 \n";
		cout << "Yes  -> 1 \n";

		short int EndSessionvalue;
		bool CheckEndSessionvalue = false;

		while (!CheckEndSessionvalue)
		{
			if (!(cin >> EndSessionvalue))
			{
				cout << "You have entered a text, Please Enter a valid number. \n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if ((EndSessionvalue != 1) && (EndSessionvalue != 0))
			{
				cout << "Please Enter a valid Option. \n";

			}
			else if (EndSessionvalue == 0)  // No End Session
			{
				CheckEndSessionvalue = true;
				EndSession = true;
			}
			else
			{
				CheckEndSessionvalue = true;
				EndSession = false;
			}
		}
	}
}

// Function To Open or create a data base for Books
bool AdminOpenBookFile(fstream& BooksFile)
{
	bool FileAccess = false;
	BooksFile.open("BooksFile.txt", ios::in | ios::out | ios::app);

	//Check if file opened successfully or not
	if (!BooksFile.is_open())
	{
		// File not opened then create the file
		cout << "File is not existed \n File will be created now as BooksFile.txt. \n";
		BooksFile.open("BooksFile.txt", ios::out);
		BooksFile.close();					// Close to re-open it in read/write mode
		BooksFile.open("BooksFile.txt", ios::in | ios::out | ios::app);

	}
	// Check whether it created successfully
	if (BooksFile.is_open())
	{
		FileAccess = true;
		cout << "Data Base has been opened successfully for read / write.\n";

	}
	else
	{
		FileAccess = false;
		cout << "Data Base can't be opened, Please Try Again later.\n";

	}

	return FileAccess;
}


// Add Book Function
void AdminAddBook(fstream& BooksFile)
{
	// Create an object to manage the libirary:
	BookManager manager;
	manager.BookAdd(BooksFile);
}

// Delete Book Function
void AdminDeleteBook(fstream& BooksFile)
{
	// Create an object to manage the libirary:
	BookManager manager;
	manager.BookDelete(BooksFile);
}

// Borrow Book Function
void AdminBorrowBook(fstream& BooksFile)
{
	// Create an object to manage the libirary:
	BookManager manager;
	manager.BookBorrow(BooksFile);
}

// Return Book Function
void AdminReturnBook(fstream& BooksFile)
{
	// Create an object to manage the libirary:
	BookManager manager;
	manager.BookReturn(BooksFile);
}

// Show Book Function
void AdminShowBook(fstream& BooksFile)
{
	BookManager manager;
	manager.BookShowList(BooksFile);
}