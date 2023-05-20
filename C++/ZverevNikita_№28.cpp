#include <iostream>
#include <locale.h>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int m, n;
    cout << "Введите количество строк в массиве: ";
    cin >> m;
    cout << "Введите количество столбцов в массиве: ";
    cin >> n;
    int **array = new int*[m];
    cout << endl;
    
    cout << "Исходный двумерный массив, заполненный рандомными числами: " << endl;
    
    cout << endl;
    for (int i = 0; i < m; i++) 
    {
        array[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            array[i][j] = (rand() % 79) + 7;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string space = array[i][j] >= 10 ? " " : " ";
            cout << array[i][j] << space;
        }
        cout << endl;
    }
    cout << endl;
    int first = 0;
    cout << "Введите номер столбца двумерного массива, который нужно обнулить: ";
    cin >> first;
    first -= 1;
    for(int i = 0; i < m; i++)
    {
        array[i][first] = 0;
    }
    cout << endl;
    cout << "Полученный двумерный массив с занулением столбца: " << endl;
    
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string space = array[i][j] >= 10 ? " " : " ";
            cout << array[i][j] << space;
        }
        cout << endl;
    }
}