//
// Created by lexa2k on 19.10.2022.
//

#include <iostream>
#include "tree.h"

using namespace std;

int main(){
    system("chcp 65001");
    idealBalanceTree tree;
    tree.generateTree(10);

    tree.printTree();


    return 0;
}