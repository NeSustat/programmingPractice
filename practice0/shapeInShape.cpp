#include "shapeInShape.h"
#include "struct.h"
#include "checkOnCrosing.h"
#include "checkPoint.h"
#include <iostream>
#include <cmath>

bool shapeInShape(Circle firstCircle, Circle secondCircle){
    Circle big, small;
    if (firstCircle.radius > secondCircle.radius){
        big.center.x = firstCircle.center.x;
        big.center.y = firstCircle.center.y;
        big.radius = firstCircle.radius;
        small.center.x = secondCircle.center.x;
        small.center.y = secondCircle.center.y;
        small.radius = secondCircle.radius;
    } else {
        big.center.x = secondCircle.center.x;
        big.center.y = secondCircle.center.y;
        big.radius = secondCircle.radius;
        small.center.x = firstCircle.center.x;
        small.center.y = firstCircle.center.y;
        small.radius = firstCircle.radius;
    }
    double areaLoc = big.radius - small.radius;
    double difCenter = distance(firstCircle.center, secondCircle.center);
    if (difCenter < areaLoc && !checkOnCrosing(big, small)){
        return true;
        // std::cout << "Circle in circle\n";
    } else {
        return false;
        // std::cout << "Circle is not in circle\n";
    }
}

bool shapeInShape(Circle circle, Square square){
    Circle big, small;
    small.radius = square.side / 2.0;
    small.center.x = square.leftUp.x + small.radius;
    small.center.x = square.leftUp.y - small.radius;

    big.radius = (square.side * sqrt(2)) / 2.0;
    big.center.x = square.leftUp.x + small.radius;
    big.center.x = square.leftUp.y - small.radius;

    if (shapeInShape(circle, big)){
        std::cout << "Circle is in square\n";
    } else if (shapeInShape(circle, small)){
        std::cout << "Square is in circle\n";
    } else {
        std::cout << "Shape is not in shape";
    }
}

bool shapeInShape(Square firstSquare, Square secondSquare){
    Square small, big;
    if (firstSquare.side > secondSquare.side){
        small.side = secondSquare.side;
        small.leftUp.x = secondSquare.leftUp.x;
        small.leftUp.y = secondSquare.leftUp.y;
        big.side = firstSquare.side;
        big.leftUp.x = firstSquare.leftUp.x;
        big.leftUp.y = firstSquare.leftUp.y;
    } else {
        big.side = secondSquare.side;
        big.leftUp.x = secondSquare.leftUp.x;
        big.leftUp.y = secondSquare.leftUp.y;
        small.side = firstSquare.side;
        small.leftUp.x = firstSquare.leftUp.x;
        small.leftUp.y = firstSquare.leftUp.y;        
    }

    Dots smallRightBot, bigRightBot;
    smallRightBot.x = small.leftUp.x + small.side;
    smallRightBot.y = small.leftUp.y - small.side;
    
    bigRightBot.x = big.leftUp.x + big.side;
    bigRightBot.y = big.leftUp.y - big.side;

    if (!checkOnCrosing(big, small) && small.leftUp.x > big.leftUp.x && 
        small.leftUp.y < big.leftUp.y && smallRightBot.x < bigRightBot.x &&
        smallRightBot.y > bigRightBot.y){
            std::cout << "Square is in square";
        } else {
            std::cout << "Square is not in square";
        }
}