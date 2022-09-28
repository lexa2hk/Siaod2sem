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

int main() {
    system("chcp 65001");

//    generateBinaryFile("extraLarge.bin", 500000);

    HashTable hashTable;
    string bitFileName = "extraLarge.bin";


    migrateBinHash(hashTable, bitFileName);
    getByKeyHash(hashTable, bitFileName, "00284681");

    //measure time
    auto start = chrono::high_resolution_clock::now();
    getByKeyHash(hashTable, bitFileName, "00591551");
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    getByKeyHash(hashTable, bitFileName, "00035075");
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    getByKeyHash(hashTable, bitFileName, "00397588");
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;



    return 0;
}