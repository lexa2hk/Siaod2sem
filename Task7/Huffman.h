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
    };



    vector<Node> data;
    vector<bool> answer;
    long long s_length=0;
public:
    void scanText(string dataText);
    int find_el(char c);
    vector<bool> encode(string dataText);
};

#endif //SIAOD2SEM_HUFFMAN_H
