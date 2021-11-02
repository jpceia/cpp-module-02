/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:00:54 by jceia             #+#    #+#             */
/*   Updated: 2021/11/02 22:22:34 by jceia            ###   ########.fr       */
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

    // Get-Set
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Converters
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison operators
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
    Fixed& operator++(void);    // Pre-Increment
    Fixed operator++(int);      // Post-Increment
    Fixed& operator--(void);    // Pre-Decrement
    Fixed operator--(int);      // Post-Decrement

    // Min-Max
    static Fixed& min(Fixed& x, Fixed& y);
    static const Fixed& min(const Fixed& x, const Fixed& y);
    static Fixed& max(Fixed& x, Fixed& y);
    static const Fixed& max(const Fixed& x, const Fixed& y);
};

// Ostream operator
std::ostream& operator << (std::ostream &out, const Fixed& x);

#endif
