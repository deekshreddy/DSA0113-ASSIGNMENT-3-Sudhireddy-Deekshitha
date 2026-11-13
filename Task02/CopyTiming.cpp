
#include <iostream>
#include <string>
#include <chrono>
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

    // Deep copy constructor
    Prescription(const Prescription& other)
        : n(other.n), medicines(new string[other.n])
    {
        for (int i = 0; i < n; i++)
        {
            medicines[i] = other.medicines[i];
        }
    }

    // Copy assignment operator
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

    string get(int i) const
    {
        if (i >= 0 && i < n)
        {
            return medicines[i];
        }

        return "";
    }
};

void measureCopyTime(int count, int iterations)
{
    Prescription original(count);

    // Fill prescription
    for (int i = 0; i < count; i++)
    {
        original.set(i, "Medicine");
    }

    volatile size_t checksum = 0;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
    {
        Prescription copy = original;

        checksum = checksum + copy.get(0).size();
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast<chrono::microseconds>(
            end - start
        );

    double average =
        static_cast<double>(duration.count()) / iterations;

    cout << "Medicines: " << count << '\n';

    cout << "Iterations: " << iterations << '\n';

    cout << "Total time: " << duration.count()
         << " microseconds\n";

    cout << "Average time: " << average
         << " microseconds per copy\n\n";

    (void)checksum;
}

int main()
{
    cout << "PRESCRIPTION COPYING TIME TEST\n";
    cout << "==============================\n\n";

    measureCopyTime(10, 10000);

    measureCopyTime(1000, 1000);

    measureCopyTime(100000, 10);

    return 0;
}
