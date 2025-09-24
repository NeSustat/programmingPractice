#pragma once
#include <iostream>
#include <cmath>

class Arr {
    int iteration;
    int *data;
    bool checkGap(int a);
public:
    Arr(int n);
    Arr(const Arr &curData);
    ~Arr();
    void set();
    void pushBack();
    void getNum(int num);
    void getArr();
    void sumArr(Arr &a);
    void minusArr(Arr &a);
};