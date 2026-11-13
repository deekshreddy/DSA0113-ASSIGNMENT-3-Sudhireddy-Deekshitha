#include <iostream>
#include <iomanip>
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

    long long getPaise() const
    {
        return paise;
    }
};

Money add(const Money& a, const Money& b)
{
    long long total = a.getPaise() + b.getPaise();

    return Money(total / 100, total % 100);
}

bool equals(const Money& a, const Money& b)
{
    return a.getPaise() == b.getPaise();
}

void print(const Money& m)
{
    long long amount = m.getPaise();

    if (amount < 0)
    {
        cout << "-Rs ";
        amount = -amount;
    }
    else
    {
        cout << "Rs ";
    }

    cout << amount / 100 << "."
         << setfill('0') << setw(2)
         << amount % 100 << endl;
}

int main()
{
    cout << "NAMED FUNCTIONS DEMONSTRATION\n\n";

    Money a(120, 75);
    Money b(79, 25);

    Money c = add(a, b);

    cout << "Amount A: ";
    print(a);

    cout << "Amount B: ";
    print(b);

    cout << "Total: ";
    print(c);

    cout << "Equality: "
         << boolalpha << equals(c, Money(200))
         << endl;

    return 0;
}
