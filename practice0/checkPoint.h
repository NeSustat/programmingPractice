#pragma once
#include "struct.h"
#include <iostream>

double distance(Dots a, Dots b);

//проверка точки с кругом
bool checkPointInsideShape(Circle* circle, Dots* dots);
bool checkPointOnCont(Circle* circle, Dots* dots);

//проверка точки с квадратом
bool checkPointInsideShape(Square* square, Dots* dots);
bool checkPointOnCont(Square* square, Dots* dots);