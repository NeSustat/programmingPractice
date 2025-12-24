#include <iostream>
#include "struct.h"

int main() {
    try {
        Arr arr(3);
        
        std::cout << "=== Testing array creation and input ===" << std::endl;
        // arr.set(); // Раскомментировать для интерактивного ввода
        
        std::cout << "=== Testing index out of range ===" << std::endl;
        try {
            arr.getNum(5); // Индекс вне диапазона
        } catch (const std::out_of_range& e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
        
        try {
            arr.getNum(0); // Индекс вне диапазона (должен быть >= 1)
        } catch (const std::out_of_range& e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
        
        std::cout << "=== Testing invalid argument ===" << std::endl;
        // Тест будет работать при интерактивном вводе значений > 100 или < -100
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}