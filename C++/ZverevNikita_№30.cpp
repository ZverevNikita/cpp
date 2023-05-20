#include <iostream>
#include <locale.h>

using namespace std;

class Matrix
{
private:
    int** array;
    int** array2;
    int rows, cols;
public:
    void Fill_array(int rows_value, int cols_value)
    {
        rows = rows_value;
        cols = cols_value;

        array = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            array[i] = new int[cols];
        }
        cout << "Исходный двумерный массив: " << endl;

        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                array[i][j] = (rand() % 10) + 1;
                string space = array[i][j] >= 10 ? " " : "  ";
                cout << array[i][j] << space;
            }
            cout << endl;
        }
        cout << endl;
    }

    void Change_rows_with_cols()
    {
        array2 = new int* [cols];
        for (int i = 0; i < cols; i++)
        {
            array2[i] = new int[rows];
        }
        cout << "Строки двумерного массива преобразованы в столбцы: " << endl;
        
        cout << endl;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                array2[i][j] = array[j][i];
                cout << array[i][j] << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    srand(time(0));
    Matrix first;
    first.Fill_array(5, 5);
    first.Change_rows_with_cols();
}