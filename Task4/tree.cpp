//
// Created by lexa2k on 19.10.2022.
//

#include "tree.h"
#include <iostream>
#include <random>


void idealBalanceTree::generateTree(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < size; i++) {
        addElement(dis(gen));
    }
}

void idealBalanceTree::addElement(int key) {
    if (root == nullptr) {
        root = new node;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        node *current = root;
        while (true) {
            if (key < current->key) {
                if (current->left != nullptr) {
                    current = current->left;
                } else {
                    current->left = new node;
                    current->left->key = key;
                    current->left->left = nullptr;
                    current->left->right = nullptr;
                    break;
                }
            } else {
                if (current->right != nullptr) {
                    current = current->right;
                } else {
                    current->right = new node;
                    current->right->key = key;
                    current->right->left = nullptr;
                    current->right->right = nullptr;
                    break;
                }
            }
        }
    }
}


//print tree in console
//void idealBalanceTree::printTree(node *element , std::string prefix, bool root) {
//    if (root) {
//        element = this->root;
//    }
//
//    if(!element) return;
//
//    if(element->right){
//        printTree(element->right, prefix + (root ? "    " : "│   "), false);
//    }
//    std::cout << prefix << (root ? "└── " : "├── ") << element->key << std::endl;
//    if(element->left){
//        printTree(element->left, prefix + (root ? "    " : "│   "), false);
//    }
//}
