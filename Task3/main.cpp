//
// Created by lexa2k on 26.09.2022.
//
#include <iostream>
#include "manipulateHash.h"
#include "bitFile.h"
#include "manipulateBinHash.h"
#include "binaryGenerator.h"
#include <chrono>

using namespace std;
//
//int main(){
//    system("chcp 65001");
//    //generateBinaryFile("trueBinShort.bin", 3);
//    printRecord(directAccess("trueBin.bin", 999));
//
//    testBinF();
//    testHeshT();
//    return 0;
//}


int main() {
    system("chcp 65001");

    //generateBinaryFile("trueBinLarge.bin", 1000000);


    //create switch-case menu for 5 elements where 0 calls exit
    int choice=1;
    unsigned int inp;

    HashTable hashTable;
    while(choice!=0){
        cout<<"Лабораторная работа №2. 'Применение хеш-таблицы для поиска данных в двоичном файле с записями фиксированной длины.'. Смольников Алексей. Вариант 22"<<endl;
        cout<<"1) Прочитать запись из файла и вставить элемент в таблицу"<<endl;
        cout<<"2) Удалить запись из таблицы при заданном значении ключа и соответственно из файла."<<endl;
        cout<<"3) Найти запись в файле по значению ключа (найти ключ в хеш-таблице, получить номер записи с этим ключом в файле, выполнить прямой доступ к записи по ее номеру).."<<endl;
        cout<<"4) Тестовый прогон на большом файле (500 000 записей)"<<endl;
        cout<<"5) Запустить testBinF"<<endl;
        cout<<"6) Запустить testHeshT"<<endl;
        cout<<"Выберите номер задания (0-выход)"<<endl;
        cin>>choice;

        switch (choice) {
            case 1: {
                cout << "Введите номер записи" << endl;
                cin >> inp;
                cout << "Введите имя файла" << endl;
                string file;
                cin >> file;

                migrateBinHash(hashTable, file, inp);
                hashTable.print();
            }
                break;
            case 2:{
                string key;
                cout << "Введите ключ" << endl;
                cin >> key;
                cout << "Введите имя файла" << endl;
                string file;
                cin >> file;
                deleteByKeyHash(hashTable, file,key);

                break;
            }
            case 3:{
                string sinp;
                cout<<"Введите ключ"<<endl;
                cin>>sinp;
                cout<<"Введите имя файла"<<endl;
                string file;
                cin>>file;
                getByKeyHash(hashTable, file,sinp);
                break;
            }
            case 4:{
                HashTable hashTable1;
                string bitFileName = "trueBinLarge.bin";

                migrateBinHash(hashTable1, bitFileName);

                //measure time
                auto start = chrono::high_resolution_clock::now();
                getByKeyHash(hashTable1, bitFileName, "00437843");
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time taken by function: "
                     << duration.count() << " microseconds" << endl;

                start = chrono::high_resolution_clock::now();
                getByKeyHash(hashTable1, bitFileName, "006255414");
                end = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time taken by function: "
                     << duration.count() << " microseconds" << endl;

                start = chrono::high_resolution_clock::now();
                getByKeyHash(hashTable1, bitFileName, "00592629");
                end = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time taken by function: "
                     << duration.count() << " microseconds" << endl;
                break;
            }
            case 5:
                testBinF();
                break;
            case 6: {
                testHeshT();
                break;
            }
            case 7:
                hashTable.print();
                break;
            default:
                break;
        }
    }

    return 0;
}

//int main1() {
//    system("chcp 65001");
//
////    generateBinaryFile("extraLarge.bin", 500000);
//
//    HashTable hashTable;
//    string bitFileName = "extraLarge.bin";
//
//
//    migrateBinHash(hashTable, bitFileName);
//    getByKeyHash(hashTable, bitFileName, "00284681");
//
//    //measure time
//    auto start = chrono::high_resolution_clock::now();
//    getByKeyHash(hashTable, bitFileName, "00591551");
//    auto end = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
//    cout << "Time taken by function: "
//         << duration.count() << " microseconds" << endl;
//
//    start = chrono::high_resolution_clock::now();
//    getByKeyHash(hashTable, bitFileName, "00035075");
//    end = chrono::high_resolution_clock::now();
//    duration = chrono::duration_cast<chrono::microseconds>(end - start);
//    cout << "Time taken by function: "
//         << duration.count() << " microseconds" << endl;
//
//    start = chrono::high_resolution_clock::now();
//    getByKeyHash(hashTable, bitFileName, "00397588");
//    end = chrono::high_resolution_clock::now();
//    duration = chrono::duration_cast<chrono::microseconds>(end - start);
//    cout << "Time taken by function: "
//         << duration.count() << " microseconds" << endl;
//
//
//
//    return 0;
//}