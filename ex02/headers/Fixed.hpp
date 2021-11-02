/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:00:54 by jceia             #+#    #+#             */
/*   Updated: 2021/11/02 21:15:22 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    /* data */
    int _raw;
    static const int fracBits = 8;
public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& x);
    ~Fixed(void);

    Fixed& operator = (const Fixed& x);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    // comparison operators
    bool operator> (const Fixed& x);
    bool operator< (const Fixed& x);
    bool operator>= (const Fixed& x);
    bool operator<= (const Fixed& x);
    bool operator== (const Fixed& x);
    bool operator!= (const Fixed& x);

    // Arithmetic operators
    Fixed operator+ (const Fixed& x);
    Fixed operator- (const Fixed& x);
    Fixed operator* (const Fixed& x);
    Fixed operator/ (const Fixed& x);

    // Increment/Decrement operators
    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);

    static Fixed& min(Fixed& x, Fixed& y);
    static const Fixed& min(const Fixed& x, const Fixed& y);
    static Fixed& max(Fixed& x, Fixed& y);
    static const Fixed& max(const Fixed& x, const Fixed& y);
};

std::ostream& operator << (std::ostream &out, const Fixed& x);

#endif
