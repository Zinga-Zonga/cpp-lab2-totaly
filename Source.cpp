/*Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы No1 с помощью созданных классов.
 Все функции оформить в виде методов классов.
В коде отразить следующее:
 Выделение и освобождение динамической памяти производить в конструкторах и деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации []. В классе Matrix добавить методы T at(int i, int j) const и
setAt(int i, int j, T val), которые позволяют получить и установить значение элемента массива с индексом [i][j],
 T – это тип элементов массива по варианту (int или double).
 Перегрузить операторы инкремента и декремента (как префиксного, так и постфиксного).
Смысл инкремента / декремента всего массива заключается в инкременте / декременте каждого элемента массива.*/

//Преобразование: 2D → 1D.Двумерный массив 5х5 целых чисел необходимо выложить в один ряд по элементам слева направо и сверху вниз,
//исключая все элементы на нечетных строках.
//Инициализация : заполнить массив факториалами : x[i][j] = i!+ j!.
//Вывод на экран : на каждый элемент массива отвести 8 позиций.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Vector.h"
#include "Matrix.h"
#include "Stadium.h"
#include "Fraction.h"

using namespace std;

int FindFactroial(int a);
void From2to1(Matrix &array2D,Vector &array1D);
void Task1();
void Task2();
void Task3();

int main()
{
    std::cout <<"Task 1"<< std::endl;
    Task1();
    std::cout << std::endl;
    std::cout << "Task 2" << std::endl;
    Task2();
    std::cout << std::endl;
    std::cout << "Task 3" << std::endl;
    Task3();
    std::cout << std::endl;

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
void From2to1(Matrix &array2D, Vector& array1D) {
    int k = 0;
    for (int i = 0; i < array2D.getRows(); i++) {
        for (int j = 0; j < array2D.getCols(); j++) {
            if (i % 2 == 0)
                continue;
            else
                array1D[k++] = array2D.at(i, j);

        }
    }
}

void Task1() {
    Matrix array2D(5, 5);
    Vector array1D(10);

    for (int i = 0; i < array2D.getRows(); i++) {
        for (int j = 0; j < array2D.getCols(); j++) {
            array2D.setAt(i, j, (FindFactroial(i) + FindFactroial(j)));
        }
    }
    
    array2D.printFormated();
    
    std::cout << " => \n" << std::endl;
    From2to1(array2D, array1D);
    std::cout << array1D << std::endl;

    std::cout << "postfix/prefix test" << std::endl;
    std::cout << "postfix" << std::endl;
    array1D++;
    std::cout << array1D;
    std::cout << "prefix" << std::endl;
    ++array1D;
    std::cout << array1D;
    std::cout << "postfix" << std::endl;
    array2D++;
    array2D.printFormated();
    std::cout << std::endl;
    std::cout << "prefix" << std::endl;
    ++array2D;
    array2D.printFormated();
    std::cout << std::endl;
    
}

void Task2()
{
    Fraction frac(6, 20);
    Fraction frac2(5, 20);
    Fraction frac3 = frac / frac2;
    frac.printFrac();
    frac2.printFrac();
    frac3.printFrac();
    char str[] = "0.25";
    double test = 0.25;
    frac.printAsFraction(str);
    frac.printAsFraction(test);
    std::cout << frac.getTotalFractions();
    std::cout << std::endl;
}

void Task3()
{
    Stadium* stad1 = new Stadium();
    Stadium* stad2 = new Stadium();
    Stadium stad3("Lebron str 28", "Lebor", 680, 20, 300);

    stad1->setAdress("Petrovsky distrikt.");
    stad1->setClub("Munchester");
    stad1->setCapacity(25000);
    stad1->setSectorsAmount(5);
    stad1->GenVisitors();
    stad1->serialize();

    stad2->setAdress("Kirovsky distrikt.");
    stad2->setClub("FC POBEDA");
    stad2->setCapacity(10000);
    stad2->setSectorsAmount(5);
    stad2->GenVisitors();
    stad2->serialize();

    stad3.GenVisitors();
    stad3.serialize();

    stad1->deserialize();

    //std::cout << *stad1;
    //std::cout << stad3;
}

