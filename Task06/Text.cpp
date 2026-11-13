#include <iostream>
#include <cstring>
#include <chrono>
#include <string>

using namespace std;

class Text
{
private:
    char* data;

    static int copyCount;

public:

    Text(const char* str = "")
    {
        if (str == NULL)
            str = "";

        data = new char[strlen(str) + 1];

        strcpy(data, str);
    }

    Text(const Text& other)
    {
        data = new char[strlen(other.data) + 1];

        strcpy(data, other.data);

        copyCount++;
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

    Text operator+(const Text& other) const
    {
        int len1 = strlen(data);
        int len2 = strlen(other.data);

        char* buffer = new char[len1 + len2 + 1];

        strcpy(buffer, data);
        strcat(buffer, other.data);

        Text result(buffer);

        delete[] buffer;

        return result;
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

    static int getCopyCount()
    {
        return copyCount;
    }

    static void resetCopyCount()
    {
        copyCount = 0;
    }

    int length() const
    {
        return strlen(data);
    }
};

int Text::copyCount = 0;


int main()
{
    cout << "====================================\n";
    cout << "       SMS TEXT MANAGEMENT\n";
    cout << "====================================\n\n";

    Text a("Hello ");
    Text b("World");
    Text c("!");

    cout << "1. BASIC TEXT OBJECTS\n";

    cout << "Text A: " << a << endl;
    cout << "Text B: " << b << endl;
    cout << "Text C: " << c << "\n\n";

    cout << "2. CONCATENATION\n";

    Text message = a + b;

    cout << "A + B: " << message << endl;

    Text finalMessage = message + c;

    cout << "A + B + C: "
         << finalMessage << "\n\n";

    cout << "3. COMPARISON OPERATORS\n";

    Text x("Hello");
    Text y("Hello");
    Text z("Goodbye");

    cout << "X == Y: "
         << boolalpha << (x == y) << endl;

    cout << "X != Z: "
         << (x != z) << "\n\n";

    cout << "4. COPY CONSTRUCTOR\n";

    Text original("Original Message");

    Text copied(original);

    cout << "Original: " << original << endl;
    cout << "Copied: " << copied << "\n\n";

    cout << "5. COPY ASSIGNMENT\n";

    Text assigned;

    assigned = original;

    cout << "Assigned Message: "
         << assigned << "\n\n";

    cout << "6. SELF-ASSIGNMENT TEST\n";

    original = original;

    cout << "After self-assignment: "
         << original << "\n\n";

    cout << "7. EMPTY MESSAGE TEST\n";

    Text empty("");

    cout << "Empty Message: [" << empty << "]" << endl;

    cout << "Empty Length: "
         << empty.length() << endl;

    cout << "Empty + Hello: "
         << empty + x << "\n\n";

    cout << "8. LONG MESSAGE TEST\n";

    Text longMessage(
        "This is a long SMS message used to test "
        "dynamic memory allocation and deep copying "
        "in the custom Text class.");

    cout << "Long Message: "
         << longMessage << endl;

    cout << "Message Length: "
         << longMessage.length() << "\n\n";

    cout << "9. COPY COUNT EXPERIMENT\n";

    Text first("A");
    Text second("B");
    Text third("C");

    Text::resetCopyCount();

    Text combined = first + second + third;

    cout << "Combined Message: "
         << combined << endl;

    cout << "Copy Constructor Calls: "
         << Text::getCopyCount() << "\n\n";

    cout << "10. PERFORMANCE COMPARISON\n";

    const int COUNT = 100000;

    auto startText =
        chrono::high_resolution_clock::now();

    for (int i = 0; i < COUNT; i++)
    {
        Text temp = first + second;
    }

    auto endText =
        chrono::high_resolution_clock::now();

    string str1 = "A";
    string str2 = "B";

    auto startString =
        chrono::high_resolution_clock::now();

    for (int i = 0; i < COUNT; i++)
    {
        string temp = str1 + str2;
    }

    auto endString =
        chrono::high_resolution_clock::now();

    double textTime =
        chrono::duration<double, milli>(
            endText - startText).count();

    double stringTime =
        chrono::duration<double, milli>(
            endString - startString).count();

    cout << "Number of Concatenations: "
         << COUNT << endl;

    cout << "Custom Text Time: "
         << textTime << " ms" << endl;

    cout << "std::string Time: "
         << stringTime << " ms" << endl;

    cout << "\n====================================\n";
    cout << "       PROGRAM COMPLETED\n";
    cout << "====================================\n";

    return 0;
}
