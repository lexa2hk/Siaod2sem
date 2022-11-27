//
// Created by lexa2k on 27.11.2022.
//

//for LZ77 use alphabet [0,1] and encode string "0100100010010000101"

#include "LZ77.h"

Node LZ77::fillNode(int off,int l, char nex){
    return Node{off,l,nex};
}

vector<Node> LZ77::encode(std::string text) {

    vector<Node> result;
    windowLength=text.length();

    result.push_back(fillNode(0,0,text[0]));

    for(int i=1;i<text.length();i++) {
        string window;
        if(true){
            window = text.substr(0,i);
        }else{
            window= text.substr(i-windowLength,windowLength);
        }

        //finding match in buffer
        int matchLength=0;
        int matchOffset=0;
        for(int j=0;j<window.length();j++){
            int k=0;
            int pos=j+k;
            int startPos=j+k;
            while(window[pos]==text[i+k]){
                k++;
                pos++;
                if(pos>=window.length()){
                    pos-=(int)window.length();
                }
            }
            if(k>matchLength){
                matchLength=k;
                matchOffset=i-startPos;
            }
        }

        if(matchLength==0){
            result.push_back(fillNode(0,0,text[i]));
        }else{
            result.push_back(fillNode(matchOffset,matchLength,text[i+matchLength]));
            i+=matchLength;
        }
    }

    encoded=result;
    return result;
}

string LZ77::decode(vector<Node> encoded){
    string result;
    for(int i=0;i<encoded.size();i++){
        if(encoded[i].offset==0){
            result+=encoded[i].next;
        }else{
            int pos=result.length()-encoded[i].offset;
            int resultLen=result.length();
            for(int j=0;j<encoded[i].length;j++){
                result+=result[pos];
                pos++;
                if(pos>=resultLen){
                    pos-=resultLen;
                }
            }
            result+=encoded[i].next;
        }
//        cout<<result<<endl;
    }
    return result;
}

void LZ77::printEncoded() {
    for(int i=0;i<encoded.size();i++){
        if(encoded[i].next=='\0'){
            cout<<"("<<encoded[i].offset<<","<<encoded[i].length<<", NTERM)"<<endl;
        }else{
            cout<<"("<<encoded[i].offset<<","<<encoded[i].length<<", "<<encoded[i].next<<")"<<endl;
        }

    }
}

int LZ77::getEncodedLength() {
    return encoded.size()*(1+1+1);
}
