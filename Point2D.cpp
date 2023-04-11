#include <algorithm>
#include <iostream>
#include "Point2D.h"
using namespace std;


struct Point2D::Impl
{
    Impl(){};
    Impl(vector<SimplePoint2D> _pointCollection): pointCollection(move(_pointCollection)){};

    vector<SimplePoint2D> pointCollection;
    bool deduplicated;
    bool sorted;
};

Point2D::Point2D() {}

Point2D::Point2D(vector<SimplePoint2D> _pointCollection):pimpl(new Impl())
{
    this->pimpl->pointCollection = _pointCollection;
    this->sort();
    this->deduplicate();
}

Point2D::Point2D(vector<SimplePoint2D> _pointCollection, bool deduplicate, bool sort) : pimpl(new Impl())
{
    this->pimpl->pointCollection = _pointCollection;
    if (deduplicate)
        this->deduplicate();
    if (sort)
        this->sort();
}

Point2D::Point2D(Point2D const &sourcePoint2D): pimpl(new Impl(*sourcePoint2D.pimpl)) {}

Point2D::Point2D(Point2D &&sourcePoint2D)
{
    this->pimpl = move(sourcePoint2D.pimpl);
    sourcePoint2D.pimpl = nullptr;
}

Point2D::~Point2D() {}

int Point2D::count() const
{
    return this->pimpl->pointCollection.size();
}

void Point2D::sort()
{
    if (this->pimpl->sorted)
        return;
    std::sort(this->pimpl->pointCollection.begin(), this->pimpl->pointCollection.end());
    this->pimpl->sorted = true;
}

void Point2D::deduplicate()
{
    if (this->pimpl->deduplicated)
        return;
    this->pimpl->pointCollection.erase(unique(this->pimpl->pointCollection.begin(), this->pimpl->pointCollection.end()), this->pimpl->pointCollection.end());
    this->pimpl->deduplicated = true;
}

Point2D::Iterator Point2D::begin() const
{
    return Iterator(&(this->pimpl->pointCollection)[0]);
}

Point2D::Iterator Point2D::end() const
{
    return Iterator(&(this->pimpl->pointCollection)[this->pimpl->pointCollection.size()]);
}

bool Point2D::isOrdered()
{
    return this->pimpl->sorted;
}
