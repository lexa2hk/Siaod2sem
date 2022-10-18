//
// Created by lexa2k on 17.09.2022.
//

#ifndef SIAOD2SEM_BITFILE_H
#define SIAOD2SEM_BITFILE_H

#include <string>

struct Record{
    char key[9];
    char group[11];
    char disciplineName[4];
    char week[2];
    char number[2];
    char day[2];
    char type[4];
    char aud[4];

};

static int RECORD_SIZE = sizeof(Record);

void printRecord(Record record);

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
Record directAccess(std::string bitFileName, int number, int length=38);
bool deleteByKey(std::string bitFileName, std::string key, int length=32);

void generateByWeekDay(std::string bitFileName, std::string group, std::string day);
std::string* splitter (std::string s, std::string delim, int size);

//Обновить расписание, найти дисциплины, которые стоят на одинаковых парах в одной аудитории, и определить для них новые аудитории.
void updateSchedule(std::string bitFileName, std::string newFileName);

bool addNoteToFile(std::string bitFileName, Record note, int length=38);
int testBinF();

#endif //SIAOD2SEM_BITFILE_H
