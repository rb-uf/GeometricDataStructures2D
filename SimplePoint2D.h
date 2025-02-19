#ifndef SIMPLEPOINT2D_H
#define SIMPLEPOINT2D_H
#include "Number.h"
#include <utility>

struct SimplePoint2D
{
    Number x, y;
    SimplePoint2D();
    SimplePoint2D(const SimplePoint2D& p);
    SimplePoint2D(Number x, Number y);
    SimplePoint2D(SimplePoint2D&& p);
    SimplePoint2D& operator=(SimplePoint2D&& p);
    SimplePoint2D& operator=(const SimplePoint2D& p);
    bool operator<(const SimplePoint2D p) const;
    bool operator<=(const SimplePoint2D p) const;
    bool operator==(const SimplePoint2D p) const;
    bool operator>=(const SimplePoint2D p) const;
    bool operator>(const SimplePoint2D p) const;
    bool operator!=(const SimplePoint2D p) const;
    void print() const;
};

SimplePoint2D randomSimplePoint2D(int minX, int maxX, int minY, int maxY);

#endif
