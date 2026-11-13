
#include <iostream>
#include <string>
using namespace std;

class Prescription
{
    int n;
    string* medicines;

public:

    explicit Prescription(int count)
        : n(count), medicines(new string[count])
    {
    }

    Prescription(const Prescription& other)
        : n(other.n), medicines(new string[other.n])
    {
        for (int i = 0; i < n; i++)
        {
            medicines[i] = other.medicines[i];
        }
    }

    Prescription& operator=(const Prescription& other)
    {
        if (this == &other)
        {
            cout << "Self-assignment detected!\n";
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

    string get(int i) const
    {
        if (i >= 0 && i < n)
        {
            return medicines[i];
        }

        return "";
    }
};

int main()
{
    cout << "SELF-ASSIGNMENT TEST\n";
    cout << "====================\n\n";

    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    cout << "Before self-assignment: "
         << p.get(0) << " " << p.get(1) << '\n';

    p = p;

    cout << "After self-assignment: "
         << p.get(0) << " " << p.get(1) << '\n';

    return 0;
}
