//Преобразование: 2D → 1D.Двумерный массив 5х5 целых чисел необходимо выложить в один ряд по элементам слева направо и сверху вниз,
//исключая все элементы на нечетных строках.
//Инициализация : заполнить массив факториалами : x[i][j] = i!+ j!.
//Вывод на экран : на каждый элемент массива отвести 8 позиций.

#include <iostream>
#include <iomanip>


using namespace std;

void InitializeArray(int** arr2D, int arrRows, int arrCols);
void Print2DArray(int** arr2D, int arrRows, int arrCols);

void Delete2DArray(int** arr2D, int arrRows, int arrCols);
int FindFactroial(int a);
int* Make1D(int** arr2D, int arrRows, int arrCols);
void Print1D(int* arr1D, int length);
void Delete1D(int* arr1D);

int main()
{
    const int arrCols = 5;
    const int arrRows = 5;
    int** arr2D = new int* [arrRows];
    int* arr1D;
    

    InitializeArray(arr2D, arrCols, arrRows);
    Print2DArray(arr2D, arrRows, arrCols);
    cout << "<=" << endl;
    arr1D = Make1D(arr2D, arrRows, arrCols);
    Print1D(arr1D, (arrRows / 2) * arrCols);
    Delete1D(arr1D);
    Delete2DArray(arr2D,  arrRows, arrCols);
    
    
    return 0;
}

int FindFactroial(int a) {
    if (a == 0) {
        return 1;
    }
    else {
        return a * FindFactroial(a - 1);
    }
}

void InitializeArray(int** arr2D, int arrRows, int arrCols) {
    for (int i = 0; i < arrRows; i++) {
        *(arr2D+i) = new int[arrRows];
    }
    for (int i = 0; i < arrRows; i++) {
        for (int j = 0; j < arrCols; j++) {
            int factI = FindFactroial(i);
            int factJ = FindFactroial(j);
            *(*(arr2D + i)+j) = factI + factJ;
        }
    }
}

void Print2DArray(int** arr2D, int arrRows, int arrCols) {
    
    for (int i = 0; i < arrRows; i++) {
        for (int j = 0; j < arrCols; j++) {
            cout << *(*(arr2D + i) + j) << "\t";
        }
        cout << endl;
    }
    
}

void Delete2DArray(int** arr2D, int arrRows, int arrCols) {
    for (int i = 0; i < arrRows; i++) {
        delete *(arr2D + i);
    }
    delete [] arr2D;
}

int* Make1D(int** arr2D, int arrRows, int arrCols) {

    int size = (arrRows / 2) * arrCols;
    int* arr1D = new int[size];
    int counter = 0;

    for (int i = 0; i < arrRows; i++) {
        if (i % 2 == 0)
            continue;
        for (int j = 0; j < arrCols; j++) {
            *(arr1D + counter) = *(*(arr2D + i) + j);
            counter++;
        }
    }

    return arr1D;
}

void Print1D(int* arr1D, int length) {
    cout << "[\t";
    for (int i = 0; i < length; i++) {
       /* if (i % 8 == 0 && i != 0)
            cout << endl;*/
        cout << setw(8) << *(arr1D + i) << "\t";
    }
    cout << " ]";
}

void Delete1D(int* arr1D) {
    delete [] arr1D;
}





