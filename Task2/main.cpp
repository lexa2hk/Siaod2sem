//
// Created by lexa2k on 16.09.2022.
//
//https://drive.google.com/drive/folders/17AVqcu5P2GEqUStdI9vWSBUOAJ1k4Vz2

#include <iostream>
#include <string>

#include "textFile.h"
#include "bitFile.h"

using namespace std;

//cmake_minimum_required(VERSION 3.23)
//project(Siaod2sem)
//
//set(CMAKE_CXX_STANDARD 23)
//
//add_executable(Siaod2sem Task2/main.cpp)

int main(){
    system("chcp 65001");

    string fileName = "schedule.txt";
//    readFromFile(fileName);

    convertToBitFile(fileName, "schedule.bin");
    convertToTextFile("schedule.bin", "schedule2.txt");
    printBitFile("schedule.bin");

    return 0;
}

int main1(){
    system("chcp 65001");
    int task=-1;

    while ( task !=0 ){
        cout<<"Практическая работа 2. Смольников Алексей. ИКБО-10-21"<<endl;
        cout<<"Задание 1. Разработать программу, управления текстовым файлом."<<endl;
        cout<<"Задание 2. Разработать программу управления двоичными файлами с записями фиксированной длины. Общие требования: файл состоит из записей определенной структуры, согласно варианту. Записи имеют ключ, уникальный в пределах файла."<<endl;

        cout<<"Выберите задание: ";

        cin>>task;
        switch (task) {
            case 1: {
                cout<<"1 создание текстового файла кодировки ASCII, содержащего десятичные числа по несколько чисел на строке"<<endl;
                cout<<"2 вывод содержимого текстового файла"<<endl;
                cout<<"3 добавление в конец файла новой строки"<<endl;
                cout<<"4 прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение"<<endl;
                cout<<"5 (Вариант 22) Создать новый файл из значений исходного, размещая на каждой строке заданное количество чисел, кроме, возможно, последней, где должны разместиться оставшиеся числа."<<endl;


                cout<<"Выберите функцию: ";
                int func;
                cin>>func;
                switch (func) {
                    case 1:{
                        break;
                    }
                    case 2:{
                        break;
                    }
                    case 3:{
                        break;
                    }
                    case 4:{
                        break;
                    }
                    default:{
                        cout<<"Неверный ввод"<<endl;
                        break;
                    }
                }
                break;
            }

            case 2: {

            }
        }

        cout<<endl<<"Введите имя файла"<<endl;
    }



    return 0;
}