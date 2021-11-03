/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:43:09 by jceia             #+#    #+#             */
/*   Updated: 2021/11/03 00:50:25 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void)
    : _x(0), _y(0)
{
}

Point::Point(const Fixed& x, const Fixed& y)
    : _x(x), _y(y)
{
}

Point::Point(const Point &p)
    : _x(p._x), _y(p._y)
{
}

Point::~Point(void)
{
}

/*
Point& Point::operator= (const Point& p)
{
    this = Point(p);
    (void)p;
    return *this;
}
*/

// Arithmetic operators
Point Point::operator+ (const Point &p) const
{
    return Point(this->_x + p._x, this->_y + p._y);
}

Point Point::operator- (const Point &p) const
{
    return Point(this->_x - p._x, this->_y - p._y);
}

// Dot product
Fixed Point::dot_product(const Point &p, const Point &q)
{
    return (p._x * q._x + p._y * q._y);
}

// ostream operator
std::ostream& operator << (std::ostream &out, const Point& p)
{
    out << "(" << p.getX() << "," << p.getY() << ")";
    return out;
}
