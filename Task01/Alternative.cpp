
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
    Book(string t = "", int c = 0)
        : title(t), copies(c)
    {
        if (copies < 0)
        {
            throw invalid_argument(
                "Number of copies cannot be negative."
            );
        }
    }

    void display() const
    {
        cout << "Title: "
             << (title.empty() ? "Empty Record" : title)
             << endl;

        cout << "Copies: " << copies << endl;
    }
};

int main()
{
    Book b1;
    Book b2("C++ Basics");
    Book b3("Data Structures", 5);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}
