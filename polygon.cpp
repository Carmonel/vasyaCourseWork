#include "polygon.h"
#include "fstream"

polygon::polygon(std::ifstream& inputFile, bool debug) {
    this->debug = debug;

    Point readPoint;
    int i = 1;
    while (inputFile >> readPoint.x >> readPoint.y){
        if (debug) std::cout << "Point " << i << " = " << readPoint << " scanned." << std::endl;
        points.push_back(readPoint);
    }

    main = points.back();
    points.pop_back();
    size = points.size();

    if (debug){
        std::cout << "Scanned " << size << " points:" << std::endl;
        for (int j = 0; j < size; j++){
            std::cout << points[j] << std::endl;
        }

        std::cout << "Working point: " << main << std::endl;
    }

    checkPoints();
};

void polygon::checkPoints() {
    if (debug) std::cout << std::endl << "polygon.h::checkPoints() // checkPoint() function initialized...";
    for (int i = 0; i < size-1; i++){
        for (int j = i+1; j < size; j++){
            if (points.at(i) == points.at(j)){
                std::cout << std::endl << "Equals points!";
                exit(-1);
            }
        }
    }
    if (debug) std::cout << std::endl << "polygon.h::checkPoints() // checkPoint() return true.";
}

polygon::~polygon(){
    points.clear();
}

void polygon::isPointInsidePoly(std::ofstream& outputFile) {
    Point rayEnd{main.x+100, main.y};

    int intersectionsCount = 0;

    lineSegment pointRay(main, rayEnd);

    if (debug) std::cout << std::endl << "Working with " << pointRay << std::endl;

    for (int i = 0; i < size; i++){
        if (i != size-1){
            if (debug) std::cout << "Checking for " << points.at(i) << " <-> " << points.at(i+1);
            lineSegment polyLine(points.at(i), points.at(i+1));

            if (isLinesIntersect(pointRay, polyLine)){
                intersectionsCount++;
                if (debug) std::cout << ": true.";
            }
            else if (debug) std::cout << ": false.";
            if (debug) std::cout << std::endl;
        }
        else{
            if (debug) std::cout << "Checking for " << points.at(i) << " <-> " << points.at(0);
            lineSegment polyLine(points.at(i), points.at(0));

            if (isLinesIntersect(pointRay, polyLine)){
                intersectionsCount++;
                if (debug) std::cout << ": true.";
            }
            else if (debug) std::cout << ": false.";
            if (debug) std::cout << std::endl;
        }
    }

    if (intersectionsCount % 2 == 1){
        if (debug) std::cout << "Inside poly!";
        outputFile << "Point " << main << " is inside the polygon.";
    }
    else{
        if (debug) std::cout << "Outside poly!";
        outputFile << "Point " << main << " is outside the polygon.";
    }
}