#include "header.h"

int main()
{
    Fraction fraction1, fraction2;

    fraction1.input();
    cout << "Fraction 1: ";
    fraction1.output();
    fraction1.reduce();
    cout << endl;
    cout << "Fraction 1 after being reduced: ";
    fraction1.output();
    cout << endl;
    cout << "Is positive: " << fraction1.isPositive() << endl;
    cout << "Is nositive: " << fraction1.isNegative() << endl;
    cout << "Is zero: " << fraction1.isZero() << "\n\n";

    fraction2.input();
    cout << "Fraction 2: ";
    fraction2.output();
    fraction2.reduce();
    cout << endl;
    cout << "Fraction 2 after being reduced: ";
    fraction2.output();
    cout << endl;
    cout << "Is positive: " << fraction2.isPositive() << endl;
    cout << "Is nositive: " << fraction2.isNegative() << endl;
    cout << "Is zero: " << fraction2.isZero() << endl;
    cout << endl;

    Fraction fraction3 = addTwoFractions(fraction1, fraction2);
    fraction1.output();
    cout << " + ";
    fraction2.output();
    cout << " = ";
    fraction3.output();
    cout << endl;

    fraction3 = substractTwoFractions(fraction1, fraction2);
    fraction1.output();
    cout << " - ";
    fraction2.output();
    cout << " = ";
    fraction3.output();
    cout << endl;

    fraction3 = multiplyTwoFractions(fraction1, fraction2);
    fraction1.output();
    cout << " x ";
    fraction2.output();
    cout << " = ";
    fraction3.output();
    cout << endl;

    fraction3 = divideTwoFractions(fraction1, fraction2);
    if (fraction3.Denominator != 0)
    {
        fraction1.output();
        cout << " : ";
        fraction2.output();
        cout << " = ";
        fraction3.output();
        cout << endl;
    }
    cout << endl;


    short compare = fraction1.compare(fraction2);
    if (compare > 0)
    {
        fraction1.output();
        cout << " > ";
        fraction2.output();
    }
    
    else if (compare == 0)
    {
        fraction1.output();
        cout << " = ";
        fraction2.output();
    }

    else
    {
        fraction1.output();
        cout << " < ";
        fraction2.output();
    }
}