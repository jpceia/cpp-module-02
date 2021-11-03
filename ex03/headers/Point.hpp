/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:50:59 by jceia             #+#    #+#             */
/*   Updated: 2021/11/03 00:50:07 by jceia            ###   ########.fr       */
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
    Point(void);
    Point(const Fixed& x, const Fixed& y);
    Point(const Point& p);
    ~Point(void);

    //Point& operator = (const Point& p);

    // get
    const Fixed& getX(void) const { return _x; }
    const Fixed& getY(void) const { return _y; }

    // Arithmetic operators
    Point operator+ (const Point& other) const;
    Point operator- (const Point& other) const;

    // dot_product
    static Fixed dot_product(const Point& p, const Point& q);
};

std::ostream& operator << (std::ostream &out, const Point& p);

#endif
