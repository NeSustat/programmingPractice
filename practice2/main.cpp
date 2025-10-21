#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <string>
#include <algorithm>

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
        std::sort(arr, arr + len); 
        return arr[len / 2];
    }
    void removeNoise(int step){
        int* tempArr = new int[width * height];
        for (int i = 0; i < width * height; i++){
            tempArr[i] = arr[i];
        }
        int halfStep = step / 2;
        for (int row = halfStep; row < height - halfStep; row++){
            for (int col = halfStep; col < width - halfStep; col++){
                int curArr[step * step];
                int index = 0;
                for (int dy = -halfStep; dy <= halfStep; dy++){
                    for (int dx = -halfStep; dx <= halfStep; dx++){
                        curArr[index++] = arr[(row + dy) * width + (col + dx)];
                    }
                }
                tempArr[row * width + col] = getMedian(curArr, step * step);
            }
        }
        for (int i = 0; i < width * height; i++){
            arr[i] = tempArr[i];
        }
        delete[] tempArr;
        save("repair");
    }
};

int main(){
    int flagStart = 2;
    int noiseVal = 20;
    int repairVal = 3;
    int flag = 0;
    while (flagStart){
        std::cout << "quit - 0\nstart - 1\n";
        std::cin >> flagStart;
        if (flagStart == 1){
            pgmImage firstPic("test.pgm");
            std::cout << "do you want to noise or restore the image?\n1 = noise\n2 = repair" << std::endl;
            std::cin >> flag;
            switch (flag){
            case 1:
                std::cout << "Enter noise values: " << std::endl;
                std::cin >> noiseVal;
                std::cout << std::endl;
                std::cout << "start make noise..."<< std::endl;
                firstPic.gaussianNoise(noiseVal);
                std::cout << "make noise done." << std::endl;
                break;
            case 2:
                std::cout << "Enter repair values: " << std::endl;
                std::cin >> repairVal;
                std::cout << std::endl;
                std::cout << "start make repair..."<< std::endl;
                firstPic.removeNoise(repairVal);
                std::cout << "make repair done." << std::endl;
            default:
                std::cout << "error" << std::endl;
                break;
            }
        }
        std::cout << std::endl;
    }
}