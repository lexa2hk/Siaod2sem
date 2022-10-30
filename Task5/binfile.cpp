//
// Created by lexa2k on 29.10.2022.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Note.h"
#include "binfile.h"

void printNoteNative(Note note){
    std::cout << "Note: " << note.name << " " << note.people << " " << note.Uno << std::endl;
}


void binfile::textToBin(std::string text, std::string bin){
    std::ifstream fin(text, std::ios::in);
    std::ofstream fout(bin, std::ios::binary | std::ios::out);
    std::string line;
    while(std::getline(fin, line)){
        Note note;
        std::stringstream ss(std::ios::in | std::ios::out);
        ss << line;
        ss >> note.name >> note.people >> note.Uno;

        fout.write((char*)&note, sizeNote);
    }
    fin.close();
    fout.close();
}

int binfile::searchBin( std::string bin,  std::string name){
    std::ifstream fin(bin, std::ios::binary | std::ios::in);
    Note note;
    int i=0;
    while(!fin.eof()){
        fin.read((char*)&note, sizeNote);

        if(strcmp(note.name, name.c_str())!=0){
            printNoteNative(note);
            return i;
        }

        i++;
    }
    fin.close();
    return -1;
}

Note binfile::directAccessBin( std::string bin, int index){
    std::ifstream fin(bin, std::ios::binary | std::ios::in);
    Note note;
    fin.seekg(index*sizeNote);
    fin.read((char*)&note, sizeNote);
    printNoteNative(note);
    fin.close();
    return note;
}

void binfile::addBin(std::string bin, Note note){
    std::ofstream fout(bin, std::ios::binary | std::ios::app);
    fout.write((char*)&note, sizeNote);
    fout.close();
}
