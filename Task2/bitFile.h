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

bool readFromFile(std::string fileName);
bool convertToBitFile(std::string fileName, std::string bitFileName);
bool convertToBitFile(std::string fileName, std::string bitFileName);
bool convertToTextFile(std::string bitFileName, std::string fileName);
bool printBitFile(std::string bitFileName);



#endif //SIAOD2SEM_BITFILE_H
