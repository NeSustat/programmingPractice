#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <string>

int countImage = 1;

class pgmImage {
private:
    int width, height, maxVal;
    int* arr;
public:
    pgmImage(std::string nameFile){
        std::ifstream file;
        file.open(nameFile);
        std::string line;
        std::getline(file, line);
        std::getline(file, line);
        file >> width >> height >> maxVal;
        arr = new int[width * height];
        for (int i = 0; i < width * height; i++){
            file >> arr[i];
        }
        file.close();
    }
    ~pgmImage(){
        delete[] arr;
    }
    void save(){
        std::ofstream file;
        file.open("PicturesWithNoise/Image" + std::to_string(countImage) + ".pgm");
        file << "P2\n" << width << " " << height << std::endl;
        file << maxVal << std::endl;
        for (int i = 0; i < width * height; i++){
            file << arr[i] << std::endl;
        }
        file.close();
        countImage++;
    }
    void gaussianNoise(double sigma){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<double> noise(0.0, sigma);

        for (int i = 0; i < width * height; i++){
            double noiseValue = noise(gen);
            int newPixel = arr[i] + (int)noiseValue;
            arr[i] = std::max(0, std::min(maxVal, newPixel));
        }
    }
    int getMedian(int *arr, int len){
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if (arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return arr[len / 2];
    }

    void removeNoise(int step){
        int curArr[7] = {0};
        for (int i = 0; i < width * height - step; i++){
            for (int j = 0; j < step; j++){
                curArr[j] = arr[i + j];
            }
            arr[i + (step/2)] = getMedian(curArr, step);
        }
    }
};

int main(){
    pgmImage firstPic("test.pgm");
    firstPic.gaussianNoise(20);
    firstPic.save();
    firstPic.removeNoise(13);
    firstPic.save();
}