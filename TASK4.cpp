#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string title, author;
    bool isAvailable;
    int dueDays;
};

vector<Book> library;

// Function to add books to the database
void addBooks() {
    Book b1 = {1, "C++ Programming", "Bjarne Stroustrup", true, 0};
    Book b2 = {2, "Clean Code", "Robert C. Martin", true, 0};
    Book b3 = {3, "Introduction to Algorithms", "CLRS", true, 0};
    library.push_back(b1);
    library.push_back(b2);
    library.push_back(b3);
}

// Show all books with availability
void showBookList() {
    cout << "\n--- Book List ---\n";
    for (int i = 0; i < library.size(); i++) {
        Book book = library[i];
        cout << "ID: " << book.id
             << " | Title: " << book.title
             << " | Author: " << book.author
             << " | Status: " << (book.isAvailable ? "Available" : "Checked Out") << endl;
    }
}

// Search books by title
void searchBook(string title) {
    bool found = false;
    for (int i = 0; i < library.size(); i++) {
        Book book = library[i];
        if (book.title.find(title) != string::npos) {
            cout << "Found: " << book.title << " by " << book.author
                 << (book.isAvailable ? " [Available]" : " [Not Available]") << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Book not found." << endl;
}

// Checkout book by ID
void checkoutBook(int id) {
    for (int i = 0; i < library.size(); i++) {
        if (library[i].id == id && library[i].isAvailable) {
            library[i].isAvailable = false;
            library[i].dueDays = 7;
            cout << "Book checked out: " << library[i].title << endl;
            return;
        }
    }
    cout << "Book not available or invalid ID." << endl;
}

// Return book and calculate fine
void returnBook(int id, int daysLate) {
    for (int i = 0; i < library.size(); i++) {
        if (library[i].id == id && !library[i].isAvailable) {
            library[i].isAvailable = true;
            int fine = (daysLate > 0) ? daysLate * 5 : 0;
            cout << "Book returned: " << library[i].title << endl;
            cout << "Fine: Rs. " << fine << endl;
            return;
        }
    }
    cout << "Invalid return operation." << endl;
}

int main() {
    addBooks();
    int choice;

    while (true) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Search Book\n2. Checkout Book\n3. Return Book\n4. Exit\n5. View Book List\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string title;
            cout << "Enter book title to search: ";
            cin.ignore();
            getline(cin, title);
            searchBook(title);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter book ID to checkout: ";
            cin >> id;
            checkoutBook(id);
        }
        else if (choice == 3) {
            int id, days;
            cout << "Enter book ID to return: ";
            cin >> id;
            cout << "Enter number of late days (0 if on time): ";
            cin >> days;
            returnBook(id, days);
        }
        else if (choice == 4) {
            cout << "Thank you for using the Library Management System!" << endl;
            break;
        }
        else if (choice == 5) {
            showBookList();
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}

