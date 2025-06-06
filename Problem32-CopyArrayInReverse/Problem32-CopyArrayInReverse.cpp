#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements: ";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

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

void PrintArray(int arr[100], int arrLength)
{
    cout << "[ ";
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << ", ";
    cout << "]\n";
}

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[arrLength - 1 - i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[100], arr2[100], arrLength;

    FillArray(arr1, arrLength);
    CopyArrayInReverseOrder(arr1, arr2, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr1, arrLength);

    cout << "\nArray 2 elements (Reversed):\n";
    PrintArray(arr2, arrLength);

    return 0;
}
