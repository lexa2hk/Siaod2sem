//
// Created by lexa2k on 26.09.2022.
//

#include "manipulateHash.h"
#include <iostream>

HashTable::HashTable(){
    this->size = size;
    table = new Node*[size];
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        Node *node = table[i];
        while (node != nullptr) {
            Node *temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete[] table;
}

int HashTable::hash(std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
        hash += static_cast<int>(key[i]);
    }
    return hash % size;
}

void HashTable::add(std::string key, int value, bool isRehash) {
    currentSize++;
    if(currentSize/float(size)>0.9 or isRehash) rehash();

    int index = hash(key);
    Node *node = table[index];

    table[index] = new Node;
    table[index]->key = key;
    table[index]->value = value;
    table[index]->next = node;

}

void HashTable::remove(std::string key) {
    int index = hash(key);
    Node *node = table[index];
    Node *prev = nullptr;
    while (node != nullptr) {
        if (node->key == key) {
            if (prev == nullptr) {
                table[index] = node->next;
            } else {
                prev->next = node->next;
            }
            delete node;
            return;
        }
        prev = node;
        node = node->next;
    }
}

int HashTable::get(std::string key) {
    int index = hash(key);
    Node *node = table[index];
    while (node != nullptr) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void HashTable::rehash() {
    int oldSize = size;
    size *= 2;
    Node **oldTable = table;
    table = new Node*[size];
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
    for (int i = 0; i < oldSize; i++) {
        Node *node = oldTable[i];
        while (node != nullptr) {
            add(node->key, node->value);
            node = node->next;
        }
    }
    for (int i = 0; i < oldSize; i++) {
        Node *node = oldTable[i];
        while (node != nullptr) {
            Node *temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete[] oldTable;
}

void HashTable::print() {
    for (int i = 0; i < size; i++) {
        Node *node = table[i];
        while (node != nullptr) {
            std::cout << node->key << " " << node->value << std::endl;
            node = node->next;
        }
    }
}

//test section
int testHeshT(){
    HashTable hashTable;
    hashTable.add("keyNoCol", 1);
    hashTable.add("key1", 1);
    hashTable.add("key1", 2);
    hashTable.add("key1", 3);
    hashTable.add("key2", 4);
    hashTable.add("key3", 5);

    //remove test

    hashTable.print();

    hashTable.remove("key1");
    std::cout<<std::endl;

    hashTable.print();

    //hash test
   std::cout<<hashTable.hash("key1")<<std::endl;
   std::cout<<hashTable.hash("key2")<<std::endl;

    //rehash test
   std::cout<<"rehash\nsize before"<<std::endl;
   std::cout<<hashTable.size<<std::endl;
    hashTable.rehash();

   std::cout<<"size after"<<std::endl;
   std::cout<<hashTable.size<<std::endl;

    //add with rehash test
    hashTable.add("keyRehash", 1, true);

    hashTable.print();
   std::cout<<"after rehash add "<<hashTable.size;

    return 0;
}



