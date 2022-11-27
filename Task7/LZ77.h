//
// Created by lexa2k on 27.11.2022.
//

#ifndef SIAOD2SEM_LZ77_H
#define SIAOD2SEM_LZ77_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;


//for LZ77 use alphabet [0,1] and encode string "0100100010010000101"

struct Node{
    unsigned char offset;
    unsigned char length;
    char next;
};

class LZ77{
    int windowLength=8;
    Node fillNode(int off,int l, char nex);
public:
    vector<Node> encoded;
    vector<Node> encode(string text);
    string decode(vector<Node> encoded);
    int getEncodedLength();
    void printEncoded();
};


#endif //SIAOD2SEM_LZ77_H
