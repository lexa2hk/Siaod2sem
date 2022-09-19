//
// Created by lexa2k on 17.09.2022.

//Структура записи
//Расписание занятий группы: номер группы, название дисциплины, номер пары, номер недели, номер дня недели, вид занятия, номер аудитории.
//Доп. операция
//Сформировать в двоичном файле расписание заданной группы на заданный день недели.
//Обновить расписание, найти дисциплины, которые стоят на одинаковых парах в одной аудитории, и определить для них новые аудитории.

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

bool readFromFile(std::string fileName){
    std::ifstream file(fileName, std::ios::in);
    if (!file.is_open()){
        throw std::runtime_error("File not found");
    }

    Record record;

    while (!file.eof()){
        file >> record.group >> record.disciplineName >> record.pairNumber >> record.weekNumber >> record.dayNumber >> record.lessonType >> record.roomNumber;
        record.cutRecord();
        record.printRecord();
    }
    return true;
}

bool convertToBitFile(std::string fileName, std::string bitFileName){
    std::ifstream file(fileName, std::ios::in);
    if (!file.is_open()){
        throw std::runtime_error("File not found");
    }

    std::ofstream bitFile(bitFileName, std::ios::binary | std::ios::out);

    Record record;
    while (!file.eof()){
        file >> record.group>> record.disciplineName >> record.pairNumber >> record.weekNumber >> record.dayNumber >> record.lessonType >> record.roomNumber;
        record.cutRecord();
        bitFile.write(record.createNote().c_str(), record.createNote().size());
    }

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

    while (!bitFile.eof()){
        std::string note;
        std::getline(bitFile, note);
        file << note << std::endl;
    }

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
    while (!bitFile.eof()){
        std::string note;
        std::getline(bitFile, note);
        std::cout<< note << std::endl;
    }

    bitFile.close();
    return true;
}

