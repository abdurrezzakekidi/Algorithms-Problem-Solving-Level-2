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
enum enCharType {
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
    {
        return char(RandomNumber(97, 122));
        break;
    }
    case CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
        break;
    }
    case Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }
}
void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\n Array elements:\n\n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Array[" << i << "] : ";
        cout << arr[i] << "\n";
    }
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
string GenerateWord(enCharType CharType, short Lenght)
{
    string Word = "";
    for (int i = 1; i <= Lenght; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}
string GenerateKey()
{
    string Key = "";
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

    return Key;
}

void FillArrayWithKeys(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
}

int main()
{

    srand((unsigned)time(NULL));

    string arr[100];
    int arrLength = 0;
    arrLength = ReadPositiveNumber("How many keys do you want to generate?\n");

    FillArrayWithKeys(arr, arrLength);
    PrintStringArray(arr, arrLength);


    return 0;

}