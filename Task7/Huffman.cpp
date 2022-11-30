//
// Created by lexa2hk on 30.11.2022.
//

#include "Huffman.h"


//template <typename T, typename Compare>
//vector<size_t> sort_permutation(
//        const vector<T>& vec,
//        Compare compare)
//{
//    vector<size_t> p(vec.size());
//    iota(p.begin(), p.end(), 0);
//    sort(p.begin(), p.end(),
//         [&](size_t i, size_t j){ return compare(vec[i], vec[j]); });
//    return p;
//}
//
//template <typename T>
//vector<T> apply_permutation(
//        const vector<T>& vec,
//        const vector<size_t>& p)
//{
//    vector<T> sorted_vec(vec.size());
//    transform(p.begin(), p.end(), sorted_vec.begin(),
//              [&](size_t i){ return vec[i]; });
//    return sorted_vec;
//}


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
    sort(this->data.begin(),this->data.end(),[&](Node a, Node b){return a.weight > b.weight;});


}

vector<bool> Huffman::encode(string dataText){
    scanText(dataText);
    treeNode *left;
    treeNode *right;

    while(data.size()>1){
        Node last = data.back();
        data.pop_back();
        Node preLast = data.back();
        data.pop_back();
        Node merged{last.s+preLast.s,last.weight+preLast.weight};
        data.erase(data.begin());

        //create leaves
        left = treeNode{};

        //merge last to data[0]

    }
}

int Huffman::find_el(char c) {
    for(int i=0;i<data.size();i++){
        if (string(1,c) == data[i].s)
            return i;
    }
    return -1;
}


