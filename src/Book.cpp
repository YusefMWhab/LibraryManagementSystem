#include "../include/Book.h"

// This Function is to Load Books from the file into Array of Sruct of Books
void BookManager::BookReadFromFile(fstream& BooksFile)
{


	// OpenFile in read mode
	BooksFile.open("BooksFile.txt", ios::in);

	string StringLine;

	while (getline(BooksFile, StringLine))
	{
		// find positions of ','
		short int pos1 = StringLine.find(',');
		short int pos2 = StringLine.find(',',pos1 +1);
		short int pos3 = StringLine.find(',', pos2 + 1);

		// Create a strut of Books Type
		Books StructBook;

		string serial = StringLine.substr(0, pos1);
		string title = StringLine.substr(pos1 + 2, pos2 - pos1 - 2);
		string author = StringLine.substr(pos2 + 2, pos3 - pos2 - 2);
		string IsBorrowed = StringLine.substr(pos3 + 2);

		// Fill the members of the structure

		StructBook.serial = stoi(serial);
		StructBook.title = title;
		StructBook.author = author;
		
		if ((IsBorrowed == "Yes") || (IsBorrowed == "yes") || (IsBorrowed == "True") || (IsBorrowed == "true"))
			StructBook.IsBorrowed = true;
		else
			StructBook.IsBorrowed = false;

		// Add Book to Array

		books.push_back(StructBook);
	}

	// Close File
	BooksFile.close();
}

// This Function is to Write Books to the file from Array of Sruct of Books
void BookManager::BookWriteToFile(fstream& BooksFile)
{
	// Clear the file before writing on it
	BooksFile.close();
	BooksFile.open("BooksFile.txt", ios::out);

		for (int i = 0; i < books.size(); i++)
		{
			BooksFile << books[i].serial << ", " << books[i].title << ", " << books[i].author << ", ";
			if (books[i].IsBorrowed == true)
				BooksFile << "Yes\n";
			else
				BooksFile << "No\n";	
		}
		BooksFile.close();
}

// This Function Shows the list of books in The Data Base
void BookManager::BookShowList(fstream& BooksFile)
{
	BookReadFromFile(BooksFile);
	
	if (books.size() == 0)
	{
		cout << "Library is Empty.\n ";
	}
	else
	{
		for (int i = 0; i < books.size(); i++)
		{
			cout << "Book " << i + 1 << endl;
			cout << "Serial      :" << books[i].serial << endl;
			cout << "Title       :" << books[i].title << endl;
			cout << "Author      :" << books[i].author << endl;
			if (books[i].IsBorrowed == false)
				cout << "Not Borrowed \n";
			else
				cout << "Borrowed \n";
		}
	}
}

// This Function Allow admin to add a Book
void BookManager::BookAdd(fstream& BooksFile)
{
	BookShowList(BooksFile);
	Books StructBook;

	cout << "Enter The Book Details : \n";
	cout << "Serial... \n";
	while (!(cin >> StructBook.serial))
	{
		cout << "Enter a Valid Serial Please ! \n";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	cout << "Title... \n";
	cin.ignore(10000, '\n');
	getline(cin, StructBook.title);

	cout << "Author...\n";
	getline(cin, StructBook.author);

	StructBook.IsBorrowed = false;

	cout << "The Book Details is : \n";
	cout << "Serial : " << StructBook.serial<<endl;
	cout << "Title  : " << StructBook.title << endl;
	cout << "Author : " << StructBook.author << endl;
	cout << "Not Borrowed \n";
	// Push to array
	books.push_back(StructBook);
	cout << "Added to Array successfully \n";

	// Save at Data Base
	BookWriteToFile(BooksFile);
}

// This Function Allow admin to Return a Book
void BookManager::BookReturn(fstream& BooksFile)
{
	BookShowList(BooksFile);
	
	if (books.size() == 0)
	{
		return;
	}
	cout << "Enter Book Serial to Return. \n";
	int UserEnter;
	bool CheckUserEnter = false;
	while (!(cin>> UserEnter))
	{
		cout << "You have entered a text, Please Enter a valid Serial.\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	bool Isfound = false;

	for (int i = 0; i < books.size(); i++)
	{
		if (UserEnter == books[i].serial)
		{
			Isfound = true;
			books[i].IsBorrowed = false;
			break;
		}
	}
	if (Isfound)
		cout << "Book is found and has been returned successfully\n";
	else
		cout << "Book is not found. \n";
	BookWriteToFile(BooksFile);
}

// This Function Allow admin to Borrow a Book
void BookManager::BookBorrow(fstream& BooksFile)
{
	BookShowList(BooksFile);

	if (books.size() == 0)
	{
		return;
	}

	cout << "Enter Book Serial to Borrow. \n";
	int UserEnter;
	bool CheckUserEnter = false;
	while (!(cin >> UserEnter))
	{
		cout << "You have entered a text, Please Enter a valid Serial.\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	bool Isfound = false;

	for (int i = 0; i < books.size(); i++)
	{
		if (UserEnter == books[i].serial)
		{
			Isfound = true;
			books[i].IsBorrowed = true;
			break;
		}
	}
	if (Isfound)
		cout << "Book is found and has been Borrowed successfully\n";
	else
		cout << "Book is not found. \n";
	BookWriteToFile(BooksFile);
}

// This Function Allow admin to Delete a Book
void BookManager::BookDelete(fstream& BooksFile)
{
	BookShowList(BooksFile);

	if (books.size() == 0)
	{
		return;
	}

	cout << "Enter Book Serial to Delete. \n";
	int UserEnter;
	bool CheckUserEnter = false;
	while (!(cin >> UserEnter))
	{
		cout << "You have entered a text, Please Enter a valid Serial.\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	bool Isfound = false;

	for (int i = 0; i < books.size(); i++)
	{
		if (UserEnter == books[i].serial)
		{
			Isfound = true;
			books.erase(books.begin() + i);
			break;
		}
	}
	if (Isfound)
		cout << "Book is found and has been deleted successfully\n";
	else
		cout << "Book is not found. \n";
	BookWriteToFile(BooksFile);
}
