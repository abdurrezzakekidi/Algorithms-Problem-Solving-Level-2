#include <iostream>   
#include <string>     
#include <cstdlib>    
#include <ctime>      

using namespace std;

int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintArray(int arr[100], int arrLength)
{
    cout << "\nArray Elements: [ ";
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(0, 100);
        cout << arr[i] << ", ";
    }
    cout << "]";
    cout << endl;
}

int SumNumberArray(int arr[100], int arrLength)
{
    int SumArray = 0;

    for (int i = 0; i < arrLength; i++)
    {
        SumArray += arr [i];
    }
    return SumArray;
}

int main()

{
    srand((unsigned)time(NULL));

    int arr[100];
    int length = ReadPositiveNumber("Please enter number of elements: ");

    PrintArray(arr, length);


    cout << "\nSum of all number is: " << SumNumberArray(arr, length) << endl;




}