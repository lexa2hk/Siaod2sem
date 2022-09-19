//
// Created by lexa2k on 17.09.2022.

//Структура записи
//Расписание занятий группы: номер группы, название дисциплины, номер пары, номер недели, номер дня недели, вид занятия, номер аудитории.
//Доп. операция
//Сформировать в двоичном файле расписание заданной группы на заданный день недели.
//Обновить расписание, найти дисциплины, которые стоят на одинаковых парах в одной аудитории, и определить для них новые аудитории.

//001 ИКБО-10-21 Пр1 1 1 7 сем 223
//002 ИКБО-01-21 Пр2 2 1 7 сем 223
//003 ИКБО-02-21 Пр3 2 1 7 сем 220
//004 ИКБО-03-21 пр4 2 1 4 сем 220
//005 ИКБО-03-21 пр4 2 1 4 сем 220

#include "bitFile.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

struct Record {
    std::string hash;
    std::string group;
    std::string disciplineName;
    std::string pairNumber;
    std::string weekNumber;
    std::string dayNumber;
    std::string lessonType;
    std::string roomNumber;

    void cutRecord(){
        this->hash = this->hash.substr(0);
        this->group = this->group.substr(0, this->group.find(','));
        this->disciplineName = this->disciplineName.substr(0, this->disciplineName.find(','));
        this->pairNumber = this->pairNumber.substr(0, this->pairNumber.find(','));
        this->weekNumber = this->weekNumber.substr(0, this->weekNumber.find(','));
        this->dayNumber = this->dayNumber.substr(0, this->dayNumber.find(','));
        this->lessonType = this->lessonType.substr(0, this->lessonType.find(','));
        this->roomNumber = this->roomNumber.substr(0, this->roomNumber.find(','));
    }

    void printRecord(){
        std::cout << this->group << " " << this->disciplineName << " " << this->pairNumber << " " << this->weekNumber << " " << this->dayNumber << " " << this->lessonType << " " << this->roomNumber << std::endl;
    }

    std::string createNote(){
        std::string note = this->group + " " + this->disciplineName + " " + this->pairNumber + " " + this->weekNumber + " " + this->dayNumber + " " + this->lessonType + " " + this->roomNumber + "\n";
        return note;
    }
};


bool convertToBitFile(std::string fileName, std::string bitFileName){
    std::ifstream file(fileName, std::ios::in);
    if (!file.is_open()){
        throw std::runtime_error("File not found");
    }

    std::ofstream bitFile(bitFileName, std::ios::binary | std::ios::out);
    if (!bitFile.is_open()){
        throw std::runtime_error("File not found");
    }
//
//    Record record;
//    while (!file.eof()){
//        file >> record.group>> record.disciplineName >> record.pairNumber >> record.weekNumber >> record.dayNumber >> record.lessonType >> record.roomNumber;
//        record.cutRecord();
//        bitFile.write(record.createNote().c_str(), record.createNote().size());
//        std::string s;
//        std::getline(file, s);
//        bitFile<<s<<std::endl;
//    }
    bitFile << file.rdbuf();

    bitFile.close();
    file.close();
    return true;
}

bool convertToTextFile(std::string bitFileName, std::string fileName){
    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
    if (!bitFile.is_open()){
        throw std::runtime_error("File not found");
    }

    std::ofstream file(fileName, std::ios::out);
    if (!file.is_open()){
        throw std::runtime_error("File not found");
    }
    file<<bitFile.rdbuf();

    bitFile.close();
    file.close();
    return true;
}

bool printBitFile(std::string bitFileName){
    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
    if (!bitFile.is_open()){
        throw std::runtime_error("File not found");
    }

    std::cout<<"номер группы | название дисциплины | номер пары | номер недели | номер дня недели | вид занятия | номер аудитории"<<std::endl;
    std::cout<<bitFile.rdbuf();

    bitFile.close();
    return true;
}

bool directAccess(std::string bitFileName, int number, int length){

    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
    if (!bitFile.is_open()){
        throw std::runtime_error("File not found");
    }

    bitFile.seekg(0, std::ios::end);
    int size = bitFile.tellg();
    if ((length*sizeof(char)+10)*number > size){
        bitFile.close();
        return false;
    }

    bitFile.seekg((length*sizeof(char)+10)*number);
    std::string s;
    std::getline(bitFile, s);
    std::cout<<s<<std::endl;


    bitFile.close();
    return true;
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
    bitFile.seekg(size - length-9);

    std::string temp;

    std::getline(bitFile, temp);

    std::string tempNum = temp.substr(0, temp.find(' '));
    temp = key+ temp.substr(key.size(), temp.size());

    bitFile.seekg(0, std::ios::beg);

    std::string s;
    while (!bitFile.eof()){
        std::getline(bitFile, s);
        if(s.substr(0, key.size()) != key && s.substr(0, key.size()) != tempNum){
            tempFile<<s<<std::endl;
        } else if (s.substr(0, key.size()) == tempNum){

        }else{
            tempFile << temp << std::endl;
        }
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

std::string* splitter (std::string s, std::string delim = " ", int size =8){
    std::string* result = new std::string[size];
    int i = 0;
    while (s.find(delim) != std::string::npos){
        result[i] = s.substr(0, s.find(delim));
        s = s.substr(s.find(delim)+1, s.size());
        i++;
    }
    result[i] = s;
    return result;
}

void generateByWeekDay(std::string bitFileName, std::string group, std::string day){
    std::ifstream bitFile(bitFileName, std::ios::binary | std::ios::in);
    if (!bitFile.is_open()){
        throw std::runtime_error("File not found");
    }

    std::ofstream file("generated.bin", std::ios::out | std::ios::binary);

    std::string s;
    while (!bitFile.eof()){
        std::getline(bitFile, s);
        std::string* temp = splitter(s);
        if (temp[1] == group && temp[5] == day){
            file<<s<<std::endl;
        }
    }

    bitFile.close();
    file.close();
}
