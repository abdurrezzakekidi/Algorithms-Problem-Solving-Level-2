#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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
void FillArray(int arr[100], int& arrLength)
{

    for (int i = 0; i < arrLength; i++) {
        arr[i] = ReadPositiveNumber("Please enter a number");

    }
}

void PrintArray(int arr[100], int arrLength)
{
    cout << "\nArray Elements: [ ";
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << ", ";
    cout << "]";
    cout << endl;

    
}

bool IsPalindromeArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] != arr[Length - 1 - i])
        {
            return false;
        }
    };
    return true;
}







int main()
{
    

    int arrLength = ReadPositiveNumber("Enter the number of elements in array");
    int arr[100];
    FillArray(arr, arrLength);

    cout << "\nArray 1 elements:\n";
   PrintArray(arr, arrLength);

   if(IsPalindromeArray(arr, arrLength))
       cout << "\nYes array is Palindrome\n";
   else
       cout << "\No array is NOT Palindrome\n";

    return 0;
}
