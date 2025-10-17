#ifndef ADMIN_H
#define ADMIN_H

#include "Book.h"




void AdminHandleChoice(string admin);
bool AdminOpenBookFile(fstream& BooksFile);
void AdminAddBook(fstream& BooksFile);
void AdminDeleteBook(fstream& BooksFile);
void AdminBorrowBook(fstream& BooksFile);
void AdminReturnBook(fstream& BooksFile);
void AdminShowBook(fstream& BooksFile);







#endif // !ADMIN_H
