/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 22:44:27 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/25 22:07:07 by rchaumei         ###   ########.fr       */
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

void Pmerge::printSorted( int status){
    if (_container == VECTOR){
        if (status == UNSORTED){
            std::vector<int>::iterator it = _vunsorted.begin();
            std::cout<<BOLD "Vector Unsorted : " RESET;
            for(; it != _vunsorted.end(); it++)
            std::cout<<" [ "<<*it<<" ]";
            std::cout<<RESET<<std::endl;
        }
        else if (status == SORTED){
            std::vector<int>::iterator it = _vsorted.begin();
            std::cout<<GREEN BOLD "Vector Sorted : " RESET GREEN;
            for(; it != _vsorted.end(); it++)
            std::cout<<" [ "<<*it<<" ]";
            std::cout<<RESET<<std::endl;
            if (this->checksorted())
                std::cout<<GREEN "\n --> Vector was sort successfully\n\n" RESET;
            else
                std::cout<<RED "\n --> Error vector isn't correctly sort\n\n" RESET;
        }
    }
    else if (_container == LIST){
        if (status == UNSORTED){
            std::list<int>::iterator it = _lunsorted.begin();
            std::cout<<BOLD "List Unsorted : " RESET;
            for(; it != _lunsorted.end(); it++)
            std::cout<<" [ "<<*it<<" ]";
            std::cout<<RESET<<std::endl;
        }
        else if (status == SORTED){
            std::list<int>::iterator it = _lsorted.begin();
            std::cout<<GREEN BOLD "List Sorted : " RESET GREEN;
            for(; it != _lsorted.end(); it++)
            std::cout<<" [ "<<*it<<" ]";
            std::cout<<RESET<<std::endl;
            if (this->checksorted())
                std::cout<<GREEN "\n -->List was sort successfully\n\n" RESET;
            else
                std::cout<<RED "\n --> Error list isn't correctly sort\n\n" RESET;
        }
    }
}


bool Pmerge::checksorted(){
    if (_container == VECTOR){
        std::vector<int>::iterator it = _vsorted.begin();
        for (; it != _vsorted.end(); it++){
            std::vector<int>::const_iterator next = it + 1;
            if (next != _vsorted.end() && *it > *next)
                return false; 
        }
    }
    else if (_container == LIST){
        std::list<int>::iterator it = _lsorted.begin();
        for (; it != _lsorted.end(); it++){
            std::list<int>::const_iterator next = it;
            next++;
            if (next != _lsorted.end() && *it > *next)
                return false; 
        }
    }
    return true;
}

