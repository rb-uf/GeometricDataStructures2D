#include "SimplePoint2D.h"
#include <iostream>

SimplePoint2D::SimplePoint2D()
{
}

SimplePoint2D::SimplePoint2D(const SimplePoint2D& p)
{
	this->x = p.x;
	this->y = p.y;
}

SimplePoint2D::SimplePoint2D(Number x, Number y)
{
	this->x = x;
	this->y = y;
}

SimplePoint2D::SimplePoint2D(SimplePoint2D&& p)
{
	this->x = std::move(p.x);
	this->y = std::move(p.y);
}

SimplePoint2D& SimplePoint2D::operator=(const SimplePoint2D& p)
{
	this->x = p.x;
	this->y = p.y;
	return *this;
}

SimplePoint2D& SimplePoint2D::operator=(SimplePoint2D&& p)
{
	this->x = std::move(p.x);
	this->y = std::move(p.y);
	return *this;
}

bool SimplePoint2D::operator<(SimplePoint2D p) const
{
	if ((*this).x < p.x)
		return true;
	else
		return ((*this).x == p.x && (*this).y < p.y);
}

bool SimplePoint2D::operator<=(SimplePoint2D p) const
{
	return (*this < p || *this == p);
}

bool SimplePoint2D::operator==(SimplePoint2D p) const
{
	return ((*this).x == p.x && (*this).y == p.y);
}

bool SimplePoint2D::operator>=(const SimplePoint2D p) const
{
	return !((*this) < p);
}

bool SimplePoint2D::operator>(const SimplePoint2D p) const
{
	return !((*this) <= p);
}

bool SimplePoint2D::operator!=(const SimplePoint2D p) const
{
	return !((*this) == p);
}

void SimplePoint2D::print() const
{
    std::cout << "(" << this->x << " " << this->y << ")";
}

SimplePoint2D randomSimplePoint2D(int minX, int maxX, int minY, int maxY)
{
    return SimplePoint2D(randomInt(minX, maxX), randomInt(minY, maxY));
}
