/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:24:33 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/25 22:08:17 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <exception>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>
#include <ios>

# define VECTOR 0
# define LIST 1
# define SORTED 1
# define UNSORTED 0
# define GREEN	"\e[32m"
# define RED	"\e[31m"
# define RESET	"\e[0m"
# define BOLD	"\e[1m"

class Pmerge{
    public:
        Pmerge(int* array, size_t size, int container);
        Pmerge(const Pmerge& cpy);
        Pmerge& operator=(const Pmerge& src);
        ~Pmerge();

        std::clock_t sort();
        void printSorted( int status);
    private:
        Pmerge();
        int _container;
        // vector
        std::vector<int> _vsorted;
        std::vector<int> _vunsorted;

        std::vector<int> sortVector(std::vector<int>& container);
        std::list<int> sortList(std::list<int>& container);
        std::list<int>::iterator insertion(int target, std::list<int>::iterator low, std::list<int>::iterator high);
        size_t insertion(std::vector<int>& sorted, int target, size_t low, size_t high);
        bool checksorted();
        // list
        template <typename T>
        T next(T it, size_t value){
            while(value > 0){
                it++;
                value--;
            }
            return it;
        }
        std::list<int> _lsorted;
        std::list<int> _lunsorted;
};