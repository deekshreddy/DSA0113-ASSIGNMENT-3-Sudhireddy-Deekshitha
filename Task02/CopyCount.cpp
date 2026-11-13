
#include <iostream>
#include <string>
using namespace std;

class Prescription
{
    int n;
    string* medicines;

public:

    static int copyCount;

    explicit Prescription(int count)
        : n(count), medicines(new string[count])
    {
    }

    Prescription(const Prescription& other)
        : n(other.n), medicines(new string[other.n])
    {
        copyCount++;

        cout << "Copy constructor called! Total copies: "
             << copyCount << '\n';

        for (int i = 0; i < n; i++)
        {
            medicines[i] = other.medicines[i];
        }
    }
    
    Prescription& operator=(const Prescription& other)
    {
        if (this == &other)
        {
            return *this;
        }

        string* newMedicines = new string[other.n];

        for (int i = 0; i < other.n; i++)
        {
            newMedicines[i] = other.medicines[i];
        }

        delete[] medicines;

        medicines = newMedicines;
        n = other.n;

        return *this;
    }

    ~Prescription()
    {
        delete[] medicines;
    }

    void set(int i, const string& m)
    {
        if (i >= 0 && i < n)
        {
            medicines[i] = m;
        }
    }
};

int Prescription::copyCount = 0;

void passByValue(Prescription p)
{
    cout << "Function received object by value.\n";
}

void passByReference(const Prescription& p)
{
    cout << "Function received object by const reference.\n";
}

int main()
{
    cout << "COPY CONSTRUCTOR COUNT\n";
    cout << "======================\n\n";

    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    cout << "1. Passing by value:\n";

    passByValue(p);

    cout << "\n2. Passing by const reference:\n";

    passByReference(p);

    cout << "\nTotal copy constructor calls: "
         << Prescription::copyCount << '\n';

    return 0;
}
