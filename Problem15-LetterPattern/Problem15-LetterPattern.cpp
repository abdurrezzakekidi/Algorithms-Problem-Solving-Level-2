#include <iostream>
#include <string>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
void PrintLetterPattern(int Number)
{
    for (int i = 65 ; i <= 65 + Number -1; i++)
    {
        for (int j = 1; j <= Number - ((65 + Number -1 ) - i) ; j++)
        {
            cout << char(i);
        }
        cout << endl;

    }
}
int main()
{
    PrintLetterPattern(ReadPositiveNumber("Please neter a positive number"));


}




