/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:22:08 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/12 19:03:43 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(std::string str){
    size_t begin = 0;
    size_t end = str.size();

    while(str[begin] && std::isspace(str[begin]))
        begin++;
    while(end > begin && std::isspace(str[end - 1]))
        end--;
    return str.substr(begin, end - begin);
}

int main(int ac, char **av){
    if (ac != 2){
        std::cout<<"Program takes only 1 argument\n"; return 1;
    }
    BitcoinExchange test;
    std::string line;
    std::string inputLine[2];
    std::ifstream infile(av[1]);
    if (!infile.is_open()){
        std::cout<<"Invalid input file, make sure the file exists and you have the permissions\n"; return 1;
    }
    while (getline(infile, line)){
        if (!line.empty() && line != "date | value"){
            size_t delimiter = line.find("|");
            inputLine[DATE] = trim(line.substr(0, delimiter));
            if (delimiter == std::string::npos)
                inputLine[VALUE] = "";
            else
                inputLine[VALUE] = trim(line.substr(delimiter + 1));
            test.exchange(inputLine);
        }
    }
    return 0;
}