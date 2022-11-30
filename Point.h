#ifndef KURS_VASYA_POINT_H
#define KURS_VASYA_POINT_H

#include <iostream>

typedef struct{
    int x;
    int y;
} Point;

inline bool operator==(const Point& x, const Point& y){
    return (x.x == y.x) && (x.y == y.y);
}

inline void operator>>(std::istream& in, Point& a){
    in >> a.x >> a.y;
}

inline std::ostream& operator<<(std::ostream& out, const Point& a){
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}

#endif //KURS_VASYA_POINT_H
