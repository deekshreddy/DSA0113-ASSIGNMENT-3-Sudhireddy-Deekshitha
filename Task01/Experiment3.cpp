#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    Book(string title)
    {
        cout << "Book created: " << title << endl;
    }
};

int main()
{
    string title = "C++ Basics";

    Book b = title;

    return 0;
}