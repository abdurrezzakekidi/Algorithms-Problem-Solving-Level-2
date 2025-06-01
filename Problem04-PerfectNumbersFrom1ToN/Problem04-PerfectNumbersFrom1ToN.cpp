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

bool IsPerfectNumber(int Number)
{
    long int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum += i;
    }
    return Number == Sum;
}

void PrintPerfectFrom1ToN(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        if (IsPerfectNumber(i))

            if (IsPerfectNumber(i) == true)
                cout << i << endl;
            else
                cout << "!!\n";


    }



}


int main()
{

    PrintPerfectFrom1ToN(ReadPositiveNumber("Please enter a Positive number"));


}
