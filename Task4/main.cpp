//
// Created by lexa2k on 19.10.2022.
//

#include <iostream>
#include "tree.h"

using namespace std;

    idealBalanceTree::node* idealBalanceTree::root = nullptr;
int main(){
    system("chcp 65001");
    idealBalanceTree tree;
    tree.generateTree(11);

    tree.printTree();

    cout<<"Количество положительных элементов: "<<tree.countPositiveElements()<<endl;
    cout<<"Количество элементов с заданным значением: "<<tree.countElementsWithVariable(5)<<endl;
    tree.multiplyAllElementsWith2();
    tree.printTree();


    return 0;
}