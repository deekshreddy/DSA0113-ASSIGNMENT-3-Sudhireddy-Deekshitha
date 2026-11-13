
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

    ~Prescription()
    {
        delete[] medicines;
    }

    void set(int i, const string& m)
    {
        medicines[i] = m;
    }

    string get(int i) const
    {
        return medicines[i];
    }
};

int main()
{
    cout << "SHALLOW COPY DEMONSTRATION\n";
    cout << "===========================\n\n";

    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;

    q.set(1, "Cetirizine");

    cout << "Original Prescription: "
         << p.get(0) << " " << p.get(1) << '\n';

    cout << "Copied Prescription: "
         << q.get(0) << " " << q.get(1) << '\n';

    cout << "\nBoth objects share the same array.\n";

    return 0;
}
