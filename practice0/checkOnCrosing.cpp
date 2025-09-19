#include "struct.h"
#include "checkOncrosing.h"
#include <iostream>
#include <cmath>

const double errRate = 1e-5;

//проверка двух кругов
bool checkOnCrosing(Circle firstCircle, Circle secondCircle){
    double difCenter = sqrt(pow(firstCircle.center.x - secondCircle.center.x, 2) + 
                            pow(firstCircle.center.y - secondCircle.center.y, 2));
    double maxDif = firstCircle.radius + secondCircle.radius + errRate;
    if (difCenter >= maxDif){
        return true;
        std::cout << "\nCircles intersect";
    } else {
        return false;
        std::cout << "\nCircles not intersect";
    }
}

/*
                 ／＞'''フ        
                 |  _　_|         
              ／` ミ＿xノ         
             /　　     |        
           / 　 ヽ　　 ﾉ          
         / │　　|　|　|          
       ／￣|　　 |　|　|          
       (￣ヽ＿___ヽ_)__)          
       ＼二)ДАЛЬШЕ БОГА НЕТ...           
*/

//расширить границы квадрата на радиус круга и погрешность и проверять находится ли центр окружность внутки это квадрата
void checkOnCrosing(Circle circle, Square square){
    //фантомные ограничения с учетом радиуса и погрешности
    double leftLimit, rightLimit, topLimit, botLimit;
    leftLimit = square.leftUp.x - circle.radius - errRate;
    rightLimit = square.leftUp.x + square.side + circle.radius + errRate;
    topLimit = square.leftUp.y + circle.radius + errRate;
    botLimit = square.leftUp.y - square.side - circle.radius - errRate;

    //углы квадрата
    Dots leftUp, rightUp, leftBot, rightBot;
    leftUp.x = square.leftUp.x;
    leftUp.y = square.leftUp.y;

    rightUp.x = square.leftUp.x + square.side;
    rightUp.y = square.leftUp.y;

    leftBot.x = square.leftUp.x;
    leftBot.y = square.leftUp.y - square.side;

    rightBot.x = square.leftUp.x + square.side;
    rightBot.y = square.leftUp.y - square.side;

    if (((circle.center.x > leftUp.x && circle.center.x < rightUp.x && //ограничения для X (правая и левая граница)
        circle.center.y < topLimit && circle.center.y > square.leftUp.y - circle.radius - errRate) || //ограничения для Y (верх низ) и так еще 3 раза
        (circle.center.y < leftUp.y && circle.center.y > leftBot.y && 
        circle.center.x > leftLimit && circle.center.x < square.leftUp.x + circle.radius + errRate) || 
        (circle.center.x > leftUp.x && circle.center.x < rightUp.x && 
        circle.center.y > botLimit && circle.center.y < square.leftUp.y + circle.radius - square.side + errRate) ||
        (circle.center.y < leftUp.y && circle.center.y > leftBot.y && 
        circle.center.x < rightLimit && circle.center.x > square.leftUp.x + square.side - circle.radius - errRate)) ||
        (sqrt(pow(circle.center.x - leftUp.x, 2) + //в углах погрешность считается как радиус < расстояние между углом и центром окружности
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
bool checkOnCrosing(Square firstSquare, Square secondSquare){
    Square small, big;
    if (firstSquare.side > secondSquare.side){
        small.side = secondSquare.side;
        small.leftUp.x = secondSquare.leftUp.x;
        small.leftUp.y = secondSquare.leftUp.y;
        bid.side = firstSquare.side;
        bid.leftUp.x = firstSquare.leftUp.x;
        big.leftUp.y = firstSquare.leftUp.y;
    } else {
        bid.side = secondSquare.side;
        bid.leftUp.x = secondSquare.leftUp.x;
        bid.leftUp.y = secondSquare.leftUp.y;
        small.side = firstSquare.side;
        small.leftUp.x = firstSquare.leftUp.x;
        small.leftUp.y = firstSquare.leftUp.y;        
    }
    Dots points[4];
    points[0].x = small.leftUp.x;
    points[0].y = small.leftUp.y;

    points[1].x = small.leftUp.x + square.side;
    points[1].y = small.leftUp.y;

    points[2].x = small.leftUp.x;
    points[2].y = small.leftUp.y - square.side;

    points[3].x = small.leftUp.x + square.side;
    points[3].y = small.leftUp.y - square.side;

    int count = 0;
    for (int i = 0, i < 4, i++){
        if (checkPointOnCont(&big, &points[i]) || checkPointInsideShape(&big, &points[i])){
            count++;
        }
    }
    if (count > 0 && count < 4){
        return true;
        std::cout << "Square crosing";
    } else {
        return false;
        std::cout << "Square not crosing";
    }
}