#include <cmath>
#include <iostream>
#include <ctime>
#include <fstream>
#include "struct.h"

class SaveFileCSV : public Arr {
public:
    SaveFileCSV(int n) : Arr(n) {
        iteration = n;
        if (n > 0) {
            data = new int[iteration];
            for(int i = 0; i < iteration; i++) {
                data[i] = i + 1;  // просто для примера
            }
        } else {
            data = nullptr;
        }
    }
    void getArr() override{
        time_t now = time(0);
        struct tm* local = localtime(&now);
        char filename[100];
        strftime(filename, 100, "%Y-%m-%d_%H.%M.%S.csv", local);
        std::ofstream file(filename);
        for (int i = 0; i < iteration; i++) {
            file << data[i] << std::endl;
        }
        file.close();
    }
};

class SaveFileTXT : public Arr { 
public:
    SaveFileTXT(int n) : Arr(n) {
        iteration = n;
        if (n > 0) {
            data = new int[iteration];
            for(int i = 0; i < iteration; i++) {
                data[i] = i + 1;  // просто для примера
            }
        } else {
            data = nullptr;
        }
    }
    void getArr() override{
        time_t now = time(0);
        struct tm* local = localtime(&now);
        char filename[100];
        strftime(filename, 100, "%Y-%m-%d_%H.%M.%S.txt", local);
        std::ofstream file(filename);
        for (int i = 0; i < iteration; i++) {
            file << data[i] << std::endl;
        }
        file.close();
    }
};

void getArr(Arr* arr) {
    arr->getArr();
}


int main(){
    Arr* a[2];
    a[0] = new SaveFileCSV(5);
    a[1] = new SaveFileTXT(5);
    for (int i = 0; i < 2; i++) {
        getArr(a[i]);
        delete a[i];
    }
}