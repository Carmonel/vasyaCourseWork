#ifndef KURS_VASYA_POLYGON_H
#define KURS_VASYA_POLYGON_H

#include "lineSegment.h"
#include <vector>


class polygon {
private:
    std::vector<Point> points;
    Point main;
    size_t size;
    bool debug;
public:
    polygon(std::ifstream& inputFile, bool debug);
    void checkPoints();
    friend std::ostream& operator<<(std::ostream& out, const polygon& a);
    void isPointInsidePoly(std::ofstream& outputFile);
    ~polygon();
};

inline std::ostream& operator<<(std::ostream& out, const polygon& a){
    out << std::endl;
    out << "polygon.cpp // Polygon values: [";
    for (int i = 0; i < a.size; i++){
        out << a.points.at(i) << " ";
    }
    out << "]";
    return out;
}

#endif //KURS_VASYA_POLYGON_H