#include <iostream>
#include <fstream>
#include <string>
#include "polygon.h"

using std::cout;

int main(int argc, char* argv[]) {
    if ((argc != 3) && (argc != 4)){
        std::cout << "Incorrect arguments!" << std::endl << "Structure: [exe] [input_path] [output_path]";
        std::cout << std::endl << "Example: *.exe C:/input.txt C:/output.txt";
        exit(-1);
    }

    bool debug = false;
    if (argc == 4){
        std::string temp(argv[3]);
        if (temp != "-v"){
            std::cout << "Incorrect debug argument: use '-v' or nothing.";
            exit(-1);
        }
        debug = true;
    }

    std::ifstream inputFile(argv[1]);
    if (inputFile.fail()){
        std::cout << "Input file path incorrect.";
        exit(-1);
    }

    std::ofstream outputFile(argv[2]);
    if (outputFile.fail()){
        std::cout << "Output file path incorrect.";
        exit(-1);
    }
    outputFile.clear();

    polygon main(inputFile, debug);

    inputFile.close();

    main.isPointInsidePoly(outputFile);
}