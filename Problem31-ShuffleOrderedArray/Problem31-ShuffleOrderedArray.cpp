#include <iostream>  
using namespace std;

int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = i+1;
}
void swap(int& A, int& B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
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
void ShuffleArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        int index1 = RandomNumber(1, arrLength) - 1;
        int index2 = RandomNumber(1, arrLength) - 1;
        swap(arr[index1], arr[index2]);
    }
}
void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int main() {

    srand((unsigned)time(NULL));

    int arr1[100];

    int arrLength;

    FillArray(arr1, arrLength);

    cout << "\nArray elements before shuffle:\n";
    PrintArray(arr1, arrLength);

    // Shuffle the array elements randomly.
    ShuffleArray(arr1, arrLength);

    // Print the array after shuffling.
    cout << "\nArray elements after shuffle:\n";
    PrintArray(arr1, arrLength);


    

    
    return 0;
}