#include <iostream>
#include <cmath>
#include "struct.h"

class AdvancedArr : public Arr {
    int *sortData;
    int max = 0;
    int min = 0;
    int avirage = 0;
    int mediana = 0;
public:
    AdvancedArr(int n) : Arr(n) {
        sortData = new int[n];
    }
    AdvancedArr(const Arr &curData) : Arr(curData) {
        sortData = new int[iteration];
    }
    ~AdvancedArr(){
        delete[] sortData;
    }
    void sortArr() {
        for (int i = 0; i < iteration; i++) {
            sortData[i] = data[i];
        }
        for (int i = 0; i < iteration - 1; i++) {
            for (int j = 0; j < iteration - i - 1; j++) {
                if (sortData[j] > sortData[j + 1]) {
                    int temp = sortData[j];
                    sortData[j] = sortData[j + 1];
                    sortData[j + 1] = temp;
                }
            }
        }
    }
    void findMax() {
        max = sortData[iteration - 1];
    }
    void findMin() {
        min = sortData[0];
    }
    void findAvirage() {
        for (int i = 0; i < iteration; i++) {
            avirage += sortData[i];
        }
        avirage /= iteration;
    }
    void findMediana() {
        if (iteration % 2 == 0) {
            mediana = (sortData[iteration / 2] + sortData[iteration / 2 - 1]) / 2;
        } else {
            mediana = sortData[iteration / 2];
        }
    }
    int getMax() {
        return max;
    }
    int getMin() {
        return min;
    }
    int getAvirage() {
        return avirage;
    }
    int getMediana() {
        return mediana;
    }
};

int main(){
    int n;
    std::cin >> n;
    AdvancedArr arr(n);
    arr.set();
    arr.sortArr();
    arr.findMax();
    arr.findMin();
    arr.findAvirage();
    arr.findMediana();
    std::cout << arr.getMax() << " " << arr.getMin() << " " << arr.getAvirage() << " " << arr.getMediana() << std::endl;
}
