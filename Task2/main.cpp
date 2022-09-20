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
    int task=-1;

    while ( task !=0 ){
        cout<<endl;
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
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        generateFile(fileName);
                        break;
                    }
                    case 2:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        printFile(fileName);
                        break;
                    }
                    case 3:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите строку: ";
                        string str;
                        cin>>str;
                        appendLine(fileName, str);
                        break;
                    }
                    case 4:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите номер числа: ";
                        int num;
                        cin>>num;
                        cout<<"Число: "<<readNumber(fileName, num)<<endl;
                        break;
                    }
                    case 5:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите имя нового файла: ";
                        string newFileName;
                        cin>>newFileName;
                        cout<<"Введите количество чисел в строке: ";
                        int count;
                        cin>>count;
                        copyFormatted(fileName, newFileName, count);
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
                cout<<"Расписание занятий группы: номер группы, название дисциплины, номер пары, номер недели, номер дня недели, вид занятия, номер аудитории."<<endl;
                cout<<"1 преобразование тестовых данных из текстового файла в двоичный файл;"<<endl;
                cout<<"2 преобразование данных из двоичного файла в текстовый;"<<endl;
                cout<<"3 вывод всех записей двоичного файла;"<<endl;
                cout<<"4 доступ к записи по ее порядковому номеру в файле, используя механизм прямого доступа к записи в двоичном файле;"<<endl;
                cout<<"5 удаление записи с заданным значением ключа, выполнить путем замены на последнюю запись."<<endl;
                cout<<"6 Сформировать в двоичном файле расписание заданной группы на заданный день недели."<<endl;
                cout<<"7 Обновить расписание, найти дисциплины, которые стоят на одинаковых парах в одной аудитории, и определить для них новые аудитории.."<<endl;

                cout<<"Выберите функцию: ";
                int func;
                cin>>func;
                switch (func) {
                    case 1:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите имя нового файла: ";
                        string newFileName;
                        cin>>newFileName;
                        convertToBitFile(fileName, newFileName);
                        break;
                    }
                    case 2:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите имя нового файла: ";
                        string newFileName;
                        cin>>newFileName;
                        convertToTextFile(fileName, newFileName);
                        break;
                    }
                    case 3:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        printBitFile(fileName);
                        break;
                    }
                    case 4:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите номер записи: ";
                        int num;
                        cin>>num;
                        directAccess(fileName, num);
                        break;
                    }
                    case 5:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите ключ: ";
                        string key;
                        cin>>key;
                        deleteByKey(fileName, key);
                        break;
                    }
                    case 6:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите номер группы: ";
                        string group;
                        cin>>group;
                        cout<<"Введите номер дня недели: ";
                        string day;
                        cin>>day;
                        generateByWeekDay(fileName, group, day);
                        break;
                    }
                    case 7:{
                        cout<<"Введите имя файла: ";
                        string fileName;
                        cin>>fileName;
                        cout<<"Введите имя нового файла: ";
                        string newFileName;
                        cin>>newFileName;
                        updateSchedule(fileName, newFileName);
                        break;
                    }
                    default:{
                        cout<<"Неверный ввод"<<endl;
                        break;
                    }
                }
            }
        }

    }



    return 0;
}