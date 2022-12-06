//
// Created by lexa2k on 29.11.2022.
//
#include <fstream>
#include "ShennonFano.h"
#include <fstream>

void ShennonFano::scanText(string text) {
    for(auto c: text){

        count.find(c) == count.end() ? count[c]=1 : count[c]++;
    }
    s_length=text.length();

    for(auto it : count){
        dataProbability.emplace_back(it.first,(double)it.second/ (double)s_length);
    }

    sort(dataProbability.begin(),dataProbability.end(),[](tuple<char,double> const &a, tuple<char,double> const &b){
        return get<1>(a) >= get<1>(b);
    });
}


vector<bool> ShennonFano::encode(string text) {
    scanText(text);

    buildCodeTree(dataProbability,"",rootTree);

//    for(auto c: codeTable){
//        cout << c.first << " " << c.second << endl;
//    }

    for(auto c: text){
        for(auto code: codeTable[c]){
            if(code=='0') answer.push_back(false);
            else answer.push_back(true);
        }
    }
    return {};
}

ShennonFano::~ShennonFano() {
    answer.clear();
    count.clear();
    dataProbability.clear();
    codeTable.clear();

//    treeNode *temp = rootTree;
//    while(temp!= nullptr){
//        if(temp->left!= nullptr){
//            temp = temp->left;
//            delete temp->right;
//        } else {
//            delete temp;
//            temp = nullptr;
//        }
//    }

}

void ShennonFano::buildCodeTree(vector<tuple<char,double>>data,string curValue, treeNode *root) {

    if(data.size()==1){
        root->c = get<0>(data[0]);
        root->code = curValue;
        codeTable[get<0>(data[0])] = curValue;
        tempCnt++;
        return;
    }else if(data.size()==0){
        return;
    }

    int minPos=1;
    double minDelta=1.0;
    for(int i=1;i<data.size();i++){
        double accumulateLeft=0.0;
        double accumulateRight=0.0;
        for(int j=0;j<data.size();j++){
            if(j<i){
                accumulateLeft+=get<1>(data[j]);
            }else{
                accumulateRight+=get<1>(data[j]);
            }
        }
        double delta = abs(accumulateLeft-accumulateRight);

        if(delta<minDelta){
            minDelta=delta;
            minPos=i;
        }
    }
    vector<tuple<char,double>>leftV;
    vector<tuple<char,double>>rightV;
    leftV = vector<tuple<char,double>>(data.begin(),data.begin()+minPos);
    rightV = vector<tuple<char,double>>(data.begin()+minPos,data.end());

    treeNode *leftNode = new treeNode;
    treeNode *rightNode = new treeNode;

    root->left = leftNode;
    root->right = rightNode;

    buildCodeTree(leftV, curValue+"0",root->left);
    buildCodeTree(rightV, curValue+"1",root->right);



}

int ShennonFano::getByteSize() {
    if(answer.size()%8==0){
        return answer.size()/8;
    }else{
        return answer.size()/8+1;
    }
}

string ShennonFano::decode() {
    string result="";
    string temp_code;
    while(!answer.empty()){
        temp_code+=answer.front() ? "1" : "0";
        answer.erase(answer.begin());
        for(auto it: codeTable){
            if(it.second==temp_code){
                result+=it.first;
                temp_code.clear();
                break;
            }
        }
    }
    return result;
}

void ShennonFano::printCodeTable() {
    for(auto it: codeTable){
        cout << it.first<< endl;
    }

    for(auto it: codeTable){
        cout << it.second<< endl;
    }

}
