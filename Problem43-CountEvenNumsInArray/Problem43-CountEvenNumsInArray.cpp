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
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "Enter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(0, 100);
}
void PrintArray(int arr[100], int arrLength)
{
    cout << "\nArray Elements: [ ";
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << ", ";
    cout << "]";
    cout << endl;


}

int EvenNumbersCount(int arr[100], int arrLength)
{
    int evenCount = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
            evenCount++;
    }
    return evenCount;
}


int main()
{
    srand((unsigned)time(NULL));

    int arrLength, arr[100];

    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);

    cout << "\nCount of even numbers in array is :" << EvenNumbersCount(arr, arrLength) << endl;


    return 0;
}
