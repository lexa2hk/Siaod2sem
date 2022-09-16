// Created by lexa2k on 16.09.2022.
//
//bool generateFile(std::string name);
//bool printFile(std::string name);
//bool appendLine(std::string name, std::string line = "");
//bool readNumber(std::string name, int pos);
//bool countNumbers(std::string name);

#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>


bool generateFile(std::string name){
    std::ofstream file(name, std::ios::out);
    if (file.is_open()){

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(10, 100);

        int n = dis(gen);
        for(int i=0;i<n;i++){
            for(int j=0;j<dis(gen);j++){
                file << dis(gen) << " ";
            }
            file << std::endl;
        }

        file.close();
        return true;
    }
    return false;
}

bool printFile(std::string name){
    std::ifstream file(name, std::ios::in);
    if (file.is_open()){
        std::string line;
        while (getline(file, line)){
            std::cout << line << std::endl;
        }
        file.close();
        return true;
    }
    return false;
}

bool appendLine(std::string name, std::string line){
    std::ofstream file(name, std::ios::app);
    if (file.is_open()){
        file << line << std::endl;
        file.close();
        return true;
    }
    return false;
}

int readNumber(std::string name, int pos){
    std::ifstream file(name, std::ios::in);
    if (file.is_open()){
        std::string line;
        int i = 0;
        while (getline(file, line)){
            std::stringstream ss(line);
            int n;
            while (ss >> n){
                if (i == pos){
                    file.close();
                    return n;
                }
                i++;
            }

        }
        file.close();
        return NAN;
    }
    return NAN;
}

int countNumbers(std::string name){
    std::ifstream file(name, std::ios::in);
    if (file.is_open()){
        std::string line;
        int i = 0;
        while (getline(file, line)){
            std::stringstream ss(line);
            int n;
            while (ss >> n){
                i++;
            }
        }
        file.close();
        return i;
    }
    return NAN;
}

int copyFormatted(std::string name, std::string cp_name , int width){
    std::ifstream file(name, std::ios::in);
    if (file.is_open()){
        std::ofstream cp_file(cp_name, std::ios::out);
        if (cp_file.is_open()){
            std::string line;
            int cnt = 0;
            while (getline(file, line)){
                std::stringstream ss(line);
                int n;
                while (ss >> n){
                    if(cnt == width){
                        cp_file << std::endl;
                        cnt = 0;
                    }
                    cnt++;
                    cp_file << n << " ";

                }
            }
            cp_file.close();
            file.close();
            return true;
        }
        file.close();
        return false;
    }
    return false;
}

