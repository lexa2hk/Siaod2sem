//
// Created by lexa2k on 29.10.2022.
//
#include <iostream>
#include <string>
#include <chrono>

#include "AVLTree.h"
#include "Note.h"
#include "binfile.h"
#include "binTree.h"

using namespace std;

void avlLarge(){
    AVLTree treeLarge;
    binfile binLarge;

    binLarge.textToBin("C:\\Users\\lexa2k\\Desktop\\RTU_SEM2\\Siaod2sem\\Task5\\T5Large.txt", "T5large.bin");
    treeLarge.BuildByFile("T5large.bin");
    cout<<"Large(300 000) AVL Tree height: "<<endl;
    cout<<treeLarge.root->height;

    cout<<"Search: ZeBndfRUydEEGkQQaNGq "<<treeLarge.search("ZeBndfRUydEEGkQQaNGq");

    cout<<"rotations: "<<treeLarge.rotations<<endl;
}

void BSTLarge(){
    binTree treeLarge;
    binfile binLarge;

    binLarge.textToBin("C:\\Users\\lexa2k\\Desktop\\RTU_SEM2\\Siaod2sem\\Task5\\T5Large.txt", "T5large.bin");
    treeLarge.BuildByFile("T5Large.bin");
    cout<<"\nLarge(300 000) BST Tree: "<<endl;

    cout<<"Search:  ";
    treeLarge.searchByKey(treeLarge.root, "ybqORJFSipIHhJZUvmiq");

//    treeLarge.printTree();


}

void analyzeLinearTime(){
    binfile binLarge;

    binLarge.textToBin("C:\\Users\\lexa2k\\Desktop\\RTU_SEM2\\Siaod2sem\\Task5\\T5Large.txt", "T5large.bin");
    cout<<"\nLarge(300 000) File: "<<endl;

    cout<<"Search (top):  ";
    auto start = chrono::high_resolution_clock::now();
    cout<<binLarge.searchBin("T5large.bin", "ybqORJFSipIHhJZUvmiq")<<endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    cout<<"Search (middle):  ";
    start = chrono::high_resolution_clock::now();
    cout<<binLarge.searchBin("T5large.bin", "FOQKoqiOfPMJDuvGJhbO")<<endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    cout<<"Search (bottom):  ";
    start = chrono::high_resolution_clock::now();
    cout<<binLarge.searchBin("T5large.bin", "NSQDFWlnkIeWiuWBsBAf")<<endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    return;
}

void avalyzeBSTTime(){
    binTree treeLarge;
    binfile binLarge;

    binLarge.textToBin("C:\\Users\\lexa2k\\Desktop\\RTU_SEM2\\Siaod2sem\\Task5\\T5Large.txt", "T5large.bin");
    treeLarge.BuildByFile("T5Large.bin");
    cout<<"\nLarge(300 000) BST Tree: "<<endl;

    cout<<"Search (top):  ";
    auto start = chrono::high_resolution_clock::now();
    treeLarge.searchByKey(treeLarge.root, "OIbpjaBmQgXJievFHbPA");
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    cout<<"Search (middle):  ";
    start = chrono::high_resolution_clock::now();
    treeLarge.searchByKey(treeLarge.root, "FOQKoqiOfPMJDuvGJhbO");
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    cout<<"Search (bottom):  ";
    start = chrono::high_resolution_clock::now();
    treeLarge.searchByKey(treeLarge.root, "NSQDFWlnkIeWiuWBsBAf");
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    return;
}

