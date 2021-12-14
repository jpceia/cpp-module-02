/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:50:59 by jceia             #+#    #+#             */
/*   Updated: 2021/12/14 19:14:30 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    // Constructors
    Point(void);
    Point(const Fixed& x, const Fixed& y);
    Point(const Point& p);

    // Destructor
    ~Point(void);

    // Assignment operator
    Point& operator = (const Point& p);

    // Getters
    const Fixed& getX(void) const { return _x; }
    const Fixed& getY(void) const { return _y; }

    // Arithmetic operators
    Point operator+ (const Point& other) const;
    Point operator- (const Point& other) const;

    // Dot product
    static Fixed dot_product(const Point& p, const Point& q);
};

std::ostream& operator << (std::ostream &out, const Point& p);

#endif
