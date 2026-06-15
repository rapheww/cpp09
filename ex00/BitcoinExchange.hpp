/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:19:52 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/12 19:14:39 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include<cstdlib>

# define DATE 0
# define VALUE 1
# define MINYEAR 2009

class BitcoinExchange{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        class BadInputDate : std::exception{
            public:
                const char* what() const throw();
        };

        class BadInputValue : std::exception{
            public:
                const char* what() const throw();
        };
        class Overflow: std::exception{
            public:
                const char* what() const throw();
        };
        class NegativeValue: std::exception{
            public:
                const char* what() const throw();
        };
        class BadValue: std::exception{
            public:
                const char* what() const throw();
        };
        void checkDate(std::string date, char format);
        void checkValue(std::string value);
        void parseData();
        void exchange(std::string* line);
        size_t getDataSize();
    private:
        std::multimap<std::string, double> _data;
};