#include "lineSegment.h"

lineSegment::lineSegment(Point P, Point Q) {
    first = P;
    second = Q;
}

lineSegment::~lineSegment() = default;

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;

    return false;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0)? 1: 2;
}

bool isLinesIntersect(const lineSegment& a, const lineSegment& b)
{
    Point p1 = a.first;
    Point q1 = a.second;
    Point p2 = b.first;
    Point q2 = b.second;

    // Ориентации
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // Общий случай
    if (o1 != o2 && o3 != o4)
        return true;

    // Спец случаи
    // p1, q1, p2 коллинеарны и p2 на отрезке p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1, q2 коллинеарны и q2 на отрезке p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2, p1 коллинеарны и p1 на отрезке p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2, q1 коллинеарны и q1 на отрезке p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}