//
// Created by lexa2k on 29.11.2022.
//

#ifndef SIAOD2SEM_SHENNONFANO_H
#define SIAOD2SEM_SHENNONFANO_H
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <tuple>

using namespace std;

class ShennonFano{
    long long s_length=0;
    vector<bool> answer;
    map<char,int>count;
    vector<tuple<char,double>>dataProbability;
    map<char,string>codeTable;


    int tempCnt=0;

    struct treeNode{
        char c;
        string code;

        treeNode *left;
        treeNode *right;
    };

    treeNode *rootTree = new treeNode;

public:
    void scanText(string text);
    vector<bool> encode(string text);
    void buildCodeTree(vector<tuple<char,double>>data, string curValue, treeNode *root);

    int getByteSize();
    ~ShennonFano();


};

#endif //SIAOD2SEM_SHENNONFANO_H
