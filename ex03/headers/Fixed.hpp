/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:00:54 by jceia             #+#    #+#             */
/*   Updated: 2021/12/14 19:14:39 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _raw;
    static const int fracBits = 8;
public:
    // Constructors
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& x);

    // Destructor
    ~Fixed(void);

    // Assignment operator
    Fixed& operator = (const Fixed& x);

    // Getters and Setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Converters
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison operators
    bool operator> (const Fixed& x) const;
    bool operator< (const Fixed& x) const;
    bool operator>= (const Fixed& x) const;
    bool operator<= (const Fixed& x) const;
    bool operator== (const Fixed& x) const;
    bool operator!= (const Fixed& x) const;

    // Arithmetic operators
    Fixed operator+ (const Fixed& x) const;
    Fixed operator- (const Fixed& x) const;
    Fixed operator* (const Fixed& x) const;
    Fixed operator/ (const Fixed& x) const;

    // Increment/Decrement operators
    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);

    // Min-Max
    static Fixed& min(Fixed& x, Fixed& y);
    static const Fixed& min(const Fixed& x, const Fixed& y);
    static Fixed& max(Fixed& x, Fixed& y);
    static const Fixed& max(const Fixed& x, const Fixed& y);
};

std::ostream& operator << (std::ostream &out, const Fixed& x);

#endif
