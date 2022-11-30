//
// Created by lexa2k on 27.11.2022.
//
#include <iostream>
#include <string>
#include "LZ77.h"
#include "LZ78.h"
#include "ShennonFano.h"
#include "az100000.h"
#include "Huffman.h"

using namespace std;

double calcucateCompressionRatio(const string& text, const string& compressedText){ return static_cast<double>(compressedText.length())/static_cast<double>(text.length()); }
double calcucateCompressionRatio(const string& text, const int compressedSize){ return static_cast<double>(compressedSize)/static_cast<double>(text.length()); }

string encodeRLE(string data){
    string result;
    const unsigned long long len = data.length();
    if(len==0) return "";
    unsigned long long cnt=1;

    for(unsigned long long i=0;i<len;i++){
        if(i==len-1 || data[i]!=data[i+1]){
            result+=to_string(cnt);
            result+=data[i];
            cnt=1;
        } else cnt++;
    }

    return result;
}

string decodeRLE(string dataRLE){
    string result;
    const unsigned long long len = dataRLE.length();
    if(len==0) return "";
    unsigned long long cnt=0;

    for(unsigned long long i=0;i<len;i++){
        if(dataRLE[i]>='0' && dataRLE[i]<='9'){
            cnt*=10;
            cnt+=dataRLE[i]-'0';
        } else {
            for(unsigned long long j=0;j<cnt;j++) result+=dataRLE[i];
            cnt=0;
        }
    }

    return result;
}




int main(){

//    system("chcp 65001");
    setlocale(LC_CTYPE,"Russian");

    cout<<"RLE encoding"<<endl;
    string RLErepeat = "ABBBBABBBBBABBBBBABBBBBBAOOOOOOOSDSSSSSSSSHHHHHHHLLLLLLL%%%%%%%%%%";
    cout<<"Long repeating text: "<<RLErepeat<<endl;
    string textRLE = encodeRLE(RLErepeat);
    cout<<"Encoded text: "<<textRLE<<endl;
    cout<<"Ratio:"<<calcucateCompressionRatio(RLErepeat,textRLE)<<endl;

    cout<<"Encoding long a-z string (100 000). Ratio: "<<calcucateCompressionRatio(encodeRLE(az100000),az100000)<<endl;


    cout<<"===========LZ77============"<<endl;
    LZ77 lz77;
    string text = "0100100010010000101";
    cout<<"Input text: "<<text<<endl;
    lz77.encode(text);
    cout<<"Ratio : "<<calcucateCompressionRatio(text,lz77.getEncodedLength())<<endl;

    cout<<"Code: ";
    lz77.printEncoded();
    cout<<endl;

    cout<<"Back-decoded text: "<<lz77.decode(lz77.encoded)<<endl;


    cout<<"===========LZ78============"<<endl;
    LZ78 lz78;
    string lz78text= "упупапекапекаупуп";
    string lz78textENG="upupapekapekaupup";
    cout<<"Input text: "<<lz78textENG<<endl;

    lz78.encode(lz78textENG);
    cout<<"Encoded text: ";
    lz78.printEncoded();
    cout<<endl;

    cout<<"Length: "<<lz78.getEncodedLength()<<endl;
    cout<<"Compression ratio: "<<calcucateCompressionRatio(lz78textENG,lz78.getEncodedLength())<<endl;

    cout<<"===========Shennon-Fano============"<<endl;

    string shenonText = "One, two, Freddy's coming for you \n"
                        "Three, four, better lock \n"
                        "your door Five, six, grab a crucifix \n"
                        "Seven, eight, gonna stay up late.\n";

    ShennonFano ShFano;
    ShFano.encode(shenonText);
    cout<<"RATIO: "<<calcucateCompressionRatio(shenonText,ShFano.getByteSize())<<endl;

    cout<<"Decoded: "<<ShFano.decode()<<endl;


    cout<<"===========Huffman============"<<endl;
    Huffman huffman;
    string huffmanText = "Smolnikov Alexey Borisovich";
    huffman.encode(huffmanText);
    huffman.printEncoded();
    cout<<huffman.getEncodedLength()<<endl;

    cout<<"Decoded: "<<huffman.decode()<<endl;

    cout<<"RATIO: "<<calcucateCompressionRatio(huffmanText,huffman.getEncodedLength())<<endl;


    cout<<"===========Huffman (encoding large)============"<<endl;
    Huffman huffmanLarge;
    huffmanLarge.encode("","world192.txt",true);
    cout<<"RATIO: "<<(double)huffmanLarge.getEncodedLength()/(double)huffmanLarge.s_length<<endl;
    cout<<"Decoded: "<<huffmanLarge.decode()<<endl;
    return 0;
}


