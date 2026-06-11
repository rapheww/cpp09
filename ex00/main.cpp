/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:22:08 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/11 23:16:21 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// std::multimap<std::string, double> parseInput(std::string inputFile){
//     std::string line;
//     std::ifstream infile(inputFile.c_str());
//     std::multimap<std::string, double> res;
    
//     if (!infile.is_open()){
//         std::cout<<"Invalid input file, make sure the file exists and you have the permissions\n"; return res;
//     }
//     while(getline(infile, line)){
//         if (!line.c_str() || line != "date,exchange_rate"){
//             size_t delimiter = line.find(",");
//             std::string date = line.substr(0, delimiter);
//             float amount = 0.0f;
//             if (delimiter == std::string::npos)
//                 amount = convertToFloat("");
//             else
//                 amount = convertToFloat(line.substr(delimiter + 1));
//             res.insert(std::pair<std::string, float>(date, amount));
//         }
//     }
//     infile.close();
//     return res;
// }

int main(int ac, char **av){
    if (ac != 2){
        std::cout<<"Program takes only 1 argument\n"; return 1;
    }
    // BitcoinExchange test;
    // std::string inputLine[2];
    // std::ifstream infile(av[1]);
    // if (!infile.is_open()){
    //     std::cout<<"Invalid input file, make sure the file exists and you have the permissions\n"; return 1;
    // }
    // std::string line;
    // std::getline(infile, line);
    // std::getline(infile, line);
    // while (getline(infile, line)){
    //     if (!line.empty() && line != "date | value"){
    //         size_t delimiter = line.find("|");
    //         inputLine[DATE] = line.substr(0, delimiter);
    //         if (delimiter == std::string::npos)
    //             inputLine[VALUE] = "";
    //         else
    //             inputLine[VALUE] = line.substr(delimiter + 1);
    //         test.exchange(inputLine);
    //     }
    // }
    (void)av;
    BitcoinExchange test;
    std::string line1[2] = {"2020", ""};
    std::string line2[2] = {"2020-13-01", ""};
    std::string line3[2] = {"202012-01", ""};
    std::string line4[2] = {"2020-1201", ""};
    std::string line5[2] = {"2020-12-32", ""};
    std::string line6[2] = {"2020-09-31", ""};
    std::string line7[2] = {"2026-02-29", ""};
    
    std::string line12[2] = {"2014-02-14", "1"};
    std::string line13[2] = {"2011-04-24", "2"};
    std::string line8[2] = {"2026-02-28", "1"};
    std::string line9[2] = {"2026-01-01", "1"};
    std::string line10[2] = {"2020-02-29", "1"};
    std::string line11[2] = {"2026-10-30", "1"};
    
    std::cout<<"INVALID\n";
    test.exchange(line1);
    test.exchange(line2);
    test.exchange(line3);
    test.exchange(line4);
    test.exchange(line5);
    test.exchange(line6);
    test.exchange(line7);
    std::cout<<"VALID DATE\n";
    test.exchange(line8);
    test.exchange(line9);
    test.exchange(line10);
    test.exchange(line11);
    test.exchange(line11);
    test.exchange(line12);
    test.exchange(line13);

    // std::cout<<"size of db : "<<test.getDataSize()<<std::endl;
    return 0;
}

// std::multimap<std::string, float> input = parseInput(av[1]);
// for (std::multimap<std::string, float>::iterator it = input.begin(); it !=input.end(); it++){
//     if (it->second < 0)
//         std::cout<<"Error : not a positive number\n";
//     else if (it->second == 1002)
//         std::cout<<"Error : bad input => "<<it->first<<std::endl;
//     else if (it->second > 1000)
//         std::cout<<"Error : too large number\n";
//     else
//         std::cout<<it->first<<" => "<<it->second <<" = "<<"N"<<std::endl;
// }
//pour chaque ligne du fichier -> check si date est bonne, si format est bon, si value est bonne (float ou int < 0 1000 >)