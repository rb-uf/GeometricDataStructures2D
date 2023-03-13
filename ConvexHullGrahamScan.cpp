
#include <vector>
#include <stack>
#include <algorithm>
#include "Number.h"
#include "SimplePoint2D.h"


SimplePoint2D origin = SimplePoint2D(0, 0);

Number square(Number n) { return n * n; }

Number abs(Number n)
{
    return (n < 0) ? Number("-1")*n : n;
}
Number sign(Number n)
{
    return (n < 0) ? Number("-1") : Number("1");
}

Number distSquared(SimplePoint2D a, SimplePoint2D b)
{
    return square(a.x - b.x) + square(a.y - b.y);
}

Number angleFactor(SimplePoint2D sp)
{
    return sign(sp.x) * (square(sp.x) / (square(sp.x) + square(sp.y)));
}

SimplePoint2D relativeCoord(SimplePoint2D origin, SimplePoint2D p)
{
    return SimplePoint2D(p.x - origin.x, p.y - origin.y);
}



// In an angular sweep counter-clockwise from the positive x axis to the negative
// x axis, if p1 is encountered before p2, return true. Otherwise, false.
// Calculated relative to an origin at (0, 0).
bool angularCompareFunc(SimplePoint2D p1, SimplePoint2D p2)
{
    // Note: p1 and p2 can be treated as position vectors
    // Inspiration: https://en.wikipedia.org/wiki/Cosine_similarity

    Number a1 = angleFactor(p1);
    Number a2 = angleFactor(p2);

    if (a1 != a2)
        return a1 > a2;
    else
        return distSquared(origin, p1) > distSquared(origin, p2);
}




// https://en.wikipedia.org/wiki/Graham_scan

std::vector<SimplePoint2D> ConvexHullGrahamScan(std::vector<SimplePoint2D> points)
{
    if (points.size() <= 3)
        return points;

    std::stack<SimplePoint2D> stack;

    // Let p0 be the point with the lowest y-coord and lowest x-coord (in that order)
    SimplePoint2D p0 = points[0];
    for (SimplePoint2D p : points) {
        if ((p.y < p0.y) || (p.y == p0.y && p.x < p0.x))
            p0 = p;
    }

    // This is a lambda expression. It will be used by std::sort to order the points.
    // A lambda function is needed here because the ordering is dependent on p0.
    auto comp = [p0](SimplePoint2D p1, SimplePoint2D p2) {
        return angularCompareFunc(relativeCoord(p0, p1), relativeCoord(p0, p2));
    };

    // Sort points by polar angle with P0
    std::sort(points.begin(), points.end(), comp);

    //for point in points:
        //# pop the last point from the stack if we turn clockwise to reach this point
        //while count stack > 1 and ccw(next_to_top(stack), top(stack), point) <= 0:
            //pop stack
        //push point to stack
    //end
}

