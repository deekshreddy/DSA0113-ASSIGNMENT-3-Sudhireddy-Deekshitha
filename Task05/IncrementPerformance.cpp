#include <iostream>
#include <chrono>

using namespace std;

class Counter
{
private:
    long long value;

public:

    Counter(long long v = 0)
    {
        value = v;
    }

    Counter& operator++()
    {
        ++value;
        return *this;
    }

    Counter operator++(int)
    {
        Counter old = *this;

        ++value;

        return old;
    }

    long long getValue() const
    {
        return value;
    }
};

int main()
{
    const int COUNT = 10000000;

    Counter prefixCounter(0);
    Counter postfixCounter(0);

    volatile long long prefixChecksum = 0;
    volatile long long postfixChecksum = 0;

    auto startPrefix =
        chrono::high_resolution_clock::now();

    for (int i = 0; i < COUNT; i++)
    {
        ++prefixCounter;
        prefixChecksum += prefixCounter.getValue();
    }

    auto endPrefix =
        chrono::high_resolution_clock::now();

    auto startPostfix =
        chrono::high_resolution_clock::now();

    for (int i = 0; i < COUNT; i++)
    {
        postfixChecksum += (postfixCounter++).getValue();
    }

    auto endPostfix =
        chrono::high_resolution_clock::now();

    double prefixTime =
        chrono::duration<double, milli>(
            endPrefix - startPrefix).count();

    double postfixTime =
        chrono::duration<double, milli>(
            endPostfix - startPostfix).count();

    cout << "====================================\n";
    cout << "    INCREMENT PERFORMANCE TEST\n";
    cout << "====================================\n\n";

    cout << "Total Iterations: "
         << COUNT << "\n\n";

    cout << "PREFIX INCREMENT\n";
    cout << "Final Value: "
         << prefixCounter.getValue() << endl;

    cout << "Execution Time: "
         << prefixTime << " ms\n\n";

    cout << "POSTFIX INCREMENT\n";
    cout << "Final Value: "
         << postfixCounter.getValue() << endl;

    cout << "Execution Time: "
         << postfixTime << " ms\n\n";

    cout << "Prefix Checksum: "
         << prefixChecksum << endl;

    cout << "Postfix Checksum: "
         << postfixChecksum << endl;

    cout << "\n====================================\n";

    return 0;
}
