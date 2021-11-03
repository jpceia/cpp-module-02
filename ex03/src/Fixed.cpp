/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:01:00 by jceia             #+#    #+#             */
/*   Updated: 2021/11/03 00:54:31 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors

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

// Destructor

Fixed::~Fixed(void)
{
    #ifdef DEBUG
    std::cout << "Destructor called" << std::endl;
    #endif
}

// Assigment operator

Fixed&  Fixed::operator=(const Fixed& x)
{
    #ifdef DEBUG
    std::cout << "Assignation operator called" << std::endl;
    #endif
    _raw = x.getRawBits();
    return *this;
}

// Getters

int Fixed::getRawBits(void) const
{
    return (_raw);
}

// Setters

void Fixed::setRawBits(int const raw)
{
    _raw = raw;
}

// Converters

float Fixed::toFloat(void) const
{
    return ((float)_raw / (1 << Fixed::fracBits));
}

int Fixed::toInt(void) const
{
    return (_raw >> Fixed::fracBits);
}

// ostream operator

std::ostream& operator << (std::ostream &out, const Fixed& x)
{
    out << x.toFloat();
    return out;
}

// Comparison operators

bool Fixed::operator> (const Fixed& x) const
{
    return (_raw > x._raw);
}

bool Fixed::operator< (const Fixed& x) const
{
    return (_raw < x._raw);
}

bool Fixed::operator>= (const Fixed& x) const
{
    return (_raw >= x._raw);
}

bool Fixed::operator<= (const Fixed& x) const
{
    return (_raw <= x._raw);
}

bool Fixed::operator== (const Fixed& x) const
{
    return (_raw == x._raw);
}

bool Fixed::operator!= (const Fixed& x) const
{
    return (_raw != x._raw);
}

// Arithmetic operators

Fixed Fixed::operator+ (const Fixed& x) const
{
    Fixed   res;

    res.setRawBits(_raw + x._raw);
    return res;
}

Fixed Fixed::operator- (const Fixed& x) const
{
    Fixed   res;

    res.setRawBits(_raw - x._raw);
    return res;
}

Fixed Fixed::operator* (const Fixed& x) const
{
    return (Fixed(this->toFloat() * x.toFloat()));
}

Fixed Fixed::operator/ (const Fixed& x) const
{
    return (Fixed(this->toFloat() / x.toFloat()));
}

// Increment/Decrement operators
Fixed& Fixed::operator++(void)
{
    ++_raw;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed   res = *this;
    
    ++_raw;
    return (res);
}

Fixed& Fixed::operator--(void)
{
    --_raw;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed   res = *this;
    
    --_raw;
    return (res);
}

Fixed& Fixed::min(Fixed& x, Fixed& y)
{
    if (x.getRawBits() > y.getRawBits())
        return (y);
    return (x);
}

const Fixed& Fixed::min(const Fixed& x, const Fixed& y)
{
    if (x.getRawBits() > y.getRawBits())
        return (y);
    return (x);
}

Fixed& Fixed::max(Fixed& x, Fixed& y)
{
    if (x.getRawBits() < y.getRawBits())
        return (y);
    return (x);
}

const Fixed& Fixed::max(const Fixed& x, const Fixed& y)
{
    if (x.getRawBits() < y.getRawBits())
        return (y);
    return (x);
}
