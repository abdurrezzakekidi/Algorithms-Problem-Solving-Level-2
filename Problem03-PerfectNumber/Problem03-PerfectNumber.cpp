#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int ReadPositiveNumber(string Message)
{
    float Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

bool IsPerfectNumber(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum += i;
    }
    return Number == Sum;
}

void PrintResult(int Number)
{
    if (IsPerfectNumber(Number))
        cout << Number << " is Perfect Number.";
    else
        cout << Number << " is not Perfect Number";
}


int main()
{

    PrintResult(ReadPositiveNumber("Please enter a Positive number"));


}
