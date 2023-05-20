#include <iostream>
#include <fstream>
#include <locale.h>

using namespace std;

int main()
{
    string words[100];
    int count, number;
    ifstream infile("EnglishWords.txt");
    count = 0;
    while (infile >> words[count])
    {
        count++;
    }
    number = count;
    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - i - 1; j++)
        {
            if (words[j] > words[j + 1])
            {
                string result = words[j];
                words[j] = words[j + 1];
                words[j + 1] = result;
            }
        }
    }
    ofstream outfile("SortedEnglishWords.txt");
    for (int i = 0; i < number; i++)
    {
        outfile << words[i] << endl;
    }
    infile.close();
    outfile.close();
    cout << "Слова отсортированы в алфавитном порядке!";
}