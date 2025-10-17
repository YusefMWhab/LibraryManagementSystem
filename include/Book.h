#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// This Structure to Define each Book 
struct Books
{
	unsigned int serial;
	string title;
	string author;
	bool IsBorrowed;

};

class BookManager {

private:

	// Dynamic Array to store Books
	vector<Books> books;

	// Array of struct of Book
	void BookReadFromFile(fstream& BooksFile);
	void BookWriteToFile(fstream& BooksFile);

public:

	void BookAdd(fstream& BooksFile);
	void BookDelete(fstream& BooksFile);
	void BookBorrow(fstream& BooksFile);
	void BookReturn(fstream& BooksFile);
	void BookShowList(fstream& BooksFile);

};

#endif // !BOOK_H
