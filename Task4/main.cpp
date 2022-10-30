//
// Created by lexa2k on 19.10.2022.
//
//cmake_minimum_required(VERSION 3.23)
//project(Siaod2sem)
//
//set(CMAKE_CXX_STANDARD 23)
//add_executable(Siaod2sem Task4/main.cpp Task4/tree.h Task4/tree.cpp Task5/main.cpp)

#include <iostream>
#include "tree.h"

using namespace std;

idealBalanceTree::node* idealBalanceTree::root = nullptr;


//create console menu
int main() {
    system("chcp 65001");
    int choice=-1;
    idealBalanceTree tree;

    while (choice!=0) {
        cout<<"Лабораторная работа №4. 'Нелинейные структуры данных. Бинарное дерево.'. Смольников Алексей. Вариант 2(22)"<<endl;
        cout<<"Идеально сбалансированное дерево"<<endl;
        cout<<"Выберите действие:"<<endl;
        cout<<"1. Случайно сгенерировать дерево"<<endl;
        cout<<"2. Вывести дерево в консоль"<<endl;
        cout<<"3. Добавить вручную элемент в дерево"<<endl;
        cout<<"Индивидуальные задания"<<endl;
        cout<<"4. Посчитать количество положительных элементов в дереве"<<endl;
        cout<<"5. Посчитать количество элементов с заданным значением"<<endl;
        cout<<"6. Умножить все элементы дерева на 2"<<endl;
        cout<<"7. Запуск функции тестирования"<<endl;
        cout<<"0. Выход"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:{
                int length;
                cout<<"Количество элементов дерева:"<<endl;
                cin>>length;
                tree.generateTree(length);
                break;
            }
            case 2:{
                tree.printTree();
                break;
            }
            case 3:{
                int key;
                cout<<"Введите ключ элемента:"<<endl;
                cin>>key;
                tree.addElement(key);
                break;
            }
            case 4:{
                cout<<"Количество положительных элементов в дереве: "<<tree.countPositiveElements()<<endl;
                break;
            }
            case 5:{
                int key;
                cout<<"Введите ключ элемента:"<<endl;
                cin>>key;
                cout<<"Количество элементов с ключом "<<key<<": "<<tree.countElementsWithVariable(key)<<endl;
                break;
            }
            case 6:{
                tree.multiplyAllElementsWith2();
                break;
            }
            case 7:{
                testTree();
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"Wrong input"<<endl;
                break;
            }
        }
    }

    return 0;
}


