/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:23:56 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/15 22:17:57 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av){
    if (ac < 2){
        std::cout<<"Program need at least 1 param"<<std::endl; return 0;
    }
    std::cout<<"Unsorted (size : "<<ac - 1<<") :";
    for (int i = 0; i < ac; i++)
        std::cout<<" "<<av[i];
    std::cout<<std::endl;
}