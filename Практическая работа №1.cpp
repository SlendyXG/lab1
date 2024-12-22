// Практическая работа №1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <Windows.h>
#include <stdio.h>
HANDLE console = ::GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    //1 задание
    setlocale(0, "");
    cout << "int:" << sizeof(int) << " байт\n";
    cout << "short int:" << sizeof(short int) << " байт\n";
    cout << "long int:" << sizeof(long int) << " байт\n";
    cout << "float:" << sizeof(float) << " байт\n";
    cout << "double:" << sizeof(double) << " байт\n";
    cout << "long double:" << sizeof(long double) << " байт\n";
    cout << "char:" << sizeof(char) << " байт\n";
    cout << "bool:" << sizeof(bool) << " байт\n";
    
    //2 задание
    
    cout << "Представление целого числа в памяти компьютера";
    signed int a;
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    cout << "\nВведите целое число:";
    cin >> a;
    for (int i = 0; i < sizeof(int) * 8 ; ++i, mask>>=1) {
        putchar(a & mask ? '1' : '0');
        if ( i == 0 || i % 8 == 0) {
            cout << ' ';
        }
        if (i == 0) {
            SetConsoleTextAttribute(console, FOREGROUND_RED);
        }

     
    }
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    //3 задание
    unsigned int mask2 = 1 << (sizeof(float) * 8 - 1);
    cout <<"\nПредставление вещественного числа в памяти компьютера";
    union{
         float c;
         int b;
    };
    cout << "\nВведите вещественное число:";
    cin >> c;
    for (int i = 0; i <= (sizeof(float) * 8) -1; i++, mask2 >>= 1) {
        putchar(b & mask2 ? '1' : '0');
        if (i % 8 == 0) {
            cout << ' ';
        }
        if (i == 0) {
            SetConsoleTextAttribute(console, FOREGROUND_RED);
        }
        else if (i / 8 == 1) {
            SetConsoleTextAttribute(console, FOREGROUND_GREEN);
        }
        
    }
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    //4 задание
    int mask3 = 1 << (sizeof(int) * 8 - 1);
    cout << "\nПредставление вещественного числа double в памяти компьютера";
    union {
        double d;
        unsigned int e[2];
    };
    cout << "\nВведите вещественное число типа double:";
    cin >> d;
    for (int j = 1; j >= 0; --j) {
        for (int i = 1; i <= (sizeof(int) * 8); i++, mask3 >>= 1) {

            putchar(e[i] & mask3 ? '1' : '0');
            if ((i == 1 && j == 1)) {
              
                cout << " ";
                SetConsoleTextAttribute(console, FOREGROUND_RED);
            }
            if (i == 12 && j == 1) {
                
                cout << " ";
                SetConsoleTextAttribute(console, FOREGROUND_GREEN);
            }
        }
        mask3 = 1 << 31;
    }
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}
