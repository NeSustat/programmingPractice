#include <iostream>
#include <cmath>
#include "struct.h"

const float pi = 3.14;


int main(){
    int opt = 0;
    bool flag = true;
    std::cout << "circle = 1\nsquare = 2\n";
    while ((opt != 1 || opt != 2) && flag){
        std::cin >> opt; 
        switch (opt) {
        case 1:
            Circle firstCircle;
        
            //fill
            std::cout << "write X, Y and radius\n";
            std::cin >> firstCircle.center.x >> firstCircle.center.y >> 
                firstCircle.radius;
            firstCircle.len = 2 * pi * firstCircle.radius;
            firstCircle.square = pi * firstCircle.radius * 
                firstCircle.radius;
            
            //print 
            std::cout << "circle length: " << firstCircle.len << std::endl <<
                "the area of the circle: " << firstCircle.square << std::endl;
            flag = false;
            break;
        case 2:
            Square firstSquare;
            
            //fill
            std::cout << "write X, Y and side length\n";
            std::cin >> firstSquare.leftUp.x >> firstSquare.leftUp.y >> 
                firstSquare.side;
            firstSquare.square = firstSquare.side * firstSquare.side;
            firstSquare.perimeter = 4 * firstSquare.side;

            //print
            std::cout << "square area: " << firstSquare.square << std::endl <<
                "the perimeter of the square: " << firstSquare.perimeter << std::endl;
            flag = false;
            break;
        default:
            std::cout << "oops, something went wrong\ncircle = 1\nsquare = 2\n";
            std::cin >> opt;
            break;
        }
    }
    std::cout << "check point = 1\ncheck shape = 2\n";
    flag = true;
}