//
// Created by lexa2k on 19.10.2022.
//

#include "tree.h"
#include <iostream>
#include <random>
#include <list>

idealBalanceTree::idealBalanceTree() {
    root = nullptr;
}

void idealBalanceTree::generateTree(int length) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-30, 30);

    for (int i = 0; i < length; i++) {
        addElement(dis(gen));
    }
    this->size=length;
}

void idealBalanceTree::addElement(int key, node* &el) {
    node* newNode = new node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    size++;
   if(el== nullptr){
       el=newNode;
       return;
   }

    if(el->left== nullptr){
        el->left=newNode;
        return;
    }else if (el->right== nullptr) {
        el->right = newNode;
        return;
    }else{
        //вызвать функцию с условием, что максимальная и минимальная глубина дерева отличаются не более чем на 1
        if (height(el->left) < height(el->right)) {
            addElement(key, el->left);
        } else {
            addElement(key, el->right);
        }
        return;
    }
}

int idealBalanceTree::height(idealBalanceTree::node *element) {
    if(element== nullptr){
        return 0;
    }
    int leftHeight = height(element->left);
    int rightHeight = height(element->right);
    if(leftHeight>rightHeight){
        return leftHeight+1;
    }else{
        return rightHeight+1;
    }
}


void idealBalanceTree::printTree(node *element , std::string prefix, bool root) {
    if (root) {
        element = this->root;
    }

    if(!element) return;

    if(element->right){
        printTree(element->right, prefix + (root ? "    " : "│   "), false);
    }
    std::cout << prefix << (root ? "└── " : "├── ") << element->key<</* " ("<< height(element) << ")"<<*/std::endl;
    if(element->left){
        printTree(element->left, prefix + (root ? "    " : "│   "), false);
    }
}

//personal task:
// count the number of positive leaves in the tree
int idealBalanceTree::countPositiveElements(node *element) {
    if(element== nullptr){
        return 0;
    }
    int count = 0;
    if(element->key>0 && element->left== nullptr && element->right== nullptr){
        count++;
    }
    count+=countPositiveElements(element->left);
    count+=countPositiveElements(element->right);
    return count;
}

//count the number of elements with given variable
int idealBalanceTree::countElementsWithVariable(int variable, node *element) {
    if(element== nullptr){
        return 0;
    }
    int count = 0;
    if(element->key==variable){
        count++;
    }
    count+=countElementsWithVariable(variable,element->left);
    count+=countElementsWithVariable(variable,element->right);
    return count;
}

//multuply all elements with 2 using BFS
void idealBalanceTree::multiplyAllElementsWith2(node *element) {
    if(element== nullptr){
        return;
    }

    std::list <node*> queue;
    queue.push_back(element);
    while(!queue.empty()){
        node* current = queue.front();
        queue.pop_front();
        if(current== nullptr){
            continue;
        }else{
            current->key*=2;
            if(current->left){
                queue.push_back(current->left);
            }
            if(current->right){
                queue.push_back(current->right);
            }
        }

    }
}

int testTree(){
    system("chcp 65001");
    idealBalanceTree tree;
    tree.generateTree(11);

    std::cout<< "Дерево: " << std::endl;

    tree.printTree();

    std::cout<< "Высота дерева: " << tree.height() << std::endl;

    std::cout<<"Количество положительных элементов: "<<tree.countPositiveElements()<<std::endl;
    std::cout<<"Количество элементов с заданным значением: "<<tree.countElementsWithVariable(5)<<std::endl;
    tree.multiplyAllElementsWith2();
    std::cout<<"Дерево после умножения всех элементов на 2: "<<std::endl;
    tree.printTree();


    return 0;
}
