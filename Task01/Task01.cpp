
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book
{
private:
    string title;
    int copies;

public:
    Book() : Book("", 0)
    {
        cout << "Default constructor called.\n";
    }

    Book(string t) : Book(t, 1)
    {
        cout << "Single-parameter constructor called.\n";
    }

    Book(string t, int c)
        : title(t), copies(c)
    {
        if (c < 0)
        {
            throw invalid_argument(
                "Number of copies cannot be negative."
            );
        }

        cout << "Parameterized constructor called.\n";
    }

    void display() const
    {
        cout << "Title  : "
             << (title.empty() ? "Empty Record" : title)
             << endl;

        cout << "Copies : " << copies << endl;
        cout << "-----------------------------\n";
    }
};

int main()
{
    cout << "================================\n";
    cout << "      LIBRARY BOOK RECORDS\n";
    cout << "   CONSTRUCTOR DEMONSTRATION\n";
    cout << "================================\n\n";

    cout << "1. Empty Book Record\n";
    Book book1;
    book1.display();

    cout << "2. Donated Book Record\n";
    Book book2("C++ Basics");
    book2.display();

    cout << "3. Complete Book Record\n";
    Book book3("Data Structures", 5);
    book3.display();

    cout << "4. Invalid Book Record\n";

    try
    {
        Book book4("Programming", -3);
        book4.display();
    }
    catch (const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nProgram completed successfully.\n";

    return 0;
}
