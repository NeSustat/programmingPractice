#pragma once
#include "struct.h"
#include <iostream>


//проверка точки с кругом
void checkPointInsideCircle(Circle *circle, Dots *dots);
void checkPointOnCont(Circle* circle, Dots* dots);

//проверка точки с квадратом
void checkPointInsideSquare(Square* square, Dots* dots);
void checkPointOnCont(Square* square, Dots* dots);