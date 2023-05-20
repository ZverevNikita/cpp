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
    cout << "Введите начальный диапазон: ";
    cin >> start;
    cout << "Введите конечный диапазон: ";
    cin >> end;
    string = string.erase(start, end - start + 1);
    cout << "Полученный фрагмент текста после удаления и склейки: " << string << endl;
}