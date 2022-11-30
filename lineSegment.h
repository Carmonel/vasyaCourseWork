#ifndef KURS_VASYA_LINESEGMENT_H
#define KURS_VASYA_LINESEGMENT_H

#include <iostream>
#include <queue>
#include "Point.h"

class lineSegment{
private:
    Point first;
    Point second;
public:
    lineSegment(Point P, Point Q);
    friend std::ostream& operator<<(std::ostream& out, const lineSegment& a);
    friend bool isLinesIntersect(const lineSegment& a, const lineSegment& b);
    ~lineSegment();
};

inline std::ostream& operator<<(std::ostream& out, const lineSegment& a){
    out << "line( " << a.first << " - " << a.second << " )";
    return out;
}

bool isLinesIntersect(const lineSegment& a, const lineSegment& b);

#endif //KURS_VASYA_LINESEGMENT_H