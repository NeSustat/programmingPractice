#include "checkPoint.h"
#include "struct.h"
#include <iostream>
#include <cmath>

const double errRate = 1e-5;

//проверка точки с кругом
bool checkPointInsideShape(Circle* circle, Dots* dots){
    double difX = abs(circle->center.x - dots->x);
    double difY = abs(circle->center.y - dots->y);
    double difPoint = sqrt((difX * difX) + (difY * difY));
    return difPoint < circle->radius - errRate
}

bool checkPointOnCont(Circle* circle, Dots* dots){
    double difX = abs(circle->center.x - dots->x);
    double difY = abs(circle->center.y - dots->y);
    double difPoint = sqrt((difX * difX) + (difY * difY));
    return difPoint <= circle->radius + errRate &&
            difPoint >= circle->radius - errRate
}



//проверка точки с квадратом
bool checkPointInsideShape(Square* square, Dots* dots){
    double leftLimit = square->leftUp.x + errRate;
    double rightLimit = square->leftUp.x - errRate + square->side;
    double topLimit = square->leftUp.y - errRate;
    double botLimit = square->leftUp.y + errRate - square->side;

    return dots->x > leftLimit && dots->x < rightLimit && dots->y > botLimit && dots->y < topLimit
}

/*
                 ／＞'''フ        
                 |  _　_|         
              ／` ミ＿xノ         
             /　　     |        
            /　 ヽ　　 ﾉ          
            │　　|　|　|          
       ／￣|　　 |　|　|          
       (￣ヽ＿___ヽ_)__)          
       ＼二)ДАЛЬШЕ БОГА НЕТ...           
*/

bool checkPointOnCont(Square* square, Dots* dots){
    double leftLimit = square->leftUp.x - errRate;
    double rightLimit = square->leftUp.x + errRate + square->side;
    double topLimit = square->leftUp.y + errRate;
    double botLimit = square->leftUp.y - errRate - square->side;

    Dots leftUp, rightUp, leftBot, rightBot;
    double distLeftUp, distRightUp, distLeftBot, distRightBot;
    //left top point
    leftUp.x = square->leftUp.x;
    leftUp.y = square->leftUp.y;
    
    distLeftUp = sqrt(((leftUp.x - dots->x)*(leftUp.x - dots->x)) 
                    + ((leftUp.y - dots->y)*(leftUp.y - dots->y)));
    //right top point
    rightUp.x = square->leftUp.x + square->side;
    rightUp.y = square->leftUp.y;
    
    distRightUp = sqrt(((rightUp.x - dots->x)*(rightUp.x - dots->x)) 
                    + ((rightUp.y - dots->y)*(rightUp.y - dots->y)));
    //left bot point
    leftBot.x = square->leftUp.x;
    leftBot.y = square->leftUp.y - square->side;
    
    distLeftBot = sqrt(((leftBot.x - dots->x)*(leftBot.x - dots->x)) 
                    + ((leftBot.y - dots->y)*(leftBot.y - dots->y)));
    //right bot point
    rightBot.x = square->leftUp.x + square->side;
    rightBot.y = square->leftUp.y - square->side;

    distRightBot = sqrt(((rightBot.x - dots->x)*(rightBot.x - dots->x)) 
                    + ((rightBot.y - dots->y)*(rightBot.y - dots->y)));

    return (distLeftUp <= errRate) || 
        (distLeftBot <= errRate) ||
        (distRightUp <= errRate) ||
        (distRightBot <= errRate) ||
        (dots->y > leftBot.y && dots->y < leftUp.y && dots->x > leftLimit && dots->x < leftLimit + 2 * errRate) || 
        (dots->y > rightBot.y && dots->y < rightUp.y && dots->x < rightLimit && dots->x > rightLimit - 2 * errRate) || 
        (dots->x < rightBot.x && dots->x > leftBot.x && dots->y > botLimit && dots->y < botLimit - 2 * errRate) || 
        (dots->x < rightUp.x && dots->x > leftUp.x && dots->y < topLimit && dots->y > topLimit + 2 * errRate)
}