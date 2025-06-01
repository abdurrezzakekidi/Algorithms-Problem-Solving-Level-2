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

void PrintAllDigitsFrequencey(int Number)
{
    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = 0;
        DigitFrequency = CountDigitFrequency(i, Number);

        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is "  // Print the digit and its frequency.
                << DigitFrequency << " Time(s).\n";
        }
    }
}
int main()
{
    int Number = ReadPositiveNumber("Please enter the a number?");
    // Print the frequency of each digit (0-9) in the entered number.
    PrintAllDigitsFrequencey(Number);

    return 0;

}