void avalyzeAVLTime(){
    AVLTree treeLarge;
    binfile binLarge;

    binLarge.textToBin("C:\\Users\\lexa2k\\Desktop\\RTU_SEM2\\Siaod2sem\\Task5\\T5Large.txt", "T5large.bin");
    treeLarge.BuildByFile("T5Large.bin");
    cout<<"\nLarge(300 000) AVL Tree: "<<endl;

    cout<<"Search (top):  ";
    auto start = chrono::high_resolution_clock::now();
    cout<<treeLarge.search( "OIbpjaBmQgXJievFHbPA")<<endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    cout<<"Search (middle):  ";
    start = chrono::high_resolution_clock::now();
    cout<<treeLarge.search("FOQKoqiOfPMJDuvGJhbO")<<endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    cout<<"Search (bottom):  ";
    start = chrono::high_resolution_clock::now();
    cout<<treeLarge.search("NSQDFWlnkIeWiuWBsBAf")<<endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    return;
}


//  Я знаю — моё дерево не проживёт и недели
//  Я знаю — моё дерево в этом городе обречено
//  Но я всё своё время провожу рядом с ним
//  Мне все другие дела надоели
//  Мне кажется, что это мой дом
//  Мне кажется, что это мой друг
//
//  Я посадил дерево
//  Я посадил дерево
//  Я посадил дерево
//  Я, посадил дерево
//  Я знаю — моё дерево, завтра, может, сломает школьник
//  Я знаю — моё дерево скоро оставит меня
//  Но, пока оно есть, я всегда рядом с ним
//  Мне с ним радостно, мне с ним больно
//  Мне кажется, что это мой мир
//  Мне кажется, что это мой сын

