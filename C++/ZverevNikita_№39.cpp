#include <iostream>
#include <locale.h>

using namespace std;

void allocateMemory(double*& array, int size) {
    array = new double[size];
}

void fillArray(double* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;
    }
}

void printArray(double* array, int size) {
    cout << "Заполненный одномерный массив рандомными числами: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void freeMemory(double* array) {
    delete[] array;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int size;
    string choice;
    while (true)
    {
        cout << "Введите размер одномерного массива: ";
        cin >> size;
        double* array;
        allocateMemory(array, size);
        fillArray(array, size);
        printArray(array, size);
        freeMemory(array);
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

