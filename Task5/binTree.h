//
// Created by lexa2k on 29.10.2022.
//

#ifndef SIAOD2SEM_BINTREE_H
#define SIAOD2SEM_BINTREE_H

#include <string>

class binTree{
public:
    struct Node{
        char key[45];
        int index;

        Node* left;
        Node* right;
        int height;
    };
    Node* root=nullptr;
    int size;

    int height(Node* p);
    int fixheight(binTree::Node *p);
    void BuildByFile( std::string bin);
    void addNode(Node* &node, char* key, int index);
    void deleteByKey(Node* &node, char* key);
    int searchByKey(Node* node, char* key);
    void directAccess(Node* node, int index);
    void print(Node* node, std::string offset);
    void printTree(Node *element= nullptr, std::string  prefix = "", bool root = true);



};

#endif //SIAOD2SEM_BINTREE_H
