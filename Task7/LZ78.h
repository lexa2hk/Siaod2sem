//
// Created by lexa2k on 29.11.2022.
//

#ifndef SIAOD2SEM_LZ78_H
#define SIAOD2SEM_LZ78_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct LZ78node{
    unsigned char index;
    char next;
};

class LZ78{
    vector<LZ78node> encoded;
    map<string,int> dictionary;
public:
    int getEncodedLength();
    void printEncoded();
    vector<LZ78node> encode(string text);
    string decode();
};

#endif //SIAOD2SEM_LZ78_H
