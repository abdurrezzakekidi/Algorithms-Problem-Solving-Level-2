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
        cout << arr[i] << " ";

    cout << endl;
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
short FindNumberPositionInArray(int SearchNumber, int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {

        if (arr[i] == SearchNumber)
            return i; // Return the index immediately when the number is found.

    }

    // If the loop completes without finding the number, return -1.
    return -1;
}
bool IsNumberInArray(int SearchNumber, int arr[100], int arLength)
{
    return FindNumberPositionInArray(SearchNumber, arr, arLength) != -1;
}


int main()

{
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength;


    FillArrayWithRandomNumbers(arr, arrLength);


    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);


    int Number = ReadPositiveNumber("Please enter Search Number ");
    cout << "\nNumber you are looking for is: " << Number << endl;


    if (!IsNumberInArray(Number, arr, arrLength))
        cout << "No The number is not found : (\n";
    else
    {
        cout << "Yes it is found :-)\n";
    }

   
    return 0;
}
