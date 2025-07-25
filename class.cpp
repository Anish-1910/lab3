#include <iostream>
using namespace std;

class book {
public:
    string title;
    string author;
    int price;

    void bookdetails();
};

void book::bookdetails() {
    cout << "Book Title: " << title << endl;
    cout << "Book Author: " << author << endl;
    cout << "Book price: " << price << endl;
}

int main() {
    int n;
    cout << "Enter the number of books:";
    cin >> n;
    cin.ignore();

    book books[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter book " << i + 1 << " details:" << endl;

        cout << "Enter book title: ";
        getline(cin, books[i].title);

        cout << "Enter book author: ";
        getline(cin, books[i].author);

        cout << "Enter book price: ";
        cin >> books[i].price;
      cin.ignore();
    }

    for (int i = 0; i < n; i++) {
        books[i].bookdetails();
    }

    return 0;
}
