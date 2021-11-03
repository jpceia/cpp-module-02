/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:53:56 by jceia             #+#    #+#             */
/*   Updated: 2021/11/03 00:53:13 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <cstdlib>
#include <string>


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point u = b - a;
    Point v = c - a;
    Point p = point - a;

    Fixed sq_norm_u = Point::dot_product(u, u);
    Fixed sq_norm_v = Point::dot_product(v, v);

    Fixed x = Point::dot_product(p, u) / sq_norm_u;
    Fixed y = Point::dot_product(p, v) / sq_norm_v;

    std::cout << u << " " << v << std::endl;

    return (x >= 0 && y >= 0 && x + y <= 1);
}

Fixed fixed_parse(std::string s)
{
    return Fixed((float)std::atof(s.c_str()));
}

Point point_parse(std::string s)
{
    Fixed   x, y;
    size_t  pos;

    pos = s.find(',');
    if (pos == std::string::npos)
        return Point();
    x = fixed_parse(s.substr(0, pos));
    y = fixed_parse(s.substr(pos + 1, s.length()));
    return Point(x, y);
}

int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        std::cout << "Please provide four arguments." << std::endl;
        return (-1);
    }
    Point a = point_parse(argv[1]);
    Point b = point_parse(argv[2]);
    Point c = point_parse(argv[3]);
    Point point = point_parse(argv[4]);
    std::cout << "The point is ";
    std::cout << (bsp(a, b, c, point) ? "inside" : "outside");
    std::cout << " the triangle." << std::endl;
    return 0;
}
