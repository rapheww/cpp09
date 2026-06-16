/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:24:33 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/16 23:24:24 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <exception>
#include <cstdlib>
#include <vector>
#include <list>

# define VECTOR 0
# define LIST 1
# define GREEN	"\e[32m"
# define RESET	"\e[0m"
# define BOLD	"\e[1m"

class Pmerge{
    public:
        Pmerge(int* array, size_t size, int container);
        Pmerge(const Pmerge& cpy);
        Pmerge& operator=(const Pmerge& src);
        ~Pmerge();

        void sort();
        void printSorted();
    private:
        Pmerge();
        int _container;
        // vector
        std::vector<int> _vsorted;
        std::vector<int> _vunsorted;
        
        bool checksorted();
        // list
        std::list<int> _lsorted;
        std::list<int> _lunsorted;
};