/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:05:27 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/12 23:39:56 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout<<"program takes 1 argument"<<std::endl; return 0;
    }
    Rpn test;
    test.calculate(av[1]);
    return 0;
}