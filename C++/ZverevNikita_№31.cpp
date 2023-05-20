#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int m, n, str;
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
            array[i][j] = rand() % 41 - 20;
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
    cout << "Вывод только положительных элементов двумерного массива по возрастанию: " << endl;
    
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] > 0)
            {
                string space = array[i][j] >= 10 ? " " : " ";
                cout << array[i][j] << space;
            }
        }
    }
}