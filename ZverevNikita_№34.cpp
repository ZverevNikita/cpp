#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int start, end;
    string string;
    cout << "Введите строку: ";
    getline(cin, string);
    cout << "Введите начальную точку диапазона: ";
    cin >> start;
    cout << "Введите конечную точку диапазона: ";
    cin >> end;
    string = string.substr(start, end - start + 1);
    cout << "Вырезанный фрагмент текста: " << string << endl;
}