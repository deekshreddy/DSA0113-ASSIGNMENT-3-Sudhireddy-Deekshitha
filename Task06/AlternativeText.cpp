#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Text
{
private:
    char* data;

public:

    Text(const char* str = "")
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    Text(const Text& other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    Text& operator=(const Text& other)
    {
        if (this != &other)
        {
            char* newData =
                new char[strlen(other.data) + 1];

            strcpy(newData, other.data);

            delete[] data;

            data = newData;
        }

        return *this;
    }

    ~Text()
    {
        delete[] data;
    }

    Text& operator+=(const Text& other)
    {
        int len1 = strlen(data);
        int len2 = strlen(other.data);

        char* newData = new char[len1 + len2 + 1];

        strcpy(newData, data);
        strcat(newData, other.data);

        delete[] data;

        data = newData;

        return *this;
    }

    friend Text operator+(Text a, const Text& b)
    {
        a += b;

        return a;
    }

    bool operator==(const Text& other) const
    {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const Text& other) const
    {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const Text& t)
    {
        out << t.data;
        return out;
    }
};

int main()
{
    cout << "====================================\n";
    cout << "    ALTERNATIVE TEXT IMPLEMENTATION\n";
    cout << "====================================\n\n";

    Text a("Hello ");
    Text b("World");
    Text c("!");

    Text result = a + b + c;

    cout << "Text A: " << a << endl;
    cout << "Text B: " << b << endl;
    cout << "Text C: " << c << endl;

    cout << "Combined Text: "
         << result << endl;

    Text x("Hello");
    Text y("Hello");

    cout << "\nEquality: "
         << boolalpha << (x == y) << endl;

    cout << "Inequality: "
         << (x != y) << endl;

    cout << "\nSTD::STRING ALTERNATIVE\n";

    string s1 = "Hello ";
    string s2 = "World";

    string combined = s1 + s2;

    cout << "Combined String: "
         << combined << endl;

    return 0;
}
