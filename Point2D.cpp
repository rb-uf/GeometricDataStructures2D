#include <algorithm>
#include "Point2D.h"


struct Point2D::Impl
{
    Impl(){};
    Impl(std::vector<SimplePoint2D> _pointCollection): pointCollection(move(_pointCollection)){};
    std::vector<SimplePoint2D> pointCollection;
};

Point2D::Point2D() {}

Point2D::Point2D(std::vector<SimplePoint2D> _pointCollection):pimpl(new Impl())
{
    _pointCollection.erase(unique(_pointCollection.begin(), _pointCollection.end()), _pointCollection.end());
    sort(_pointCollection.begin(), _pointCollection.end());
    this->pimpl->pointCollection = _pointCollection;
}

Point2D::Point2D(Point2D const &sourcePoint2D): pimpl(new Impl(*sourcePoint2D.pimpl))
{
}

Point2D::Point2D(Point2D &&sourcePoint2D)
{
    this->pimpl = move(sourcePoint2D.pimpl);
    sourcePoint2D.pimpl = nullptr;
}

<<<<<<< HEAD
Point2D::~Point2D() {}
=======
Point2D::~Point2D(){}

Point2D::iterator Point2D::begin() 
{
    return this->pimpl->pointCollection.begin();
}

Point2D::iterator Point2D::end() 
{
    return this->pimpl->pointCollection.end();
}
>>>>>>> 93ff9e2f1de2a6afc4b958cbc8828e83d652a30d
