/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:01:00 by jceia             #+#    #+#             */
/*   Updated: 2021/11/01 19:20:54 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
    : _raw(0)
{
    #ifdef DEBUG
    std::cout << "Default constructor called" << std::endl;
    #endif
}

Fixed::Fixed(const Fixed& obj)
{
    #ifdef DEBUG
    std::cout << "Copy constructor called" << std::endl;
    #endif
    // *this = obj;
    _raw = obj.getRawBits();
}

Fixed::~Fixed(void)
{
    #ifdef DEBUG
    std::cout << "Destructor called" << std::endl;
    #endif
}

Fixed&  Fixed::operator=(const Fixed& obj)
{
    #ifdef DEBUG
    std::cout << "Assignation operator called" << std::endl;
    #endif
    _raw = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    #ifdef DEBUG
    std::cout << "getRawBits member function called" << std::endl;
    #endif
    return (_raw);
}

void Fixed::setRawBits(int const raw)
{
    #ifdef DEBUG
    std::cout << "setRawBits member function called" << std::endl;
    #endif
    _raw = raw;
}
