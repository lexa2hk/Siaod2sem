#include <iostream>
#include <string>
using namespace std;

//Функция вывода на экран с помощью поразрядных операций (упр. 1-5)
void coutp(unsigned int x)
{
    int n=sizeof(int)*8;
    unsigned maska=1<<(n-1);
    for(int i=0; i<n; i++)
    {
        cout<<(x&maska ? '1':'0');
        x<<=1;
    }
}

//Функция установки четных битов в единицу с помощью поразрядных операций (упр. 1)
unsigned int set_even_1(unsigned int inp){
    return inp|0b10101010101010101010101010101010;
}

//Функция установки 11, 9, 7 битов в единицу с помощью поразрядных операций (упр. 2)
unsigned int set_11_9_7_to_1(unsigned int inp){
    return inp|0b101010000000;
}

//Функция умножения на 16 с помощью поразрядных операций (упр. 3)
unsigned int multiply_by_16(unsigned int inp){
    return inp<<4;
}

//Функция деления на 16 с помощью поразрядных операций (упр. 4)
unsigned int divide_by_16(unsigned int inp){
    return inp>>4;
}

//Функция установки n-ого бита в 0 с помощью поразрядных операций и маски 1 (упр. 5)
unsigned int zero_nth_bit(unsigned int inp, unsigned int n){
    return inp & ~(1<<n);
}



int main() {
    system("chcp 65001");


    //create switch-case menu for 5 elements where 0 calls exit
    int choice=1;
    unsigned int inp;

    while(choice!=0){
        cout<<"Лабораторная работа №1. 'Поразрядные операции и их применение'. Смольников Алексей. Вариант 3"<<endl;
        cout<<"Выберите номер задания (0-выход)"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Задание 1. Установить четные биты переменной целого типа в 1:"<<endl;
                cout<<"Число 16"<<endl;
                cout<<"Двоичное представление: ";
                coutp(0x10);
                cout<<endl;
                cout<<"Результат: ";
                coutp(set_even_1(0x10));
                cout<<endl;
                break;
            case 2:
                cout<<"Задание 2. Установить биты 11, 9, 7 в 1:"<<endl;
                cout<<"Введите число: ";
                cin>>inp;
                cout<<"Двоичное представление: ";
                coutp(inp);
                cout<<endl;
                cout<<"Результат: ";
                coutp(set_11_9_7_to_1(inp));
                cout<<endl;
                break;
            case 3:
                cout<<"Задание 3. Умножить число на 16:"<<endl;
                cout<<"Введите число: ";
                cin>>inp;
                cout<<"Двоичное представление: ";
                coutp(inp);
                cout<<endl;
                cout<<"Результат: ";
                coutp(multiply_by_16(inp));
                cout<<endl;

                break;
            case 4:
                cout<<"Задание 4. Разделить число на 16:"<<endl;
                cout<<"Введите число: ";
                cin>>inp;
                cout<<"Двоичное представление: ";
                coutp(inp);
                cout<<endl;
                cout<<"Результат: ";
                coutp(divide_by_16(inp));
                cout<<endl;
                break;
            case 5:
                cout<<"Задание 5. Обнулить n-ый бит:"<<endl;
                cout<<"Введите число: ";
                cin>>inp;
                cout<<"Введите номер бита: ";
                unsigned int n;
                cin>>n;
                cout<<"Число "<<inp<<endl;
                cout<<"Двоичное представление: ";
                coutp(inp);
                cout<<endl;
                cout<<"Результат: ";
                coutp(zero_nth_bit(inp, n));
                cout<<endl;

                break;
            default:
                break;
        }
    }

    return 0;
}
