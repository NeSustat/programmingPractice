#include <iostream>
#include <cmath>

const float pi = 3.14;

struct Dots{
    double x;
    double y;
};

struct Circle{
    Dots center;
    double radius;
    double len;
    double square;
};

struct Square{
    Dots leftUp;
    double side;
    double square;
    double perimeter;
};


int main(){
    int a;
    std::cout << "circle = 1\nsquare = 2\n";
    std::cin >> a; 
    if (a == 1){
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
            "the area of the circle: " << firstCircle.square;
    } else if (a == 2){
        Square firstSquare;
        
        //fill
        std::cout << "write X, Y and side length\n";
        std::cin >> firstSquare.leftUp.x >> firstSquare.leftUp.y >> 
            firstSquare.side;
        firstSquare.square = firstSquare.side * firstSquare.side;
        firstSquare.perimeter = 4 * firstSquare.side;

        //print
        std::cout << "square area: " << firstSquare.square << std::endl <<
            "the perimeter of the square: " << firstSquare.perimeter; 
    }

}