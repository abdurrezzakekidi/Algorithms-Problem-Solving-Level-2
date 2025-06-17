#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enQuestionsLevel { Easy = 1, Medium = 2, Hard = 3, MixLevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };


struct stQuestion
{
    int Number1;
    int Number2;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionsLevel QuestionLevel;
    enOperationType OpType;
    short RightAnswers = 0;
    short WrongAnswers = 0;
    bool isPass = false;
};


int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enOperationType GetRandomOperation()
{
    int Op = RandomNumber(1, 4);
    return (enOperationType)Op;
}

string GetQuestionLevel(enQuestionsLevel level)
{
    string arrLevelChoice[4] = { "Easy", "Medium", "Hard", "Mix" };
    return arrLevelChoice[level - 1];
}

string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mult:
        return "X";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

int LevelInQuestions(enQuestionsLevel QuizLevel)
{
    if (QuizLevel == MixLevel)
        QuizLevel = (enQuestionsLevel)RandomNumber(1, 3); // Easy-Medium-Hard'tan biri

    switch (QuizLevel)
    {
    case Easy: return RandomNumber(1, 9);
    case Medium: return RandomNumber(10, 49);
    case Hard: return RandomNumber(50, 99);
    default: return RandomNumber(1, 99);
    }
}

enQuestionsLevel ReadQuestionsLevel()
{
    short QuestionLevel = 1;

    do
    {
        cout << "\nYour Choice: [1]:Easy, [2]:Medium, [3]:Hard, [4]:Mix ?";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuestionsLevel)QuestionLevel;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mult:
        return Number1 * Number2;
    case enOperationType::Div:
        return (Number2 != 0) ? (Number1 / Number2) : 0;  // Avoid division by zero.
    default:
        return Number1 + Number2;
    }
}

enOperationType ReadOpType()
{
    short OpTypeChoice = 1;

    do
    {
        cout << "\nYour Choice: [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ?";
        cin >> OpTypeChoice;
    } while (OpTypeChoice < 1 || OpTypeChoice > 5);

    return (enOperationType)OpTypeChoice;
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionsLevel::MixLevel)
        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);

    if (OpType == enOperationType::MixOp)
        OpType = GetRandomOperation();

    Question.OperationType = OpType;

    switch (QuestionLevel)
    {
    case enQuestionsLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuestionsLevel::Medium:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuestionsLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    }
    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    Question.QuestionLevel = QuestionLevel;

    return Question;
}

void GenrateQuizzQuestions(stQuizz& Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OpType);
    }
}

int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "\n";
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << endl;
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n__________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.WrongAnswers++;

        cout << "Worng Answer :-( \n";
        cout << "The rigth answer is: ";
        cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
        cout << "\n";
    }
    else
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.RightAnswers++;

        cout << "Rigth Answer :-) \n";
    }
    cout << endl;
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void SetScreenColor(bool isCorrect) {
    if (isCorrect)
        system("color 2F"); // Yeşil - doğru
    else
        system("color 4F"); // Kırmızı - yanlış
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);

        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }

    Quizz.isPass = (Quizz.RightAnswers >= Quizz.WrongAnswers);
}

string GetFinalResultsText(bool Pass)
{
    if (Pass)
        return "PASS :-)";
    else
        return "FAIL : -(";
}

short ReadHowManyQestion()
{
    short Question = 0;

    do
    {
        cout << "How Many Questions do you want to answer? \n";
        cin >> Question;
    } while (Question < 1 || Question > 10);

    return Question;
}

void PrintQuizzResults(stQuizz Quizz)
{
    cout << "\n";
    cout << "____________________________\n\n";
    cout << "Final Results is " << GetFinalResultsText(Quizz.isPass);
    cout << "\n\n_______________________\n\n";

    cout << "Number Of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "Questionss Level   :" << GetQuestionLevel(Quizz.QuestionLevel) << endl;
    cout << "OpType             :" << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number of Right Answers :" << Quizz.RightAnswers << endl;
    cout << "Number of Wrong Answers :" << Quizz.WrongAnswers << endl;
    cout << "___________________________________\n";
}

stQuizz PlayMathGame()
{
    stQuizz Quiz;
    Quiz.NumberOfQuestions = ReadHowManyQestion();
    Quiz.QuestionLevel = ReadQuestionsLevel();
    Quiz.OpType = ReadOpType();

    GenrateQuizzQuestions(Quiz);
    AskAndCorrectQuestionListAnswers(Quiz);
    PrintQuizzResults(Quiz);

    return Quiz; // Return the Quiz object
}

void ResetScreen()
{
     system("cls"); // geçici olarak kapat
    system("color 0F");
}

void StartQuiz()
{
    cout << "StartQuiz başladı! Giris ekranı birazdan gelecek...\n"; // Test satırı
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stQuizz QuizResult = PlayMathGame();
        cout << "Do you want  to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartQuiz();
    system("pause");

    return 0;
}