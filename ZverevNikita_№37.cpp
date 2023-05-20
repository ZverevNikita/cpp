#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
 
using namespace std;
 
void DeleteAllSpaces(std::string& text)
{
    auto start{ text.find(" ") };
    while (start != string::npos)
    {
        text.erase(start, 1);
        start = text.find(" ");
    }
}
 
int main()
{
    setlocale(LC_ALL, "Russian");
    string text;
    cout << "Введите текст: ";
    getline(cin, text);
    string separators{ " ,." };
    vector<string> list;
    auto startIndex = 0;
    while (startIndex <= text.length())
    {
        auto endIndex = text.find_first_of(separators, startIndex);
        if (endIndex == string::npos) endIndex = text.length();
        string word = text.substr(startIndex, endIndex - startIndex);
        if (word != "") list.push_back(word);
        startIndex = endIndex + 1;
    }
    DeleteAllSpaces(text);
    string result = "";
    auto current = 0;
    for (string word : list)
    {
        int wordlen = word.length();
        auto wordIndex = text.find(word, current);
        if (current > 0)
        {
            char testDot = text.at(wordIndex - 1);
            char title = word.at(0);
            word.erase(0, 1);
            if (testDot == '.')
                word.insert(0, 1, toupper(title));
            else
                word.insert(0, 1, tolower(title));
        }
        else 
        {
            char title = word.at(0);
            word.erase(0, 1);
            word.insert(0, 1, tolower(title));
        }
        if (wordIndex + wordlen >= text.length())
        {
            result += word;
            break;
        }
        char lastWordChar = text.at(wordIndex + wordlen);
        if (lastWordChar == ',' || lastWordChar == '.')
            result += word + lastWordChar + " ";
        else
            result += word + " ";
 
        current = wordIndex + wordlen;
    }
    cout << "Отформатированный исходный текст: " << result << endl;
}