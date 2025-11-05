#include <iostream>
#include <cmath>
#include "struct.h"

bool Arr::checkGap(int num){
    if (num > -100 && num < 100){
        return true;
    } else {
        return false;
    }
}

Arr::Arr(int n){
    iteration = n;
    if (n > 0) {
        data = new int[iteration];
    } else {
        data = nullptr;
    }
}


Arr::Arr(const Arr &curData){
    iteration = curData.iteration;
    data = new int[iteration]();
    for (int i = 0; i < iteration; i++){
        data[i] = curData.data[i];
    }

}

Arr& Arr::operator=(const Arr& other) {
    if (this != &other) {
        delete[] data;
        iteration = other.iteration;
                if (iteration > 0) {
            data = new int[iteration];
            for (int i = 0; i < iteration; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    return *this;
}


Arr::~Arr(){
    if (data != nullptr) {
        delete[] data;
    }
}


void Arr::set(){
    int i = 0;
    int curNum = 0;
    while (i < iteration) {
        std::cout << "Enter a number " << i+1 << std::endl;
        std::cin >> curNum; 
        if (checkGap(curNum)) {
            data[i] = curNum;
            i++;
        } else {
            std::cout << "the number should be in the range from -100 to 100" << std::endl;
        }
    }
    std::cout << std::endl;
}

void Arr::pushBack(){
    int a;
    std::cout << "Enter a number "; 
    std::cin >> a;
    std::cout << std::endl;
    
    if (checkGap(a)) {
        int *b = new int[iteration + 1]();
        for (int i = 0; i < iteration; i++){
            b[i] = data[i];
        }
        b[iteration] = a;
        delete[] data;
        data = b;
        iteration++;
    } else {
        std::cout << "the number should be in the range from -100 to 100" << std::endl;
    }
}


void Arr::getNum(int num) {
    std::cout << data[num-1] << std::endl;
}

void Arr::getArr() {
    for (int i = 0; i < iteration; i++) {
        std::cout << data[i] << std::endl;
    }
}

void Arr::sumArr(Arr &a){
    for (int i = 0; i < std::min(iteration, a.iteration); i++){
        data[i] += a.data[i];
    }
}

void Arr::diffArr(Arr &a){
    for (int i = 0; i < std::min(iteration, a.iteration); i++){
        data[i] -= a.data[i];
    }
}