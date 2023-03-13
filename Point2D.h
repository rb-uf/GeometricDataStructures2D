#ifndef POINT2D_H
#define POINT2D_H

#include <vector>
#include <memory>
#include "SimplePoint2D.h"
#include "Line2D.h"


class Point2D {
private:
    class Impl;
    std::unique_ptr<Impl> pimpl;

public:
    Point2D();
    Point2D(std::vector<SimplePoint2D> _pointCollection);
    Point2D(Point2D const &sourcePoint2D);
    Point2D(Point2D &&sourcePoint2D);
    ~Point2D();
};


#endif //POINT2D_H
