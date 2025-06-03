#include <iostream>
#include <string>
using namespace std;
string ReadText()
{
    string Text;

    cout << "Please enter Text)\n";
    getline(cin, Text);

    return Text;
}

string EncryptText(string Text, short EncryptKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptKey);
    }
    return Text;
}

string DecrypText(string Text, short EncryptKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptKey);
    }
    return Text;
}

int main()
{

    const short Encryptkey = 3;

    string Text = ReadText();
    string TextAfterEncryption = EncryptText(Text, Encryptkey);
    string TextAfterDecryption = DecrypText(TextAfterEncryption, Encryptkey);

    cout << "\n Text Before Encryption : " << Text << endl;
    cout << "Text After Encryption : " << TextAfterEncryption << endl;
    cout << "Text After Decryption : " << TextAfterDecryption << endl;

}




