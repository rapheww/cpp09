/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:05:39 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/12 23:50:42 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

Rpn::Rpn(){}
Rpn::Rpn(const Rpn& cpy){*this = cpy;}
Rpn& Rpn::operator=(const Rpn& src){
    if (this != &src)
        _operand = src._operand;
    return *this;
}
Rpn::~Rpn(){}

int Rpn::isInt(std::string str){
    if (!(str.find_first_not_of("0123456789") == std::string::npos))
        return 0;
    if (str.size() > 2)
        throw(InvalidArg());
    double tester = strtod(str.c_str(), NULL);
    if (tester > 9)
        throw(InvalidArg());
    return 1;
}

void Rpn::parseInput(std::string input){
    std::stringstream inputStream(input);
    std::stack<std::string> tmp;
    std::string num;
    
    if (input.find_first_not_of("0123456789-+/* ") != std::string::npos)
        throw(InvalidArg());
    while(getline(inputStream, num, ' ')){
        tmp.push(num);
    }
    for(std::stack<std::string> dump = tmp; !dump.empty(); dump.pop()){
        _operand.push(dump.top());
    }
}

void Rpn::calculate(std::string input){
    std::string allOps[4] = {"+", "-", "/", "*"};
    int res;
    // std::string ops[2];
    int value;
    int i;
    
    try {
        parseInput(input);
        if (isInt(_operand.top())){
            res = atoi(_operand.top().c_str());
            _operand.pop();
        }
        while(!_operand.empty()){
            if (isInt(_operand.top())){
                value = atoi(_operand.top().c_str());
                _operand.pop();
            }
            for (i = 0; i < 4; i++)
                if (allOps[i] == _operand.top())
                    break;
            switch(i){
                case 0:
                    res += value;
                    break;
                case 1:
                    res -= value;
                    break;
                case 2:
                    res /= value;
                    break;
                case 3:
                    res *= value;
                    break;
                default:
                    throw(InvalidArg());
                    break;
            }
            _operand.pop();
        }   
    }
    catch(std::exception& e){
        std::cout<<"Error"<<std::endl;
        return ;
    }
    std::cout<<res<<std::endl;
        // int i;
        // for (i = 0; i < 4; i++)
        //     if (ops[i] == *itStr)
        //         break;
        // switch(i){
            
        // }
}


// Rpn::Rpn(){}
// Rpn::Rpn(const Rpn& cpy){*this = cpy;}
// Rpn& Rpn::operator=(const Rpn& src){
//     if (this != &src)
//         _operand = src._operand;
//     return *this;
// }
// Rpn::~Rpn(){}

// int isInt(std::string str){
//     if (!(str.find_first_not_of("0123456789") == std::string::npos))
//         return 0;
//     if (str.size() > 2)
//         return 0;
//     double tester = strtod(str.c_str(), NULL);
//     if (tester > 9)
//         return 0;
//     return 1;
// }

// std::vector<std::string> Rpn::parseInput(std::string input){
//     std::stringstream inputStream(input);
//     std::vector<std::string> str;
//     std::string num;
    
//     if (input.find_first_not_of("0123456789-+/* ") != std::string::npos)
//         throw(InvalidArg());
//     while(getline(inputStream, num, ' ')){
//         str.push_back(num);
//     }
//     std::vector<std::string>::iterator it = str.begin();
//     while(it != str.end()){
//         if (isInt(*it)){
//             _operand.push_back(atoi((*it).c_str()));
//             std::vector<std::string>::iterator tmp = it;
//             str.erase(it);
//             it = tmp;
//         }
//         else
//             it++;
        
//     }
//     std::cout<<"---INT VECTOR---"<<std::endl;
//     std::vector<int>::iterator it2 = _operand.begin();
//     for (; it2 != _operand.end(); it2++){
//         std::cout<<*it2<<" ";
//     }
//     std::cout<<std::endl;
//     return str;
// }

// void Rpn::calculate(std::string input){
//     std::vector<std::string> str = this->parseInput(input);
//     std::vector<std::string>::iterator itStr = str.begin();
//     std::vector<int>::iterator itOp = _operand.begin();
//     int res = *itOp;
//     std::string ops[4] = {"+", "-", "/", "*"};
//     itOp++;
//     while(itStr != str.end()){
//         int i;
//         for (i = 0; i < 4; i++)
//             if (ops[i] == *itStr)
//                 break;
//         switch(i){
            
//         }
//     }
    
    
// }
