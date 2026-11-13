#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Prescription
{
    vector<string> medicines;

public:

    explicit Prescription(int count)
        : medicines(count)
    {
    }

    void set(int i, const string& m)
    {
        if (i >= 0 && i < static_cast<int>(medicines.size()))
        {
            medicines[i] = m;
        }
    }

    string get(int i) const
    {
        if (i >= 0 && i < static_cast<int>(medicines.size()))
        {
            return medicines[i];
        }

        return "";
    }
};

int main()
{
    cout << "RULE OF ZERO DEMONSTRATION\n";
    cout << "==========================\n\n";

    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;

    q.set(1, "Cetirizine");

    cout << "Original Prescription: "
         << p.get(0) << " " << p.get(1) << '\n';

    cout << "Copied Prescription: "
         << q.get(0) << " " << q.get(1) << '\n';

    return 0;
}
