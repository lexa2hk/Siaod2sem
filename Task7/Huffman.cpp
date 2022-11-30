//
// Created by lexa2hk on 30.11.2022.
//

#include "Huffman.h"




void Huffman::scanText(string dataText) {
    for(char c:dataText){
        s_length++;
        int index = find_el(c);
        if(index!=-1){
            this->data[index].weight++;
        }else{
            this->data.push_back(Node{string(1,c),1});
        }
    }
}


vector<bool> Huffman::encode(string dataText, string fileName, bool isFile) {

    if(!isFile) {
        scanText(dataText);
        sort(this->data.begin(), this->data.end(), [&](Node a, Node b) { return a.weight > b.weight; });
    }else{
        ifstream file(fileName);
        string str;
        while (getline(file, str)) {
            scanText(str+"\n");
        }
        sort(this->data.begin(), this->data.end(), [&](Node a, Node b) { return a.weight > b.weight; });
    }

    vector<treeNode*> nodes;
    for(int i=0;i<this->data.size();i++){
        nodes.push_back(new treeNode{this->data[i], nullptr, nullptr, nullptr});
    }

    while(nodes.size()>1){
        treeNode *left = nodes[nodes.size()-1];
        treeNode *right = nodes[nodes.size()-2];
        treeNode *parent = new treeNode{Node{"",left->data.weight+right->data.weight},left,right,nullptr};
        left->parent=parent;
        right->parent=parent;
        nodes.pop_back();
        nodes.pop_back();
        nodes.push_back(parent);
        sort(nodes.begin(), nodes.end(), [&](treeNode *a, treeNode *b) { return a->data.weight > b->data.weight; });
    }

    this->rootTree = nodes[0];


    //create codes for all tree
    createCodes(rootTree,"");

    //cout map
    for(auto i:codeTable){
        cout<<i.first<<" "<<i.second<<endl;
    }

//encode data
    if(!isFile){
        for(char c : dataText){
            for(char code : codeTable[string(1,c)]){
                if(code=='0') answer.push_back(false);
                else answer.push_back(true);
            }
        }
    }else{
        ifstream file(fileName);
        string str;
        while (getline(file, str)) {
            for(char c : str){
                for(char code : codeTable[string(1,c)]){
                    if(code=='0') answer.push_back(false);
                    else answer.push_back(true);
                }
            }
            for(char code : codeTable[string(1,'\n')]){
                if(code=='0') answer.push_back(false);
                else answer.push_back(true);
            }
        }
    }


    return answer;

}

int Huffman::find_el(char c) {
    for(int i=0;i<data.size();i++){
        if (string(1,c) == data[i].s)
            return i;
    }
    return -1;
}

void Huffman::createCodes(Huffman::treeNode *pNode, string code) {
    if(pNode->left== nullptr && pNode->right== nullptr){
        codeTable[pNode->data.s]=code;
        decodeTable[code]=pNode->data.s;
        return;
    }
    createCodes(pNode->left,code+"0");
    createCodes(pNode->right,code+"1");

}

void Huffman::printEncoded(){
    for(bool i: answer){
        cout<<i;
    }
    cout<<endl;
}

int Huffman::getEncodedLength() {
    return answer.size()/8;
}

string Huffman::decode(){
    string decoded;
    string code;
    for(bool i:answer){
        if(i) code+="1";
        else code+="0";
        if(decodeTable.find(code)!=decodeTable.end()){
            decoded+=decodeTable[code];
            code="";
        }
    }
    return decoded;
}


