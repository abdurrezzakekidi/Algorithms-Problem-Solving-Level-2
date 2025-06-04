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
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << ", ";

    cout << endl;
}
void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
}

int main()

{
    srand((unsigned)time(NULL));

    int arr[100];
    int length;

    FillArrayWithRandomNumbers(arr, length);

    int arrCopy[100];

    CopyArray(arr, arrCopy, length);

    cout << "\n Orginal array elements : ";
    PrintArray(arr, length);

    cout << "\n Copied array elements : ";
    PrintArray(arrCopy, length);

    return 0;

}