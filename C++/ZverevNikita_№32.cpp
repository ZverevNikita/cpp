#include <iostream>
#include <algorithm> 
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int array[7][7];
    int negative[7 * 7];
    int positive[7 * 7];
    int count = 0;
    
    cout << "Исходный двумерный массив, заполненный рандомными числами: " << endl;
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            array[i][j] = (rand() & 30) - 10;
        }
    }
    
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Отрицательные элементы двумерного массива с повторениями: " << endl;;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (array[i][j] < 0) 
            {
                cout << array[i][j] << " ";
            }
        }
    }
    cout << endl << endl;
    
    cout << "Положительные элементы двумерного массива с повторениями: " << endl;;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (array[i][j] > 0) 
            {
                cout << array[i][j] << " ";
            }
        }
    }
    cout << endl << endl;
    
    cout << "Отрицательные элементы двумерного массива по возрастанию без повторений: " << endl;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++) 
        {
            if (array[i][j] < 0) 
            {
                negative[count] = array[i][j];
                count++;
            }
        }
    }
    
    sort(negative, negative + count);
    auto element = unique(negative, negative + count);
    count = distance(negative, element);
    for (int i = 0; i < count; i++) 
    {
        cout << negative[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Положительные элементы двумерного массива по возрастанию без повторений: " << endl;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++) 
        {
            if (array[i][j] > 0) 
            {
                positive[count] = array[i][j];
                count++;
            }
        }
    }
    
    sort(positive, positive + count);
    auto elements = unique(positive, positive + count);
    count = distance(positive, elements);
    for (int i = 0; i < count; i++) 
    {
        cout << positive[i] << " ";
    }
}