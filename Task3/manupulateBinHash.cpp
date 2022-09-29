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
            std::string temp;
            std::getline(bitFile,temp);
            hashTable.add(temp.substr(0,temp.find(' ')), cnt);
            cnt++;
        }
    }else{
        std::string temp;
        temp = directAccess(bitFileName, number);
        if(temp.length()==0){
            std::cout<<"Error";
            return;
        }
        hashTable.add(temp.substr(0,temp.find(' ')), number);
    }
}

void insertNoteToHash(std::string file, int note, HashTable &hashTable){
    std::string temp = directAccess(file, note);
    if(temp.length()==0){
        std::cout<<"Error";
        return;
    }
    hashTable.add(temp.substr(0,temp.find(' ')), note);
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

    directAccess(bitFileName, number);
}