size_t Pmerge::insertion(std::vector<int>& sorted, int target, size_t low, size_t high){
    while (low < high){
        size_t mid = low + (high - low) / 2;
        if (sorted[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

std::vector<int> Pmerge::sortVector(std::vector<int>& container){
    int lastodd = -1;
    bool isodd = false;
    
    if (container.size() <= 1)
        return container;
    if (container.size() % 2 != 0){
        lastodd = container.back();
        isodd = true;
        container.pop_back();
    }
    std::vector<std::pair<int, int> > pairs;
    
    for (size_t i = 0; i < container.size(); i += 2){
        if(container[i] > container[i + 1])
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        else
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
    }
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].first);
    std::vector<int> sorted = sortVector(winners);
    int firstw = sorted[0];
    size_t firstlIdx = 0;
    
    for (size_t i = 0; i < pairs.size(); i++){
        if (pairs[i].first == firstw){
            firstlIdx = i;
            sorted.insert(sorted.begin(), pairs[i].second);
            break;
        }   
    }

    std::vector<size_t> jacob;
    
    //idx a define
    jacob.push_back(1);
    jacob.push_back(3);
    while(jacob.back() < pairs.size()){
        jacob.push_back(jacob[jacob.size() - 1] +  2 * jacob[jacob.size() - 2]);
    }

    std::vector<size_t> jacobIdx;
    std::vector<bool> visited(pairs.size(), false);
        visited[firstlIdx] = true;
    
    for (size_t i = 0; i < jacob.size(); i++){
        size_t target = jacob[i];
        if (target >= pairs.size())
            target =pairs.size() - 1;
        for (long long j = target; j>= 0; j--){
            if (!visited[j]){
                jacobIdx.push_back(j);
                visited[j] = true;
            }
        }
    }
    
    for (size_t i = 0; i < jacobIdx.size(); i++){
        size_t idx = jacobIdx[i];
        int loser = pairs[idx].second;
        
        size_t pos = insertion(sorted, loser, 0, sorted.size());
        sorted.insert(sorted.begin() + pos, loser);
    }
    if (isodd){
        size_t pos = insertion(sorted, lastodd, 0, sorted.size());
        sorted.insert(sorted.begin() + pos, lastodd);
    }
    return sorted;
}


//LIST SORTING

std::list<int>::iterator Pmerge::insertion(int target, std::list<int>::iterator low, std::list<int>::iterator high){
    while (low != high) {
        // Calcule le nombre d'éléments entre low et high
        size_t count = std::distance(low, high);
        size_t mid_dist = count / 2;
        
        // On avance un itérateur temporaire jusqu'au milieu
        std::list<int>::iterator mid = next(low, mid_dist);
        
        if (*mid < target) {
            low = next(mid, 1); // On restreint à la partie droite
        } else {
            high = mid;  // On restreint à la partie gauche
        }
    }
    return low; // Retourne l'itérateur où insérer l'élément
} 

std::list<int> Pmerge::sortList(std::list<int>& container){
    int lastodd = -1;
    bool isodd = false;
    
    if (container.size() <= 1)
        return container;
    if (container.size() % 2 != 0){
        lastodd = container.back();
        isodd = true;
        container.pop_back();
    }
    std::list<std::pair<int, int> > pairs;
    
   for (std::list<int>::iterator it = container.begin(); it != container.end(); ) {
        int first = *it;
        it++;
        int second = *it;
        it++; // On avance l'itérateur manuellement, sans effet de bord indésirable
        
        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }
    std::list<int> winners;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        winners.push_back(it->first);
    std::list<int> sorted = sortList(winners);
    if (sorted.empty()) return sorted;
    std::list<int>::iterator itSorted = sorted.begin();
    int firstw = *itSorted;
    std::list<std::pair<int, int> >::iterator firstlIdx = pairs.end();
    
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        if (it->first == firstw){
            firstlIdx = it;
            sorted.insert(sorted.begin(), it->second);
            break;
        }   
    }

    std::list<size_t> jacob;
    
    //idx a define
    jacob.push_back(1);
    jacob.push_back(3);
    while(jacob.back() < pairs.size()){
        long last = jacob.back();
    
        jacob.pop_back();
        long prevToLast = jacob.back();
    
        jacob.push_back(last);
        jacob.push_back(last + 2 * prevToLast);
    }

    std::list<size_t> jacobIdx;
    std::list<bool> visited(pairs.size(), false);
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        if (it->first == firstw){
            size_t dist = std::distance(pairs.begin(), it);
            std::list<bool>::iterator tmp = next(visited.begin(), dist);
            *tmp = true;
            break;
        }
    }
    
    for (std::list<size_t>::iterator it = jacob.begin(); it != jacob.end(); it++){
        size_t target = *it;
        if (target >= pairs.size())
            target =pairs.size() - 1;
        for (long long j = target; j>= 0; j--){
            std::list<bool>::iterator check = next(visited.begin(), j);
            if (*check == false){
                jacobIdx.push_back(j);
                *check = true;
            }
        }
    }
    
   for (std::list<size_t>::iterator it = jacobIdx.begin(); it != jacobIdx.end(); it++){
        size_t idx = *it;
        std::list<std::pair<int, int> >::iterator itPairs = next(pairs.begin(), idx);
        int loser = itPairs->second;
        
        // On donne sorted.begin() et sorted.end() à notre fonction
        std::list<int>::iterator pos = insertion(loser, sorted.begin(), sorted.end());
        // 'pos' est déjà l'itérateur exact où insérer !
        sorted.insert(pos, loser);
    }
    
    // CORRECTION 4 : Gestion de l'élément impair avec itérateurs
    if (isodd){
        std::list<int>::iterator pos = insertion(lastodd, sorted.begin(), sorted.end());
        sorted.insert(pos, lastodd);
    }
    return sorted;
}


std::clock_t Pmerge::sort(){
    if(_container == VECTOR){
        std::clock_t start = std::clock();
        this->_vsorted = sortVector(_vunsorted);
        std::clock_t end = std::clock() - start;
        return end;
    }
    else if (_container == LIST){
        std::clock_t start = std::clock();
        _lsorted = sortList(_lunsorted);
        std::clock_t end = std::clock() - start;
        return end;
    }
    return 0;
}
