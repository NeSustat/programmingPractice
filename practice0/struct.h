#pragma once

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