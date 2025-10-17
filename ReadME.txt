# 📚 Library Management System (C++)

A simple **Library Management System** built using **C++**, demonstrating:
- **Object-Oriented Programming (OOP)**
- **File Handling** (`fstream`) for data persistence
- **Structs and Classes**
- **Dynamic Vectors**
- Basic **CRUD operations**: Add, Delete, Borrow, Return books

---

## 🧩 Features
- Add new books with serial, title, and author
- Delete existing books by serial number
- Borrow and return books
- Display all books with their status (Borrowed / Not Borrowed)
- All data saved in `BooksFile.txt` automatically

---

## 📂 Folder Structure
LibraryManagementSystem/
│
├── src/
│ ├── main.cpp
│ ├── Admin.cpp
│ ├── Book.cpp
│ ├── LoginWindow.cpp
│
├── include/
│ ├── Admin.h
│ ├── Book.h
│ ├── LoginWindow.h
│
├── BooksFile.txt
└── README.md


---

## ⚙️ Requirements
- **C++17** or later
- Any IDE that supports C++ (Visual Studio, Code::Blocks, CLion, VS Code)
- Windows / Linux / MacOS

---

## 🚀 How to Run

### From Terminal / PowerShell:
```bash
g++ src/*.cpp -I include -o LibrarySystem
.\LibrarySystem.exe       # Windows
./LibrarySystem           # Linux/Mac

From IDE:

Open project folder in IDE

Add all .cpp files from src/

Add include/ as additional include path

Build & Run main.cpp

💡 Notes

The program automatically creates BooksFile.txt if it does not exist

Enter login as instructed in the console to access admin features

All operations are saved persistently in the text file

👨‍💻 Author

Youssef Mohamed
Electronics & Electrical Communication Engineer
Cairo University

📝 License

This project is free to use for educational purposes