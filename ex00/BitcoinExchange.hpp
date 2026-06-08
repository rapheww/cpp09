/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:19:52 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/08 23:22:50 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class BitcoinExchange{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();  
};