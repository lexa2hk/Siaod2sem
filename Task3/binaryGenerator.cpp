//
// Created by lexa2k on 26.09.2022.
//
#include "binaryGenerator.h"

void generateBinaryFile(std::string fileName, int length){


    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    if (file.is_open()){

        for(int i=0; i<length; i++) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(10000, 1000000);

            int num = dis(gen);

            std::string str;
            std::string temp = std::to_string(num);
            while(temp.size()!=8){
               temp = "0"+temp;
            }
            str+=temp;
            str+=" ";
            for(int i=0;i<10;i++){
                str+=std::to_string(dis(gen)%10);
            }
            str+=" ";
            for(int i=0;i<3;i++){
                str+=std::to_string(dis(gen)%10);
            }
            str+=" ";
            for(int i=0;i<3;i++){
                str+=std::to_string(dis(gen)%10);
                str+=" ";
            }
            for(int i=0;i<3;i++){
                str+=std::to_string(dis(gen)%10);
            }
            str+=" ";
            temp = std::to_string(dis(gen)%1000);
            while(temp.size()!=3){
                temp = "0"+temp;
            }
            str+=temp;
            str+="\n";

            file<<str;
        }
        file.close();
    }
}