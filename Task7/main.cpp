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
    system("chcp 65001");
    int choise=-1;
    cout<<"Лабораторная работа №7.'Алгоритмы сжатия'. Смольников Алексей. Вариант 2(22)"<<endl;
    while(choise!=0){
        cout<<"Выберите алгоритм сжатия:"<<endl;
        cout<<"1. RLE"<<endl;
        cout<<"2. LZ77"<<endl;
        cout<<"3. LZ78"<<endl;
        cout<<"4. Shennon-Fano"<<endl;
        cout<<"5. Huffman"<<endl;
        cout<<"0. Выход"<<endl;
        cin>>choise;

        switch (choise) {
            case 1:{
                cout<<"RLE encoding"<<endl;
                string RLEtext;
                cout<<"Введите текст: ";
                cin>>RLEtext;
                string textRLE = encodeRLE(RLEtext);
                cout<<"Закодированный текст: "<<textRLE<<endl;
                cout<<"Коэффициент сжатия:"<<calcucateCompressionRatio(RLEtext,textRLE)<<endl;

                cout<<"Encoding long random a-z string (100 000). Ratio: "<<calcucateCompressionRatio(encodeRLE(az100000),az100000)<<endl;
                break;
            }
            case 2:{
                cout<<"===========LZ77============"<<endl;
                LZ77 lz77;
                string text;
                text = "0100100010010000101";
                lz77.encode(text);
                cout<<"Коэффициент сжатия : "<<calcucateCompressionRatio(text,lz77.getEncodedLength())<<endl;

                cout<<"Закодированная последовательность: ";
                lz77.printEncoded();
                cout<<endl;

                cout<<"Обратная декодировка: "<<lz77.decode(lz77.encoded)<<endl;
                break;
            }

            case 3:{
                cout<<"===========LZ78============"<<endl;
                LZ78 lz78;
                string lz78text;
                lz78text = "upupapekapekaupup";
                lz78.encode(lz78text);
                cout<<"Текст: "<< lz78text<<endl;
                lz78.printEncoded();
                cout<<endl;

                cout<<"Длина: "<<lz78.getEncodedLength()<<endl;
                cout<<"Коэффициент сжатия: "<<calcucateCompressionRatio(lz78text,lz78.getEncodedLength())<<endl;
                break;
            }

            case 4:{
                cout<<"===========Shennon-Fano============"<<endl;
                string shenonText;
                cout<<"Текст: ";
                shenonText = "One, two, Freddy's coming for you \n"
                             "Three, four, better lock \n"
                             "your door Five, six, grab a crucifix \n"
                             "Seven, eight, gonna stay up late.\n";
                cout<<shenonText<<endl;
                ShennonFano ShFano;
                ShFano.encode(shenonText);
                cout<<"Коэффициент сжатия: "<<calcucateCompressionRatio(shenonText,ShFano.getByteSize())<<endl;

                cout<<"Декодированный текст: "<<ShFano.decode()<<endl;
                ShFano.printCodeTable();

                break;
            }

            case 5:{
                cout<<"===========Huffman============"<<endl;
                Huffman huffman;
                string huffmanText;
                cout<<"Текст: ";
                huffmanText = "Smolnikov Alexey Borisovich";
                huffman.encode(huffmanText);
                huffman.printEncoded();
                cout<<huffman.getEncodedLength()<<endl;

                cout<<"Декодированный текст: "<<huffman.decode()<<endl;
                cout<<"Коэффициент сжатия: "<<calcucateCompressionRatio(huffmanText,huffman.getEncodedLength())<<endl;


                cout<<"===========Huffman (encoding large)============"<<endl;
                Huffman huffmanLarge;
                huffmanLarge.encode("","world192.txt",true);
                cout<<"RATIO: "<<(double)huffmanLarge.getEncodedLength()/(double)huffmanLarge.s_length<<endl;

                break;
            }
            case 0:{
                cout<<"Выход"<<endl;
                break;
            }
        }
    }

    return 0;
}


