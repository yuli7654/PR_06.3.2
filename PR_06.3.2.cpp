// Лабораторна робота № 6.3, варіант 20 (рекурсивний спосіб)
// Пошук найбільшого елемента масиву: звичайна та шаблонна рекурсивні функції
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// Формування масиву випадкових чисел від Low до High
void Create(int* a, const int size, const int Low, const int High, int i = 0)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Універсальний шаблон для виведення масиву в рядок
template <typename T>
void Print(T* a, const int size, int i = 0)
{
    cout << setw(8) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Звичайна функція: пошук найбільшого елемента масиву int
// Виклик: Max(a, size, 0)  (i - індекс поточного елемента)
int Max(int* a, const int size, int i)
{
    if (i == size - 1)              // останній елемент - кінець рекурсії
        return a[i];
    int m = Max(a, size, i + 1);    // найбільший серед решти елементів
    return a[i] > m ? a[i] : m;
}

// Шаблонна функція: пошук найбільшого елемента масиву будь-якого типу
template <typename T>
T Max(T* a, const int size, int i)
{
    if (i == size - 1)
        return a[i];
    T m = Max<T>(a, size, i + 1);
    return a[i] > m ? a[i] : m;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;

    // 1) Звичайна та шаблонна функції для int масиву
    int a[n];
    Create(a, n, -20, 50);
    cout << "int array:" << endl;
    Print(a, n);
    cout << "Max(a, n, 0)            = " << Max(a, n, 0) << endl;
    cout << "Max<int>(a, n, 0)       = " << Max<int>(a, n, 0) << endl << endl;

    // 2) Шаблонна функція для double масиву
    double b[n] = { 1.1, 12.2, 3.3, -4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    cout << "double array:" << endl;
    Print(b, n);
    cout << "Max<double>(b, n, 0)    = " << Max<double>(b, n, 0) << endl << endl;

    // 3) Шаблонна функція для string масиву
    string c[n] = { "apple", "pear", "plum", "kiwi", "lemon",
                    "orange", "melon", "peach", "grape", "fig" };
    cout << "string array:" << endl;
    Print(c, n);
    cout << "Max<string>(c, n, 0)    = " << Max<string>(c, n, 0) << endl;

    return 0;
}