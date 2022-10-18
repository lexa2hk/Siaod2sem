//
// Created by lexa2k on 17.09.2022.

#include "bitFile.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <map>


void printRecord(Record record){
    std::cout << record.key << " " << record.group << " " << record.disciplineName << " " << record.week << " " << record.number << " " << record.day << " " << record.type << " " << record.aud << std::endl;
}


//bool convertToBitFile(std::string fileName, std::string bitFileName){
//    std::ifstream file(fileName, std::ios::in);
//    if (!file.is_open()){
//        throw std::runtime_error("File not found");
//    }
//
//    std::ofstream bitFile(bitFileName, std::ios::binary | std::ios::out);
//    if (!bitFile.is_open()){
//        throw std::runtime_error("File not found");
//    }
//    bitFile << file.rdbuf();
//
//    bitFile.close();
//    file.close();
//    return true;
//}

//bool convertToTextFile(std::string bitFileName, std::string fileName){
//    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
//    if (!bitFile.is_open()){
//        throw std::runtime_error("File not found");
//    }
//
//    std::ofstream file(fileName, std::ios::out);
//    if (!file.is_open()){
//        throw std::runtime_error("File not found");
//    }
//    file<<bitFile.rdbuf();
//
//    bitFile.close();
//    file.close();
//    return true;
//}

bool printBitFile(std::string bitFileName){
    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
    if (!bitFile.is_open()){
        throw std::runtime_error("File not found");
    }

    std::cout<<"номер группы | название дисциплины | номер пары | номер недели | номер дня недели | вид занятия | номер аудитории"<<std::endl;

    Record record;
    while (bitFile.read((char*)&record, RECORD_SIZE)){
        printRecord(record);
    }

    std::cout<<std::endl;

    bitFile.close();
    return true;
}

Record directAccess(std::string bitFileName, int number, int length){

    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
    if (!bitFile.is_open()){
        throw std::runtime_error("File not found");
    }

    bitFile.seekg(0, std::ios::end);
    long long size = bitFile.tellg();

    bitFile.seekg(0, std::ios::beg);
    if ((length*sizeof(char))*number > size){
        bitFile.close();
        return {};
    }

    bitFile.seekg((length)*number);

    Record record;
    bitFile.read((char*)&record, sizeof(record));

    bitFile.close();
    return record;
}

bool deleteByKey(std::string bitFileName, std::string key, int length){
    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
    if (!bitFile.is_open()){
        throw std::runtime_error("File not found");
    }

    std::ofstream tempFile("temp.bin", std::ios::out | std::ios::binary);
    if (!tempFile.is_open()){
        bitFile.close();
        throw std::runtime_error("File not found");
    }

    bitFile.seekg(0, std::ios::end);
    int size = bitFile.tellg();
    bitFile.seekg(0, std::ios::beg);

    std::string s;
    Record record;
    while ( bitFile.read((char*)&record, sizeof(record))){
        if (record.key == key){
            continue;
        }
        tempFile.write((char*)&record, sizeof(record));
    }

    bitFile.close();
    tempFile.close();

    std::remove(bitFileName.c_str());
    if(std::rename("temp.bin", bitFileName.c_str())==0){
        return true;
    } else{
        return false;
    }

}

//std::string* splitter (std::string s, std::string delim = " ", int size =8){
//    std::string* result = new std::string[size];
//    int i = 0;
//    while (s.find(delim) != std::string::npos){
//        result[i] = s.substr(0, s.find(delim));
//        s = s.substr(s.find(delim)+1, s.size());
//        i++;
//    }
//    result[i] = s;
//    return result;
//}

//void generateByWeekDay(std::string bitFileName, std::string group, std::string day){
//    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
//    if (!bitFile.is_open()){
//        throw std::runtime_error("File not found");
//    }
//
//    std::ofstream file("generated.bin", std::ios::out | std::ios::binary);
//
//    std::string s;
//    while (!bitFile.eof()){
//        std::getline(bitFile, s);
//        std::string* temp = splitter(s);
//        if (temp[1] == group && temp[5] == day){
//            file<<s<<std::endl;
//        }
//    }
//
//    bitFile.close();
//    file.close();
//}

//
//customVector::customVector() {
//    data = new std::string[1];
//    size = 0;
//    capacity = 1;
//}
//void customVector::push_back(std::string s){
//    if (size == capacity){
//        std::string* temp = new std::string[capacity*2];
//        for (int i = 0; i < size; i++){
//            temp[i] = data[i];
//        }
//        delete[] data;
//        data = temp;
//        capacity *= 2;
//    }
//    data[size] = s;
//    size++;
//}
//void customVector::print(){
//    for (int i = 0; i < size; i++){
//        std::cout<<data[i]<<std::endl;
//    }
//}
//
//customVector::~customVector(){
//    delete[] data;
//}
//
//void updateSchedule(std::string bitFileName, std::string newFileName){
//
//    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
//    if (!bitFile.is_open()){
//        throw std::runtime_error("File not found");
//    }
//
//    std::ofstream tempFile(newFileName, std::ios::out | std::ios::binary);
//    if (!tempFile.is_open()){
//        bitFile.close();
//        throw std::runtime_error("File not found");
//    }
//
//
//    customVector scheudele;
//    std::string s;
//    while (!bitFile.eof()){
//        std::getline(bitFile, s);
//        std::string* temp = splitter(s);
////        s = temp[0] + " " + temp[3] + " " + temp[4] + " " + temp[5] + " " + temp[7];
//        scheudele.push_back(s);
//    }
//
//    scheudele.print();
//
//    for(int i=0;i<scheudele.size;i++){
//        std::string* temp = splitter(scheudele.data[i]);
//
////        for(int z=0;z<8;z++){
////            tempFile<<"!"<<temp[z];
////        }
////        tempFile<<std::endl;
//
//
//        for(int j=i+1;j<scheudele.size;j++){
//            std::string* temp2 = splitter(scheudele.data[j]);
//            if(temp[7]==temp2[7] && temp[3]==temp2[3] && temp[4]==temp2[4] && temp[5]==temp2[5]){
//                scheudele.data[i] = temp[0]+ " " +temp[1] + " " + temp[2] + " " + temp[3] + " " + temp[4] + " " + temp[5] + " " + temp[6] + " "  + std::to_string(200+ rand()%100);
//            }
//        }
//    }
//
//    for(int i=0;i<scheudele.size;i++){
//        tempFile<<scheudele.data[i]<<std::endl;
//    }
//
//    bitFile.close();
//    tempFile.close();
//}

bool addNoteToFile(std::string bitFileName, Record note, int length){
    std::fstream bitFile(bitFileName, std::ios::binary| std::ios::out | std::ios::app);
    if (!bitFile.is_open()){
        return false;
    }

    bitFile.write((char*)&note, length);
    bitFile.close();
    return true;
}


int testBinF(){

    std::string bitFileName = "trueBinShort.bin";

    Record record = {"00465001","5322703905","664","0","8","9","034","817"};

    printBitFile(bitFileName);

    addNoteToFile(bitFileName, record, sizeof(record));

    printBitFile(bitFileName);

    deleteByKey(bitFileName, "00465001");

    printBitFile(bitFileName);
    std::cout<<std::endl;
    directAccess(bitFileName, 0);


    return 0;
}