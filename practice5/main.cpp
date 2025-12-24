#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>
#include <cmath>

template<typename T>
class Array {
private:
    T* data;
    size_t size;
public:
    Array(size_t s) : size(s), data(new T[s]) {}
    ~Array() { delete[] data; }
    Array(const Array& other) : size(other.size), data(new T[size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    size_t getSize() const { return size; }
    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value>::type
    setElement(size_t index, const T& value) {
        if (index >= size) throw std::out_of_range("Index out of range");
        data[index] = value;
    }
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& arr);
    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, double>::type
    distance(const Array& other) const {
        if (size != other.size) throw std::invalid_argument("Arrays must have same size");
        double sum = 0;
        for (size_t i = 0; i < size; ++i) {
            double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }
    template<typename U = T>
    typename std::enable_if<!std::is_arithmetic<U>::value, double>::type
    distance(const Array& other) const {
        throw std::bad_typeid();
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
    os << "[";
    for (size_t i = 0; i < arr.size; ++i) {
        os << arr.data[i];
        if (i < arr.size - 1) os << ", ";
    }
    os << "]";
    return os;
}

int main() {
    Array<int> arr1(3);
    arr1[0] = 1; arr1[1] = 2; arr1[2] = 3;
    Array<int> arr2(3);
    arr2[0] = 4; arr2[1] = 5; arr2[2] = 6;
    std::cout << "Array 1: " << arr1 << std::endl;
    std::cout << "Array 2: " << arr2 << std::endl;
    try {
        arr1.setElement(1, 10);
        std::cout << "After setter: " << arr1 << std::endl;
        double dist = arr1.distance(arr2);
        std::cout << "Distance: " << dist << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    Array<std::string> strArr(2);
    strArr[0] = "hello"; strArr[1] = "world";
    std::cout << "String array: " << strArr << std::endl;
    try {
        Array<std::string> strArr2(2);
        strArr.distance(strArr2);
    } catch (const std::bad_typeid& e) {
        std::cout << "Distance not supported for non-numeric types" << std::endl;
    }
}