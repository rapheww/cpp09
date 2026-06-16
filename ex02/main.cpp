/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:23:56 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/16 23:25:53 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isInt(std::string str){
    if (!(str.find_first_not_of("0123456789") == std::string::npos))
        return false;
    if (str.size() > 11)
        return false;
    double tester = strtod(str.c_str(), NULL);
    if (tester > std::numeric_limits<int>::max() || tester < std::numeric_limits<int>::min())
        return false;
    return true;
}

bool isDup(std::string str, int* array, size_t arraySize){
    int value = atoi(str.c_str());
    for (size_t i = 0; i < arraySize; i++){
        if (value == array[i])
            return true;
    }
    return false;
}

bool isValid(std::string str, int* array, size_t size){
    if (!isInt(str)){
        delete[] array;
        throw(std::out_of_range("Error : only positive integer allowed"));
    }
    if (isDup(str, array, size)){
        delete[] array;
        throw(std::out_of_range("Error : " + str + " duplicate number"));
    }
    return true;
}

int *makeArray(char **av, size_t arraySize){
    int* array = new int[arraySize];
    size_t size = 0;
    int j = 0;
    
    for (size_t i = 1; i < arraySize; i++){
        if (isValid(av[i], array, size)){
            array[j] = atoi(av[i]);
            size++;
            j++;
        }
    }
    return array;
}

void tryPmerge(int* array, size_t arraySize){
    std::cout<<BOLD"Unsorted (size : "<<arraySize - 1<<") :" RESET;
    for (size_t i = 0; i < arraySize; i++)
        std::cout<<" [ "<<array[i]<<" ]";
    std::cout<<std::endl;
    Pmerge testvector(array, arraySize, VECTOR);
    Pmerge testlist(array, arraySize, LIST);
    testvector.sort();
    // testvector.printSorted();
    (void)testlist;
}

int main(int ac, char **av){
    size_t arraySize = ac - 1;
    
    if (ac < 2){
        std::cout<<"Program need at least 1 param"<<std::endl; return 0;
    }
    int* array = NULL;
    try{
        array = makeArray(av, ac);
        tryPmerge(array, arraySize);
    }
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    delete[] array;
}