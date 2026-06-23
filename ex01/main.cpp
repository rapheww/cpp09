/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:05:27 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/22 20:02:10 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout<<"program takes 1 argument"<<std::endl; return 0;
    }
    Rpn test;
    if (av[1][0] == '\0'){
        std::cout<<"Error\n"; return 0;
    }
    try{
        std::cout<<test.calculate(av[1])<<std::endl;
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}