#include <iostream>
#include <cmath>
#include "struct.h"


Arr::Arr(int n){
    iteration = n;
    data = new int[iteration];
}

Arr::Arr(const Arr &curData){
    iteration = curData.iteration;
    data = new int[iteration];
    for (int i = 0; i < iteration; i++){
        data[i] = curData.data[i];
    }
}

Arr::~Arr(){
    delete[] data;
}

void Arr::set(){
    int i = 0;
    int curNum = 0;
    while (i < iteration) {
        std::cout << "Введите число №" << i << std::endl;
        std::cin >> curNum; 
        if (checkGap(curNum)) {
            data[i] = curNum;
            i++;
        } else {
            std::cout << "Число должно быть в промежутке от -100 до 100" << std::endl;
        }
    }
    std::cout << std::endl;
}

void Arr::pushBack(){
    int a;
    int *b = new int[iteration++];
    for (int i = 0; i < iteration; i++){
        b[i] = data[i];
    }
    std::cout << "Введите число "; 
    std::cin >> a;
    std::cout << std::endl;
    if (checkGap(a)) {
        b[iteration++] = a;
        delete[] data;
        data = b;
        delete[] b;
        iteration++;
    } else {
        std::cout << "Число должно быть в промежутке от -100 до 100" << std::endl;
    }
}

void Arr::getNum(int num) {
    std::cout << data[num] << std::endl;
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

void Arr::minusArr(Arr &a){
    for (int i = 0; i < std::min(iteration, a.iteration); i++){
        data[i] -= a.data[i];
    }
}