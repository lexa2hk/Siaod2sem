//
// Created by lexa2k on 26.09.2022.
//

#ifndef SIAOD2SEM_MANIPULATEHASH_H
#define SIAOD2SEM_MANIPULATEHASH_H

#include <iostream>
#include <string>

//Цепное хеширование
//Расписание занятий группы: номер группы,
//название дисциплины, номер пары, номер недели, номер дня недели, вид занятия, номер аудитории.

//структура - ключ-номер строки
//способ разрешения коллизий - цепное хеширование

struct Node {
    std::string key;
    int value;
    Node *next;
};

class HashTable {
protected:
    Node **table;
    int currentSize=0;

public:
    HashTable();
    ~HashTable();
    int hash(std::string key);
    void add(std::string key, int value, bool isRehash = false);
    void remove(std::string key);
    int get(std::string key);
    void rehash();
    void print();

    int size=100;
};

//test section
int testHeshT();

#endif //SIAOD2SEM_MANIPULATEHASH_H
