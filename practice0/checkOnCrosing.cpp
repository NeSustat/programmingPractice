#include "struct.h"
#include "checkOncrosing.h"
#include <iostream>
#include <cmath>

const double errRate = 1e-5;

//проверка двух кругов
void checkOncrosing(Circle firstCircle, Circle secondCircle){
    double difCenter = sqrt(pow(firstCircle.center.x - secondCircle.center.x, 2) + 
                            pow(firstCircle.center.y - secondCircle.center.y, 2));
    double maxDif = firstCircle.radius + secondCircle.radius + errRate;
    if (difCenter >= maxDif){
        std::cout << "\nCircles intersect";
    } else {
        std::cout << "\nCircles not intersect";
    }
}

//расширить границы квадрата на радиус круга и погрешность и проверять находится ли центр окружность внутки это квадрата
void checkOncrosing(Circle circle, Square square){
    double leftLimit, rightLimit, topLimit, botLiimit;
    leftLimit = square.leftUp.x - circle.radius - errRate;
    rightLimit = square.leftUp.x + square.side + circle.radius + errRate;
    topLimit = square.leftUp.y + circle.radius + errRate;
    dotLimit = square.leftUp.y - square.side - circle.radius - errRate;

    Dots leftUp, rightUp, leftBot, rightBot;
    leftUp.x = square.leftUp.x;
    leftUp.y = square.leftUp.y;

    rightUp.x = square.leftUp.x + square.side;
    rightUp.y = square.leftUp.y;

    leftBot.x = square.leftUp.x;
    leftBot.y = square.leftUp.y - square.side;

    rightBot.x = square.leftUp.x + square.side;
    rightBot.y = square.leftUp.y - square.side;

    if (((circle.center.x > leftUp.x && circle.center.x < rightUp.x && 
        circle.center.y < topLimit && circle.center.y > botLimit) ||
        (circle.center.y < leftUp.y && circle.center.y > leftBot.y && 
        circle.center.x > leftLimit && circle.center.x < rightLimit)) ||
        (sqrt(pow(circle.center.x - leftUp.x, 2) + 
        pow(circle.center.y - leftUp.Y, 2)) <= Circle.radius + errRate) ||
        (sqrt(pow(circle.center.x - rightUp.x, 2) + 
        pow(circle.center.y - rightUp.Y, 2)) <= Circle.radius + errRate) || 
        (sqrt(pow(circle.center.x - leftBot.x, 2) + 
        pow(circle.center.y - leftBot.Y, 2)) <= Circle.radius + errRate) || 
        (sqrt(pow(circle.center.x - rightBot.x, 2) + 
        pow(circle.center.y - rightBot.Y, 2)) <= Circle.radius + errRate)){
            std::cout << "\nCircle crosing square";
        } else {
            std::cout << "\nCircle not crosing square";
        }
}

//проверка двух квадратов
void checkOncrosing(Square firstSquare, Square secondSquare){

}