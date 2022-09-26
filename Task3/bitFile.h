//
// Created by lexa2k on 17.09.2022.
//

#ifndef SIAOD2SEM_BITFILE_H
#define SIAOD2SEM_BITFILE_H

#include <string>
//
//struct Record {
//    std::string group;
//    std::string disciplineName;
//    std::string pairNumber;
//    std::string weekNumber;
//    std::string dayNumber;
//    std::string lessonType;
//    std::string roomNumber;
//
//    void cutRecord();
//    void printRecord();
//    std::string createNote();
//};

struct customVector{

    int size;
    std::string* data;

    int capacity;

    customVector();

    void push_back(std::string s);
    void print();

    ~customVector();
};

bool convertToBitFile(std::string fileName, std::string bitFileName);
bool convertToBitFile(std::string fileName, std::string bitFileName);
bool convertToTextFile(std::string bitFileName, std::string fileName);
bool printBitFile(std::string bitFileName);
bool directAccess(std::string bitFileName, int number, int length=32);
bool deleteByKey(std::string bitFileName, std::string key, int length=32);

void generateByWeekDay(std::string bitFileName, std::string group, std::string day);
std::string* splitter (std::string s, std::string delim, int size);

//Обновить расписание, найти дисциплины, которые стоят на одинаковых парах в одной аудитории, и определить для них новые аудитории.
void updateSchedule(std::string bitFileName, std::string newFileName);

bool addNoteToFile(std::string bitFileName, std::string note, int length=32);
int testBinF();

#endif SIAOD2SEM_BITFILE_H
