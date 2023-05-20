#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#include <fstream>
 
using namespace std;
 
void DeleteAllSpaces(string& text)
{
    auto start{ text.find(" ") };
    while (start != string::npos)
    {
        text.erase(start, 1);
        start = text.find(" ");
    }
}

void NormalizeLine(string& text, string& result)
{
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
}
 
int main()
{
    setlocale(LC_ALL, "Russian");
    const string filename = "file.txt";
    string result = "";
    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            string tmpLine = "";
            NormalizeLine(line, tmpLine);
            result += tmpLine + "\n";
        }
 
        result.erase(result.length() - 1); 
        myfile.close();
    }
    ofstream myfile1(filename);
    if (myfile1.is_open())
    {
        myfile1 << result;
        myfile1.close();
    }
}