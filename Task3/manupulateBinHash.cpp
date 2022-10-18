//
// Created by lexa2k on 26.09.2022.
//

#include "manipulateBinHash.h"
#include "bitFile.h"
#include "manipulateHash.h"
#include <fstream>


void migrateBinHash(HashTable &hashTable, std::string bitFileName,int number) {
    std::fstream bitFile(bitFileName, std::ios::binary| std::ios::in | std::ios::app);
    if(!bitFile.is_open()){
        std::cout<<"Error opening file";
        return;
    }
    int cnt=0;

    if(number==-1){
        while(!bitFile.eof()){
            Record record;
            bitFile.read((char*)&record, sizeof(Record));
            hashTable.add(record.key, cnt);
            cnt++;
        }
    }else{
        std::string temp;
        temp = directAccess(bitFileName, number).key;
        if(temp.length()<8){
            std::cout<<"Error";
            return;
        }
        hashTable.add(temp, number);
    }
}

void insertNoteToHash(std::string file, int note, HashTable &hashTable){
    std::string temp = directAccess(file, note).key;
    if(temp.length()==0){
        std::cout<<"Error";
        return;
    }
    hashTable.add(temp, note);
}


void deleteByKeyHash(HashTable &hashTable, std::string bitFileName,std::string key) {
    int number = hashTable.get(key);
    if(number==-1){
        std::cout<<"Error";
        return;
    }
    hashTable.remove(key);
    deleteByKey(bitFileName, key);
}

void getByKeyHash(HashTable &hashTable, std::string bitFileName,std::string key) {
    int number = hashTable.get(key);
    if(number==-1){
        std::cout<<"Error";
        return;
    }

    printRecord(directAccess(bitFileName, number));
}


