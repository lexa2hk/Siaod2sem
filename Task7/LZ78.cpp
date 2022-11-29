//
// Created by lexa2k on 29.11.2022.
//
#include "LZ78.h"

int LZ78::getEncodedLength() {
    return 2*encoded.size();
}

void LZ78::printEncoded() {
    for(int i=0;i<encoded.size();i++){
        cout<<(int)encoded[i].index<<" "<<encoded[i].next<<endl;
    }
}

vector<LZ78node> LZ78::encode(string text) {

    int index=0;
    string buffer="";

    vector<LZ78node> answer;

    for(int i=0;i<text.length();i++){
        if(dictionary.find(buffer+text[i]) != dictionary.end()){
            buffer+=text[i];
        }else{
            answer.push_back(LZ78node{static_cast<unsigned char>(dictionary[buffer]), text[i]});
            dictionary[buffer+text[i]]=dictionary.size()+1;
            buffer="";
        }
    }

    if(!buffer.empty()){
        char last_ch = buffer[buffer.length()-1];
        buffer.pop_back();
        answer.push_back(LZ78node{static_cast<unsigned char>(dictionary[buffer]),last_ch});
    }

    encoded=answer;
    return answer;
}

string LZ78::decode(){
    string res="";
    for(int i=0;i<encoded.size();i++){

    }
}


