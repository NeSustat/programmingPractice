#include "checkPoint.h"
#include <iostream>

const double errRate = 10^-5;

//проверка точки с кругом
void checkPointInsideCircle(Circle* circle, Dots* dots){
    double difX = abc(circle.center.x - dots.x);
    double difY = abc(circle.center.y - dots.y);
    if (difX < circle.radius + errRate && dify < circle.radius + errRate){
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

void checkPointOnCont(Circle* circle, Dots* dots){
    double difX = abc(circle.center.x - dots.x);
    double difY = abc(circle.center.y - dots.y);
    if (difX <= circle.radius + errRate && dify <= circle.radius + errRate &&
        difX >= circle.radius - errRate && dify >= circle.radius - errRate){
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

//проверка точки с квадратом
void checkPointInsideSqure(Squre* squre, Dots* dots){
    double rightLimit = circle.leftUp.x - errRate;
    double leftLimit = circle.leftUp.x + errRate + circle.side;
    double topLimit = circle.leftUp.y + errRate;
    double botLimit = circle.leftUp.y - errRate - circle.side;
    if (dots.x > leftLimit && dots.x < rightLimit && 
        dots.y > botLimit && dots.y < topLimit){
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

void checkPointOnSqure(Squre* squre, Dots* dots){

}