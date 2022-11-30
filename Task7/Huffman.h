//
// Created by lexa2hk on 30.11.2022.
//

#ifndef SIAOD2SEM_HUFFMAN_H
#define SIAOD2SEM_HUFFMAN_H
#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <map>
#include <numeric>
#include "fstream"

using namespace std;



class Huffman{
    struct Node{
        string s="";
        int weight=0;
    };

    struct treeNode{
        Node data;
        treeNode *left;
        treeNode *right;
        treeNode *parent;
    };



    vector<Node> data;
    vector<bool> answer;
    map<string,string>codeTable;
    map<string,string>decodeTable;

    treeNode *rootTree;
public:
    void scanText(string dataText);
    int find_el(char c);

    void createCodes(treeNode *pNode, string code);

    void printEncoded();

    int getEncodedLength();

    string decode();

    vector<bool> encode(string dataText, string fileName="", bool isFile=false);

    long long s_length=0;
};

#endif //SIAOD2SEM_HUFFMAN_H
