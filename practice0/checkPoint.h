#pragma once
#include "struct.h"
#include <iostream>


//проверка точки с кругом
void checkPointInsideShape(Circle* circle, Dots* dots);
void checkPointOnCont(Circle* circle, Dots* dots);

//проверка точки с квадратом
void checkPointInsideShape(Square* square, Dots* dots);
void checkPointOnCont(Square* square, Dots* dots);