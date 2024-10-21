#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void SwapMinMaxInOddColumns(int** a, const int rowCount, const int colCount, int j = 0, int i = 1, int minRow = 0, int maxRow = 0);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

   
    Create(a, rowCount, colCount, Low, High);

    
    cout << "" << endl;
    Print(a, rowCount, colCount);

    
    SwapMinMaxInOddColumns(a, rowCount, colCount);

   
    cout << "" << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i >= rowCount) return; 

    a[i][j] = Low + rand() % (High - Low + 1);

    if (j + 1 < colCount) 
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else 
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i >= rowCount) return; 

    cout << setw(4) << a[i][j]; 

    if (j + 1 < colCount) 
        Print(a, rowCount, colCount, i, j + 1);
    else 
    {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
    }
}

void SwapMinMaxInOddColumns(int** a, const int rowCount, const int colCount, int j, int i, int minRow, int maxRow)
{
    if (j >= colCount) return; 

    if (i < rowCount) 
    {
        
        if (a[i][j] < a[minRow][j]) minRow = i;
        if (a[i][j] > a[maxRow][j]) maxRow = i;

        SwapMinMaxInOddColumns(a, rowCount, colCount, j, i + 1, minRow, maxRow);
    }
    else 
    {
        int temp = a[minRow][j];
        a[minRow][j] = a[maxRow][j];
        a[maxRow][j] = temp;

        SwapMinMaxInOddColumns(a, rowCount, colCount, j + 2, 1, 0, 0); 
    }
}
