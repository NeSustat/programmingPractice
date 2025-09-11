#include <iostream>
#include <cmath>
#include "struct.h"
#include "checkPoint.h"

const float pi = 3.14;


int main(){
    int opt = 0;
    bool flag = true;
    std::cout << "circle = 1\nsquare = 2\n\n";
    Dots dot;
    Circle firstCircle;
    Square firstSquare;
    Circle secondCircle;
    Square secondSquare;
    while (flag){
        std::cin >> opt; 
        switch (opt) {
        case 1:
            //fill
            std::cout << "write X, Y and radius\n\n";
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
            //fill
            std::cout << "write X, Y and side length\n\n";
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
            std::cout << "oops, something went wrong\ncircle = 1\nsquare = 2\n\n";
            std::cin >> opt;
            break;
        }
    }
    int optD = 0;
    flag = true;
        std::cout << "check point = 1\ncheck circle = 2\ncheak square = 3\n\n";
        std::cin >> optD;
    while (flag){
        switch (optD){
        case 1:
            std::cout << "write X and Y\n\n";
            std::cin >> dot.x >> dot.y;
            flag = false;
            break;
        case 2:
            std::cout << "write X, Y and radius\n\n";
            std::cin >> secondCircle.center.x >> secondCircle.center.y >> secondCircle.radius;
            flag = false;
            break;
        case 3:
            std::cout << "write X, Y and side length\n\n";
            std::cin >> secondSquare.leftUp.x >> secondSquare.leftUp.y >> secondSquare.side;
            flag = false;
            break;
        default:
            std::cout << "oops, something went wrong\ncheck point = 1\ncheck circle = 2\ncheak square = 3\n\n";
            std::cin >> optD;
            break;
        }
    }
    flag = true;        
    while (flag){
        switch (optD) {
        case 1:
            if (opt == 1){
                checkPointInsideShape(&firstCircle, &dot);
                checkPointOnCont(&firstCircle, &dot);
            } else if (opt == 2){
                checkPointInsideShape(&firstSquare, &dot);
                checkPointOnCont(&firstSquare, &dot);
            }
            flag = false;
            break;
        case 2:
            
            flag = false;
            break;
        case 3:
            
            flag = false;
            break;
        default:
            break;
        }
    }
}