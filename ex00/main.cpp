/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:22:08 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/08 23:27:48 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout<<"Program takes only 1 argument\n";
    }
    //open and check if is_open works on av[1] (file verification)
    //pour chaque ligne du fichier -> check si date est bonne, si format est bon, si value est bonne (float ou int < 0 1000 >)
    return 0;
}