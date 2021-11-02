/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:01:00 by jceia             #+#    #+#             */
/*   Updated: 2021/11/02 21:05:31 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed(void)
    : _raw(0)
{
    #ifdef DEBUG
    std::cout << "Default constructor called" << std::endl;
    #endif
}

Fixed::Fixed(const int value)
{
    #ifdef DEBUG
    std::cout << "Int constructor called" << std::endl;
    #endif
    _raw = value << Fixed::fracBits;
}

Fixed::Fixed(const float value)
{
    #ifdef DEBUG
    std::cout << "Float constructor called" << std::endl;
    #endif
    _raw = (int)(roundf(value * (1 << Fixed::fracBits)));
}

Fixed::Fixed(const Fixed& x)
{
    #ifdef DEBUG
    std::cout << "Copy constructor called" << std::endl;
    #endif
    *this = x;
}

Fixed::~Fixed(void)
{
    #ifdef DEBUG
    std::cout << "Destructor called" << std::endl;
    #endif
}

Fixed&  Fixed::operator=(const Fixed& x)
{
    #ifdef DEBUG
    std::cout << "Assignation operator called" << std::endl;
    #endif
    _raw = x.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return (_raw);
}

void Fixed::setRawBits(int const raw)
{
    _raw = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_raw / (1 << Fixed::fracBits));
}

int Fixed::toInt(void) const
{
    return (_raw >> Fixed::fracBits);
}

std::ostream& operator << (std::ostream &out, const Fixed& x)
{
    out << x.toFloat();
    return out;
}
