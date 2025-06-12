#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int MyFloor(float Number)
{
    int IntPart;
    IntPart = int(Number);

    if (Number > 0)
        return IntPart;
    else
        return --IntPart;
}
float ReadNumber()
{
    float Number;


    cout << "Please enter a number? ";
    cin >> Number;

    return Number;
}


int main()
{
    float Number = ReadNumber();

    cout << "My Floor Result : " <<MyFloor(Number) << endl;
    cout << "C++ Floor Result: " << floor(Number) << endl;

    return 0;
}