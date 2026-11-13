#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:

    Complex()
    {
        real = 0.0;
        imag = 0.0;
    }

    Complex(double r)
    {
        real = r;
        imag = 0.0;
    }

    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real,
                       imag + other.imag);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real,
                       imag - other.imag);
    }

    Complex operator*(const Complex& other) const
    {
        double r = real * other.real -
                   imag * other.imag;

        double i = real * other.imag +
                   imag * other.real;

        return Complex(r, i);
    }

    Complex operator/(const Complex& other) const
    {
        double denominator =
            other.real * other.real +
            other.imag * other.imag;

        if (denominator == 0.0)
        {
            throw domain_error(
                "Division by zero impedance is not allowed."
            );
        }

        double r = (real * other.real +
                    imag * other.imag) / denominator;

        double i = (imag * other.real -
                    real * other.imag) / denominator;

        return Complex(r, i);
    }

    bool operator==(const Complex& other) const
    {
        return (real == other.real &&
                imag == other.imag);
    }

    double magnitude() const
    {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out,
                               const Complex& c)
    {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << fabs(c.imag) << "j";

        return out;
    }
};


Complex parallelImpedance(const Complex& z1,
                          const Complex& z2)
{
    return (z1 * z2) / (z1 + z2);
}


int main()
{
    cout << fixed << setprecision(4);

    cout << "========================================\n";
    cout << "       AC CIRCUIT IMPEDANCE CALCULATOR\n";
    cout << "========================================\n";

    cout << "\n1. CONSTRUCTOR DEMONSTRATION\n";

    Complex z1;
    Complex z2(10);
    Complex z3(5, 3);

    cout << "Default constructor       : " << z1 << endl;
    cout << "Real-only constructor     : " << z2 << endl;
    cout << "Two-argument constructor  : " << z3 << endl;

    cout << "\n2. OPERATOR OVERLOADING\n";

    Complex a(6, 4);
    Complex b(2, 3);

    cout << "First number  : " << a << endl;
    cout << "Second number : " << b << endl;

    cout << "Addition      : " << a + b << endl;
    cout << "Subtraction   : " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division      : " << a / b << endl;

    cout << "Equality      : ";

    if (a == b)
        cout << "Equal\n";
    else
        cout << "Not equal\n";

    cout << "Magnitude of first number: "
         << a.magnitude() << endl;

    cout << "\n3. RLC CIRCUIT PARAMETERS\n";

    double R = 10.0;
    double L = 0.1;
    double C = 100e-6;
    double frequency = 50.0;

    const double PI = acos(-1.0);

    double omega = 2.0 * PI * frequency;

    Complex ZR(R);

    Complex ZL(0, omega * L);

    Complex ZC(0, -1.0 / (omega * C));

    cout << "Resistance       : " << R << " ohms\n";
    cout << "Inductance       : " << L << " H\n";
    cout << "Capacitance      : " << C << " F\n";
    cout << "Frequency        : " << frequency << " Hz\n";
    cout << "Angular frequency: " << omega << " rad/s\n";

    cout << "\nIndividual Impedances:\n";

    cout << "Resistor   ZR = " << ZR << " ohms\n";
    cout << "Inductor   ZL = " << ZL << " ohms\n";
    cout << "Capacitor  ZC = " << ZC << " ohms\n";


    cout << "\n4. SERIES RLC CIRCUIT\n";

    Complex ZSeries = ZR + ZL + ZC;

    cout << "Formula: Z = ZR + ZL + ZC\n";

    cout << "Total impedance: "
         << ZSeries << " ohms\n";

    cout << "Magnitude       : "
         << ZSeries.magnitude() << " ohms\n";

    cout << "\n5. PARALLEL RLC CIRCUIT\n";

    Complex ZR_L = parallelImpedance(ZR, ZL);

    Complex ZParallel = parallelImpedance(ZR_L, ZC);

    cout << "Formula: Z = (Z1 * Z2) / (Z1 + Z2)\n";

    cout << "Combined R-L impedance: "
         << ZR_L << " ohms\n";

    cout << "Total parallel impedance: "
         << ZParallel << " ohms\n";

    cout << "Magnitude               : "
         << ZParallel.magnitude() << " ohms\n";


    cout << "\n6. DIVISION BY ZERO TEST\n";

    Complex numerator(10, 5);
    Complex zeroImpedance;

    try
    {
        Complex result = numerator / zeroImpedance;

        cout << "Result: " << result << endl;
    }
    catch (const domain_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }


    cout << "\n========================================\n";
    cout << "       PROGRAM EXECUTION COMPLETED\n";
    cout << "========================================\n";

    return 0;
}
