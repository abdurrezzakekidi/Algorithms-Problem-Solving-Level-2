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
        arr[i] = RandomNumber(-100, 100);
}
void PrintArray(int arr[100], int arrLength)
{
    cout << "\nArray Elements: [ ";
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << ", ";
    cout << "]";
    cout << endl;


}

int NegativeNumbersCount(int arr[100], int arrLength)
{
    int negativeCount = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < 0)
            negativeCount++;
    }
    return negativeCount;
}


int main()
{
    srand((unsigned)time(NULL));

    int arrLength, arr[100];

    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);

    cout << "\nCount of Negative numbers in array is :" << NegativeNumbersCount(arr, arrLength) << endl;


    return 0;
}
