/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:00:54 by jceia             #+#    #+#             */
/*   Updated: 2021/11/01 19:09:33 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
    /* data */
    int _raw;
    static const int fracBits = 8;
public:
    Fixed(void);
    Fixed(const Fixed& obj);
    ~Fixed(void);

    Fixed& operator= (const Fixed& obj);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
