//
// Created by lexa2k on 19.10.2022.
//

#ifndef SIAOD2SEM_TREE_H
#define SIAOD2SEM_TREE_H
#include <string>

//create class for ideal balanced tree where leafs are on the same level
class idealBalanceTree {
    struct node {
        int key;
        idealBalanceTree *left;
        idealBalanceTree *right;
    };

    node *root;

public:
    void printTree(node *element= nullptr, std::string  prefix = "", bool root = true);
    void generateTree(int size);
    void addElement(int key);

};

#endif //SIAOD2SEM_TREE_H
