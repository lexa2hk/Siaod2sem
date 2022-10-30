//
// Created by lexa2k on 29.10.2022.
//

#ifndef SIAOD2SEM_BINFILE_H
#define SIAOD2SEM_BINFILE_H
#include "Note.h"

struct binfile{
    static void textToBin( std::string text,  std::string bin);
    static int searchBin( std::string bin,  std::string name);
    static Note directAccessBin( std::string bin, int index);
    static void addBin( std::string bin, Note note);
};

#endif //SIAOD2SEM_BINFILE_H
