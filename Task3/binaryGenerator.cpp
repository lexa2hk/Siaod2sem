//
// Created by lexa2k on 26.09.2022.
//
#include "binaryGenerator.h"
#include "bitFile.h"
#include <string>
#include <cstring>

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
            Record record;

            while(temp.size()!=8){
               temp = "0"+temp;
            }
            strcpy(record.key, temp.c_str());
            str="";

            for(int i=0;i<10;i++){
                str+=std::to_string(dis(gen)%10);
            }
            strcpy(record.group, str.c_str());
            str="";

            for(int i=0;i<3;i++){
                str+=std::to_string(dis(gen)%10);
            }
            strcpy(record.disciplineName, str.c_str());
            str="";

            str=std::to_string(dis(gen)%10);
            strcpy(record.week, str.c_str());
            str="";

            str=std::to_string(dis(gen)%10);
            strcpy(record.number, str.c_str());
            str="";

            str=std::to_string(dis(gen)%10);
            strcpy(record.day, str.c_str());
            str="";

            for(int i=0;i<3;i++){
                str+=std::to_string(dis(gen)%10);
            }
            strcpy(record.type, str.c_str());
            str="";

            temp = std::to_string(dis(gen)%1000);
            while(temp.size()!=3){
                temp = "0"+temp;
            }
            strcpy(record.aud, temp.c_str());
            str="";

            //print data from record to console
//            std::cout << record.key << " " << record.group << " " << record.disciplineName << " " << record.week << " " << record.number << " " << record.day << " " << record.type << " " << record.aud << std::endl;


            file.write((char*)&record, sizeof(Record));
        }
        file.close();
        std::cout << "File " << fileName << " was created" << std::endl;
    }
}