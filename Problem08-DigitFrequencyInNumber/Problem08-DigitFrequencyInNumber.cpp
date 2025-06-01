#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int ReadPositiveNumber(string Message)
{
    long int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}


int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Remainder = 0;
    int FreqCount = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;

        if (Remainder == DigitToCheck)
        {
            FreqCount++;
        }

    }
    return FreqCount;
}


int main()
{
    long int Number = ReadPositiveNumber("Please neter a positive number?");
    short DigitCheck = ReadPositiveNumber("Please enter a digit to check(0-9)");

    cout << "\nDigit " << DigitCheck << "Frequency is "
        << CountDigitFrequency(DigitCheck, Number) << "Time(s).\n";

    return 0;

}
