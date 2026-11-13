#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

class Money
{
private:
    long long paise;

public:

    Money(long long rupees = 0, int p = 0)
    {
        paise = rupees * 100 + p;
    }

    static Money fromPaise(long long value)
    {
        Money result;
        result.paise = value;
        return result;
    }

    // TODO 1: Addition operator
    Money operator+(const Money& other) const
    {
        return fromPaise(paise + other.paise);
    }

    Money operator-(const Money& other) const
    {
        return fromPaise(paise - other.paise);
    }

    Money& operator+=(const Money& other)
    {
        paise += other.paise;
        return *this;
    }

    // TODO 2: Equality operator
    bool operator==(const Money& other) const
    {
        return paise == other.paise;
    }

    bool operator<(const Money& other) const
    {
        return paise < other.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m)
    {
        long long amount = m.paise;

        if (amount < 0)
        {
            out << "-Rs ";
            amount = -amount;
        }
        else
        {
            out << "Rs ";
        }

        out << amount / 100 << "."
            << setfill('0') << setw(2)
            << amount % 100;

        return out;
    }

    friend istream& operator>>(istream& in, Money& m)
    {
        long long rupees;
        int p;

        if (in >> rupees >> p)
        {
            m.paise = rupees * 100 + p;
        }

        return in;
    }
};

int main()
{
    cout << "====================================\n";
    cout << "       MONEY BILLING SYSTEM\n";
    cout << "====================================\n\n";

    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << "1. BASIC ADDITION\n";
    cout << "Amount A : " << a << endl;
    cout << "Amount B : " << b << endl;
    cout << "Total    : " << c << endl;

    cout << "Equality: "
         << boolalpha << (c == Money(200)) << "\n\n";

    Money x(0, 75);
    Money y(0, 50);

    cout << "2. PAISE CARRY TEST\n";
    cout << x << " + " << y
         << " = " << x + y << "\n\n";

    Money p(50);
    Money q(75);

    cout << "3. SUBTRACTION TEST\n";
    cout << p << " - " << q
         << " = " << p - q << "\n\n";

    Money balance(100);

    balance += Money(50, 50);

    cout << "4. COMPOUND ADDITION\n";
    cout << "Updated Balance: "
         << balance << "\n\n";

    Money first(50);
    Money second(100);

    cout << "5. COMPARISON TEST\n";
    cout << "Rs 50 < Rs 100: "
         << (first < second) << "\n\n";

    Money item1(120, 50);
    Money item2(79, 25);
    Money item3(50, 25);

    Money total;

    total += item1;
    total += item2;
    total += item3;

    cout << "6. BILL CALCULATION\n";
    cout << "Item 1: " << item1 << endl;
    cout << "Item 2: " << item2 << endl;
    cout << "Item 3: " << item3 << endl;
    cout << "-------------------------\n";
    cout << "Total : " << total << "\n\n";

    const int COUNT = 1000000;

    double doubleTotal = 0.0;
    Money moneyTotal;

    auto startDouble = chrono::high_resolution_clock::now();

    for (int i = 0; i < COUNT; i++)
    {
        doubleTotal += 0.01;
    }

    auto endDouble = chrono::high_resolution_clock::now();

    auto startMoney = chrono::high_resolution_clock::now();

    for (int i = 0; i < COUNT; i++)
    {
        moneyTotal += Money(0, 1);
    }

    auto endMoney = chrono::high_resolution_clock::now();

    double doubleTime =
        chrono::duration<double, milli>(
            endDouble - startDouble).count();

    double moneyTime =
        chrono::duration<double, milli>(
            endMoney - startMoney).count();

    cout << "7. ONE MILLION ADDITIONS\n";

    cout << fixed << setprecision(15);

    cout << "Double Result: "
         << doubleTotal << endl;

    cout << "Money Result: "
         << moneyTotal << endl;

    cout << "Double Time: "
         << doubleTime << " ms\n";

    cout << "Money Time: "
         << moneyTime << " ms\n";

    cout << "\n====================================\n";
    cout << "       PROGRAM COMPLETED\n";
    cout << "====================================\n";

    return 0;
}
