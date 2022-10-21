//
// Created by lexa2k on 19.10.2022.
//

#ifndef SIAOD2SEM_TREE_H
#define SIAOD2SEM_TREE_H
#include <string>


//create class for ideal balanced tree where leafs are on the same level
class idealBalanceTree {
protected:
    struct node {
        int key;
        node *left;
        node *right;
    };

    static node *root;
    int size = 0;

public:
    idealBalanceTree();
    void printTree(node *element= nullptr, std::string  prefix = "", bool root = true);
    void generateTree(int length);
    void addElement(int key,node* &el = root);

    int height(node *element = root);

    //personal task:
    // count the number of positive elements in the tree
    int countPositiveElements(node *element = root);
    //count the number of elements with given variable
    int countElementsWithVariable(int variable, node *element = root);
    //multuply all elements with 2 using BFS
    void multiplyAllElementsWith2(node *element = root);

};

int testTree();

#endif //SIAOD2SEM_TREE_H
