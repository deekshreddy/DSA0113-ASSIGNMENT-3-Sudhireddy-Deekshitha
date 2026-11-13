
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    int copies;

public:
    Book(string t, int c)
        : copies(c), title(t)
    {
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Copies: " << copies << endl;
    }
};

int main()
{
    Book b("C++ Programming", 5);
    b.display();

    return 0;
}
