/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 22:44:27 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/16 23:25:45 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//     //print vector
//     std::list<int>::iterator it = _lunsorted.begin();
//     std::cout<<"VECTOR IS ->";
//     for(; it != _lunsorted.end(); it++)
//         std::cout<<" "<<*it;
//     std::cout<<std::endl;
// {
//     //print list
//     std::list<int>::iterator it = _lunsorted.begin();
//     std::cout<<"LIST IS ->";
//     for(; it != _lunsorted.end(); it++)
//         std::cout<<" "<<*it;
//     std::cout<<std::endl;
// }

Pmerge::Pmerge(){}
Pmerge::Pmerge(const Pmerge& cpy){*this = cpy;}
Pmerge& Pmerge::operator=(const Pmerge& src){
    if (this != &src){
        _vsorted = src._vsorted;
        _vunsorted = src._vunsorted;
        _lsorted = src._lsorted;
        _lunsorted = src._lunsorted;
    }
    return *this;
}
Pmerge::~Pmerge(){}
Pmerge::Pmerge(int* array, size_t size,int container){
    
    if (container == VECTOR){
        _container = VECTOR;
        for (size_t i = 0; i < size; i++){
            _vunsorted.push_back(array[i]);
        }
    }
    else if (container == LIST){
        _container = LIST;
        for (size_t i = 0; i < size; i++){
            _vunsorted.push_back(array[i]);
            _lunsorted.push_back(array[i]);
        }
    }
}

bool Pmerge::checksorted(){
    std::vector<int>::iterator it = _vunsorted.begin();
    for (; it != _vunsorted.end(); it++){
        std::vector<int>::const_iterator next = it + 1;
        if (next != _vunsorted.end() && *it > *next)
            return false; 
    }
    return true;
}

void Pmerge::printSorted(){
    if (_container == VECTOR){
        std::vector<int>::iterator it = _vunsorted.begin();
        std::cout<<GREEN BOLD "Sorted : " RESET GREEN;
        for(; it != _vunsorted.end(); it++)
        std::cout<<" [ "<<*it<<" ]";
        std::cout<<RESET<<std::endl;
    }
    if (_container == LIST){
        std::list<int>::iterator it = _lunsorted.begin();
        std::cout<<GREEN "Sorted : ";
        for(; it != _lunsorted.end(); it++)
            std::cout<<" "<<*it;
        std::cout<<RESET<< std::endl;
    }
}

void Pmerge::sort(){
    if(_container == VECTOR){
        if (checksorted()){
            printSorted();
            return ;
        }
        else{
            std::cout<<"Sorted : To sort ...\n";
        }
    }
}
