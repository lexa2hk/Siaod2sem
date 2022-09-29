//
// Created by lexa2k on 26.09.2022.
//

#ifndef SIAOD2SEM_MANIPULATEBINHASH_H
#define SIAOD2SEM_MANIPULATEBINHASH_H

#include "manipulateHash.h"
#include "bitFile.h"

void migrateBinHash(HashTable &hashTable, std::string bitFileName, int number=-1);

void deleteByKeyHash(HashTable &hashTable, std::string bitFileName, std::string key);

void getByKeyHash(HashTable &hashTable, std::string bitFileName, std::string key);

void insertNoteToHash(std::string file, int note, HashTable &hashTable);


#endif //SIAOD2SEM_MANIPULATEBINHASH_H
