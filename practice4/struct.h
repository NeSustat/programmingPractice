#pragma once
#include <iostream>
#include <cmath>

class Arr {
protected:
    int iteration;
    int *data;
    bool checkGap(int a);
public:
    Arr(int n);
    Arr(const Arr &curData);
    Arr& operator=(const Arr& other);
    ~Arr();
    void set();
    void pushBack();
    void getNum(int num);
    virtual void getArr();
    void sumArr(Arr &a);
    void diffArr(Arr &a);
};