//
// Created by lexa2k on 29.10.2022.
//
#include "binTree.h"
#include "Note.h"
#include <fstream>
#include <iostream>
#include <cstring>

void binTree::BuildByFile(std::string bin){
    std::ifstream file(bin, std::ios::binary | std::ios::in);
    if(!file.is_open()){
        std::cout << "File not found" << std::endl;
        return;
    }
    Note note;
    int i=0;
    while(file.read((char*)&note, sizeNote)){
        addNode(root, note.name, i);
        i++;
    }
    file.close();
}

int binTree::height(binTree::Node *p) {
    return p ? p->height : 0;
}

int binTree::fixheight(binTree::Node *p) {
    int hl = height(p->left);
    int hr = height(p->right);
    return (hl > hr ? hl : hr) + 1;
}


void binTree::addNode(Node* &node, char* key, int index){
    if(node==nullptr){
        node = new Node;
        strcpy(node->key, key);
        node->index = index;
        node->left = nullptr;
        node->right = nullptr;
        node->height = fixheight(node);
        size++;
    }else if(strcmp(key, node->key)<0){
        addNode(node->left, key, index);
    }else if(strcmp(key, node->key)>0){
        addNode(node->right, key, index);
    }
}

void binTree::deleteByKey(Node* &node, char* key){
    if(node==nullptr){
        return;
    }else if(strcmp(key, node->key)<0){
        deleteByKey(node->left, key);
    }else if(strcmp(key, node->key)>0){
        deleteByKey(node->right, key);
    }else{
        if(node->left==nullptr && node->right==nullptr){
            delete node;
            node = nullptr;
        }else if(node->left==nullptr){
            Node* temp = node;
            node = node->right;
            delete temp;
        }else if(node->right==nullptr){
            Node* temp = node;
            node = node->left;
            delete temp;
        }else{
            Node* temp = node->right;
            while(temp->left!=nullptr){
                temp = temp->left;
            }
            strcpy(node->key, temp->key);
            node->index = temp->index;
            deleteByKey(node->right, temp->key);
        }
    }
}

int binTree::searchByKey(Node* node, char* key){
    if(node==nullptr){
        std::cout << "Not found" << std::endl;
        return -1;
    }else if(strcmp(key, node->key)<0){
        searchByKey(node->left, key);
    }else if(strcmp(key, node->key)>0){
        searchByKey(node->right, key);
    }else{
        std::cout << "Found" << node->key << " at "<< node->index << std::endl;
        return node->index;
    }
}

void binTree::print(Node* node, std::string offset){
    if(node==nullptr){
        return;
    }
    printTree(node->right, offset+"   ");
    std::cout << offset << node->key<<" Pos: "<<node->index<< std::endl;
    printTree(node->left, offset+"   ");
}

void binTree::printTree(Node *element , std::string prefix, bool root) {
    if (root) {
        element = this->root;
    }

    if(!element) return;

    if(element->right){
        printTree(element->right, prefix + (root ? "    " : "│   "), false);
    }
    std::cout << prefix << (root ? "└── " : "├── ") << element->key<<" "<<element->index<<std::endl;
    if(element->left){
        printTree(element->left, prefix + (root ? "    " : "│   "), false);
    }
}