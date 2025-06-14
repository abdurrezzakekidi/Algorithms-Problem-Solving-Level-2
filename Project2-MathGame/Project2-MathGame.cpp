#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}







string Tabs(short NumberOfTabs)
{

    string TabsString = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        TabsString = TabsString + "\t";
        cout << TabsString;
    }
    return TabsString;

}

int main()
{
    srand((unsigned)time(NULL));
    
    
    return 0;
}