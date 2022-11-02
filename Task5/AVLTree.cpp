//
// Created by lexa2k on 29.10.2022.
//
#include "AVLTree.h"

void AVLTree::BuildByFile(std::string bin) {
    std::ifstream fin(bin, std::ios::binary | std::ios::in);
    Note note;
    int i=0;
    while(fin.read((char*)&note, sizeNote)){

        root = insert(root, note.name, i);
        i++;
    }
    fin.close();

}

int AVLTree::height(Node *p) {
    return p ? p->height : 0;
}

int AVLTree::bfactor(Node *p) {
    return height(p->right) - height(p->left);
}

void AVLTree::fixheight(AVLTree::Node *p) {
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

AVLTree::Node* AVLTree::insert(AVLTree::Node *p, char *k, int index) {
    if(!p){
        p = new Node;
        strcpy(p->key, k);
        p->index = index;
        strcpy(p->key, k);
        p->left = p->right = nullptr;
        p->height = 1;
        size++;
        return p;
    }
    if(strcmp(k, p->key) < 0){
        p->left = insert(p->left, k, index);
    } else{
        p->right = insert(p->right, k, index);
    }
    return balance(p);
}



AVLTree::Node* AVLTree::balance(AVLTree::Node* p){
    fixheight(p);

    //выполение одного из больших поворотов
    if(bfactor(p) == 2){
        if(bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if(bfactor(p) == -2){
        if(bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}

AVLTree::Node* AVLTree::rotateright(AVLTree::Node *p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);

    rotations++;
    return q;
}

AVLTree::Node* AVLTree::rotateleft(AVLTree::Node *q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);

    rotations++;
    return p;
}



void AVLTree::print(AVLTree::Node *p, std::string prefix) {
    if(p){
        print(p->right, prefix + "    ");
        std::cout << prefix << p->key << std::endl;
        print(p->left, prefix + "    ");
    }
}


void AVLTree::printTree(Node *element , std::string prefix, bool root) {
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


AVLTree::Node* AVLTree::findMin(Node* p){
    return p->left ? findMin(p->left) : p;
}
AVLTree::Node* AVLTree::removeMin(Node* p){
    if(p->left == 0)
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}



AVLTree::Node* AVLTree::deleteNode(AVLTree::Node *p, char *k) {
    if(!p) return nullptr;
    if(strcmp(k, p->key) < 0){
        p->left = deleteNode(p->left, k);
    } else if(strcmp(k, p->key) > 0){
        p->right = deleteNode(p->right, k);
    } else{
        Node* q = p->left;
        Node* r = p->right;
        delete p;
        if(!r) return q;
        Node* min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

int AVLTree::search(char *k) {
    Node* p = root;
    while(p){
        if(strcmp(k, p->key) < 0){
            p = p->left;
        } else if(strcmp(k, p->key) > 0){
            p = p->right;
        } else{
            return p->index;
        }
    }
    return -1;
}
