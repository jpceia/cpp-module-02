/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:01:03 by jceia             #+#    #+#             */
/*   Updated: 2021/12/14 18:49:33 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


int main(void) {
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;

    // some more tests
    std::cout << std::endl;
    std::cout << "Some extra tests..." << std::endl;
    std::cout << "the result is not supposed to be exactly the same" << std::endl;
    std::cout << "in floating and fixed point representation, due to" << std::endl;
    std::cout << "rounding errors" << std::endl;
    std::cout << std::endl;

    float x = 2.1;
    float y = 3.14;
    std::cout << "Smallest Fixed: " << ++Fixed(0) << std::endl;
    std::cout << std::endl;

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << std::endl;

    std::cout << "Addition: x + y" << std::endl;
    std::cout << "Float: " << x + y << std::endl;
    std::cout << "Fixed: " << Fixed(x) + Fixed(y) << std::endl;
    std::cout << std::endl;

    std::cout << "Subtraction: x - y" << std::endl;
    std::cout << "Float: " << x - y << std::endl;
    std::cout << "Fixed: " << Fixed(x) - Fixed(y) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Multiplication: x * y" << std::endl;
    std::cout << "Float: " << x * y << std::endl;
    std::cout << "Fixed: " << Fixed(x) * Fixed(y) << std::endl;
    std::cout << std::endl;

    std::cout << "Division: x / y" << std::endl;
    std::cout << "Float: " << x / y << std::endl;
    std::cout << "Fixed: " << Fixed(x) / Fixed(y) << std::endl;
    std::cout << std::endl;
    
    return 0;
}
