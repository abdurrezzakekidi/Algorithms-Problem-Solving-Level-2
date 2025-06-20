#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner RoundWinner;
    string WinnerName;
};
struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};


int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player1", "Computer", "NoWinner" };
    return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;

    }

    return enWinner::Player1;
}

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoice[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoice[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F"); // green 
        break;

    case enWinner::Computer:
        system("color 4F"); // red
        cout << "\a";
        break;

    case enWinner::Draw:
        system("color 6F"); // yellow
        break;
    }
}

void PrintRoundResults(stRoundInfo RounInfo)
{
    cout << "\n_____________Round [" << RounInfo.RoundNumber << "] _____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RounInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RounInfo.ComputerChoice) << endl;
    cout << "Round Winner  : [" << RounInfo.WinnerName << "] \n";
    cout << "_________________________________________\n" << endl;

    SetWinnerScreenColor(RounInfo.RoundWinner);

}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(short GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
    {
        stGameResults GameResults;

        GameResults.GameRounds = GameRounds;
        GameResults.Player1WinTimes = Player1WinTimes;
        GameResults.ComputerWinTimes = ComputerWinTimes;
        GameResults.DrawTimes = DrawTimes;
        GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
        GameResults.WinnerName = WinnerName(GameResults.GameWinner);

        return GameResults;
    }

enGameChoice ReadPlayer1Choice()
{
    short Choice = 1;

    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.RoundWinner);

        if (RoundInfo.RoundWinner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.RoundWinner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
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

void ShowGameOverScreen()
{
    cout << Tabs(2) << "___________________________________________________________\n\n";
    cout << Tabs(2) << "                +++ G a m e  O v e r +++\n";
    cout << Tabs(2) << "___________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
    cout << Tabs(2) << "________________________[Game Results ]________________________\n\n";
    cout << Tabs(2) << "Game Rounds         :" << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 won times   :" << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) << "Computer won times  :" << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw times          :" << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner        :" << GameResults.WinnerName << endl;
    cout << Tabs(2) << "___________________________________________________________________\n\n";

    SetWinnerScreenColor(GameResults.GameWinner);
}

short ReadHowManyRounds()
{
    short GameRounds = 0;

    do
    {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);

    return GameRounds;
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << endl << Tabs(3) << "Do you want to play again Y/N?";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');



}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();

    return 0;
}