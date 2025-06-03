#include <iostream>
#include <string>
using namespace std;
string ReadPassword()
{
    string Password;

    cout << "Please enter a 3-Letter password (all capital ?)\n";
    cin >> Password;

    return Password;
}

bool GuessPassword(string OriginalPassword)
{
    string word = "";
    int counter = 0;

    cout << "\n";

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j<=90; j++)
        {
            for (int k = 65; k<=90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                
                counter++;

                cout << "Trial [" << counter << "] : " << word << endl;
                    // Check if the guessed word matches the original password.;
                if (word == OriginalPassword)
                    {
                        cout << "\nPassword is " << word << "\n";
                        cout << "Found after " << counter << " Trial(s)\n";

                        return true;  // Return true indicating the password was found.
                    }

                // Reset the word variable for the next guess.
                word = "";
            }
        }
    }

    return false;  // If no match was found (should not happen for valid 3-letter passwords), return false.
}

int main()
{
   
    GuessPassword(ReadPassword());

}




