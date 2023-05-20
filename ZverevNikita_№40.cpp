#include <iostream>
#include <locale.h>

using namespace std;

void allocateMemory(double**& array, int n, int m) 
{
    array = new double*[n];
    for (int i = 0; i < n; i++) 
    {
        array[i] = new double[m];
    }
}

void fillArray(double** array, int n, int m) 
{
    int minimum;
    cout << "Введите начальную точку диапазона: ";
    cin >> minimum;
    int maximum;
    cout << "Введите конечную точку диапазона: ";
    cin >> maximum;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            array[i][j] = (rand() % (maximum - minimum + 1)) + minimum;
        }
    }
}

void printArray(double** array, int n, int m) 
{
    cout << "Заполненный многомерный массив рандомными числами: ";
    cout << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void freeMemory(double** array, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        delete[] array[i];
    }
    delete[] array;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n, m;
    string choice;
    while (true) 
    {
        cout << "Введите количество строк многомерного массива: ";
        cin >> n;
        cout << "Введите количество столбцов многомерного массива: ";
        cin >> m;
        double** array;
        allocateMemory(array, n, m);
        fillArray(array, n, m);
        printArray(array, n, m);
        freeMemory(array, n);
        F:
        cout << "Вы хотите продолжить? (да/нет): ";
        cin >> choice;
        if (choice != "да" && choice != "нет")
        {
            cout << "Ошибка! Попробуйте заново! ";
            goto F;
        }
        if (choice == "нет")
        {
            break;
        }
    }
}
