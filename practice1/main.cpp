#include <iostream>
#include "struct.h"

int main(){
    int flagWork = 9;
    Arr firstArr(0);
    Arr secondArr(0);
    while (flagWork != 8){
        std::cout << "\n1. create new array\n"
                     "2. add new elements\n"
                     "3. delete array\n"
                     "4. get an element\n"
                     "5. get an array\n"
                     "6. summarize two arrays\n"
                     "7. difference two arrays\n"
                     "8. Exit\n";
        std::cin >> flagWork;
        std::cout << std::endl;
        if (flagWork > 8 || flagWork < 1){
            std::cout << "Wrong input\n";
        }
        if (flagWork == 1){
            //firstArr.~Arr();
            std::cout << "Enter the size of the array: ";
            int sizeArr;
            std::cin >> sizeArr;
            std::cout << std::endl;
            firstArr = Arr(sizeArr);
            firstArr.set();
        }
        if (flagWork == 2){
            firstArr.pushBack();
        }
        if (flagWork == 3){
            firstArr.~Arr();
        }
        if (flagWork == 4){
            std::cout << "Enter the index of the element: ";
            int index;
            std::cin >> index;
            std::cout << std::endl;
            firstArr.getNum(index);
            std::cout << std::endl;
        }
        if (flagWork == 5){
            firstArr.getArr();
        }
        if (flagWork == 6){
            //secondArr.~Arr();
            std::cout << "Enter the size of the array: ";
            int sizeArr;
            std::cin >> sizeArr;
            std::cout << std::endl;
            secondArr = Arr(sizeArr);
            secondArr.set();
            firstArr.sumArr(secondArr);
            firstArr.getArr();
        }
        if (flagWork == 7){
            //secondArr.~Arr();
            std::cout << "Enter the size of the array: ";
            int sizeArr;
            std::cin >> sizeArr;
            std::cout << std::endl;
            secondArr = Arr(sizeArr);
            secondArr.set();
            firstArr.diffArr(secondArr);
            firstArr.getArr();
        }
    }
    std::cout << "Goodbye!\n";
}