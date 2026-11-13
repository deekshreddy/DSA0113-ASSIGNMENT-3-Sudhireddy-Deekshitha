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

    static Money fromPaise(long long value)
    {
        Money result;
        result.paise = value;
        return result;
    }

    friend Money operator+(const Money& a, const Money& b)
    {
        return fromPaise(a.paise + b.paise);
    }

    friend bool operator==(const Money& a, const Money& b)
    {
        return a.paise == b.paise;
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
};
int main()
{
    cout << "FRIEND OPERATOR DEMONSTRATION\n\n";

    Money m(50);

    Money a = 100 + m;
    Money b = m + 100;

    cout << "Original Amount: " << m << endl;
    cout << "100 + m: " << a << endl;
    cout << "m + 100: " << b << endl;

    cout << "Equality: "
         << boolalpha << (a == b) << endl;

    return 0;
}
