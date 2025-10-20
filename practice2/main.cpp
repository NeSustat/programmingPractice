#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <string>

int countImageNoise = 1;
int countImageRepair = 1;

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
    void save(std::string a){
        std::ofstream file;
        if (a == "noise"){
            file.open("Pictures/NoiseImage" + std::to_string(countImageNoise) + ".pgm");
            countImageNoise++;
        } else if (a == "repair"){
            file.open("Pictures/RepairImage" + std::to_string(countImageRepair) + ".pgm");
            countImageRepair++;
        }
        file << "P2\n" << width << " " << height << std::endl;
        file << maxVal << std::endl;
        for (int i = 0; i < width * height; i++){
            file << arr[i] << std::endl;
        }
        file.close();
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
        save("noise");
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
        save("repair");
    }
};

int main(){
    pgmImage firstPic("test.pgm");
    firstPic.gaussianNoise(20);
    firstPic.removeNoise(13);
}