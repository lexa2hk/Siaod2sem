//
// Created by lexa2k on 16.09.2022.
//

#ifndef SIAOD2SEM_TEXTFILE_H
#define SIAOD2SEM_TEXTFILE_H

#include <string>
#include <fstream>

bool generateFile(std::string name);
bool printFile(std::string name);
bool appendLine(std::string name, std::string line = "");
int readNumber(std::string name, int pos);
int countNumbers(std::string name);
int copyFormatted(std::string name, std::string cp_name , int width);


#endif //SIAOD2SEM_TEXTFILE_H