int main(){
    system("chcp 65001");

    int choice = -1;
    binfile bin;
    AVLTree avlTree;
    binTree binTree;

    while(choice!=0){
        cout<<"Лабораторная работа №5. ' Сбалансированные деревья поиска (СДП) и их применение для поиска данных в файле.'. Смольников Алексей. Вариант 22"<<endl;
        cout<<"Выберите действие:"<<endl;
        cout<<"---БИНАРНЫЙ ФАЙЛ---"<<endl;
        cout<<"1. Создать двочиный файл"<<endl;
        cout<<"2. Найти запись по ключу(линейный поиск)"<<endl;
        cout<<"3. Вывод записи по известному адресу (строка начиная с 0)"<<endl;
        cout<<"4. Добавить запись в файл"<<endl;

        cout<<"---БИНАРНОЕ ДЕРЕВО ПОИСКА---"<<endl;
        cout<<"5. Построить дерево по бинарному файлу"<<endl;
        cout<<"6. Добавить элемент в дерево"<<endl;
        cout<<"7. Поиск по ключу в дереве"<<endl;
        cout<<"8. Удалить элемент из дерева"<<endl;
        cout<<"9. Вывод дерева"<<endl;

        cout<<"---СБАЛАНСИРОВАННОЕ ДЕРЕВО ПОИСКА---"<<endl;
        cout<<"10. Построить дерево по бинарному файлу"<<endl;
        cout<<"11. Добавить элемент в дерево"<<endl;
        cout<<"12. Поиск по ключу в дереве"<<endl;
        cout<<"13. Удалить элемент из дерева"<<endl;
        cout<<"14. Вывод дерева"<<endl;

        cout<<"15. Определить число поворотов при построении СДП"<<endl;
        cout<<"16. БДП на 300 000 элементов"<<endl;
        cout<<"17. СДП на 300 000 элементов"<<endl;

        cout<<"18. Сравнение времени"<<endl;

        cout<<"0. Выход"<<endl;
        cin>>choice;

        switch (choice) {
            case 1: {
                cout << "Введите путь к файлу: ";
                string path;
                cin >> path;
                cout << "Введите путь к бинарному файлу: ";
                string binPath;
                cin >> binPath;
                bin.textToBin(path, binPath);
                break;
            }
            case 2:{
                cout<<"Введите путь к бинарному файлу: ";
                string binPath;
                cin>>binPath;
                cout<<"Введите страну: ";
                string key;
                cin>>key;
                bin.searchBin(key, binPath);
                break;
            }
            case 3:{
                cout<<"Введите путь к бинарному файлу: ";
                string binPath;
                cin>>binPath;
                cout<<"Введите номер строки: ";
                int line;
                cin>>line;
                bin.directAccessBin(binPath, line);
                break;
            }
            case 4:{
                cout<<"Введите путь к бинарному файлу: ";
                string binPath;
                cin>>binPath;
                cout<<"Введите страну: ";
                string country;
                cin>>country;
                cout<<"Введите население: ";
                int population;
                cin>>population;
                cout<<"Введите Факт нахождения в UNO: ";
                int uno;
                cin>>uno;
                Note note;
                strcpy(note.name, country.c_str());
                note.people = population;
                note.Uno = uno;

                bin.addBin(binPath, note);
                break;
            }
            case 5:{
                cout<<"Введите путь к бинарному файлу: ";
                string binPath;
                cin>>binPath;
                binTree.BuildByFile(binPath);
                break;
            }
            case 6:{
                cout<<"Введите страну: ";
                string country;
                cin>>country;
                cout<<"Введите Позицию в файле: ";
                int pos;
                cin>>pos;

                char *cstr = new char[country.length() + 1];
                strcpy(cstr, country.c_str());

                binTree.addNode(binTree.root, cstr , pos);

                delete [] cstr;
                break;
            }
            case 7:{
                cout<<"Введите страну: ";
//                string country;
                char country[100];
                cin>>country;

                cout<<"Введите путь к бинарному файлу: ";
                string binPath;
                cin>>binPath;

//                char *cstr = new char[country.length() + 1];
//                strcpy(cstr, country.c_str());
                int res = binTree.searchByKey(binTree.root, country);
                cout<<endl;

                if(res == -1){
                    cout<<"Страна не найдена"<<endl;
                } else{
                    cout<<"Страна найдена"<<endl;
                    cout<<"Позиция в файле: "<<res<<endl;
                    bin.directAccessBin(binPath, res);
                }
//                delete [] cstr;
                break;
            }
            case 8:{
                cout<<"Введите страну: ";
                string country;
                cin>>country;

                char *cstr = new char[country.length() + 1];
                strcpy(cstr, country.c_str());
                binTree.deleteByKey(binTree.root, cstr);
                delete [] cstr;
                break;
            }
            case 9:{
                binTree.printTree(binTree.root);
                break;
            }
            case 10:{
                cout<<"Введите путь к бинарному файлу: ";
                string binPath;
                cin>>binPath;

                avlTree.BuildByFile(binPath);
                break;
            }
            case 11:{
                cout<<"Введите страну: ";
                string country;
                cin>>country;
                cout<<"Введите Позицию в файле: ";
                int pos;
                cin>>pos;

                char *cstr = new char[country.length() + 1];
                strcpy(cstr, country.c_str());

                avlTree.root = avlTree.insert(avlTree.root, cstr, pos);

                delete [] cstr;
                break;
            }
            case 12:{
                cout<<"Введите страну: ";
                string country;
                cin>>country;

                char *cstr = new char[country.length() + 1];
                strcpy(cstr, country.c_str());

                cout<<"FOUND at "<<avlTree.search(cstr)<<endl;
                delete [] cstr;
                break;
            }
            case 13:{
                cout<<"Введите страну: ";
                string country;
                cin>>country;

                char *cstr = new char[country.length() + 1];
                strcpy(cstr, country.c_str());
                avlTree.root = avlTree.deleteNode(avlTree.root, cstr);
                delete [] cstr;
                break;
            }
            case 14:{
                avlTree.printTree(avlTree.root);
                break;
            }
            case 15:{
                //Повороты
                cout<<"Количество поворотов: ";
                cout<<avlTree.rotations<<endl;
                break;
            }

            case 16:{

                cout<<"БДП на 300 000: ";
                BSTLarge();
                break;

            }
            case 17:{

                cout<<"CДП на 300 000: ";
                avlLarge();
                break;

            }
            case 18:{
                analyzeLinearTime();
                avalyzeBSTTime();
                avalyzeAVLTime();
                break;
            }

        }
    }

    return 0;
}