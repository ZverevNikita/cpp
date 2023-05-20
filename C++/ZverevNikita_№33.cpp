#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    cout << "Введите строку: ";
    getline(cin, str);
    int count = 0;
    for (int i = 0; i < str.size(); i++) 
    {
        count++;
    }
    cout << "Количество символов в данной строке: " << count << endl;
}
