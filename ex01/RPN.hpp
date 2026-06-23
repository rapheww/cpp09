/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:05:49 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/22 19:45:19 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class Rpn{
    public:
        Rpn();
        Rpn(const Rpn& cpy);
        Rpn& operator=(const Rpn& src);
        ~Rpn();

        class InvalidArg : public std::exception{};

        int isInt(std::string str);
        // void parseInput(std::string input);
        int calculate(std::string str);
    private:
        std::stack<std::string> _operand;
};
