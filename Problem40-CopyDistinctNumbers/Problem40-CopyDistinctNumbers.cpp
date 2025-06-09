#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << endl;
}

short FindNumberInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }
    return -1; // number not found
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberInArray(Number, arr, arrLength) != -1;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
    DestinationLength = 0;  // 💡 Hataları önlemek için başlangıç değeri atandı

    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arrSource[100], SourceLength = 0;
    int arrDestination[100], DestinationLength = 0;

    FillArray(arrSource, SourceLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arrSource, SourceLength);

    CopyDistinctNumbersToArray(arrSource, arrDestination, SourceLength, DestinationLength);

    cout << "\nArray 2 (distinct elements):\n";
    PrintArray(arrDestination, DestinationLength);

    return 0;
}
