#include <iostream>   
#include <string>     
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for the time() function.

using namespace std;  

int RandomNumber(int From, int To)
{
   
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

int main() {

    // Seed the random number generator with the current time.
  // This ensures that we get a different sequence of random numbers on each run.
    srand((unsigned)time(NULL));

    cout << RandomNumber(20, 50) << endl;
    cout << RandomNumber(20, 78) << endl;
    cout << RandomNumber(1, 10) << endl;

}