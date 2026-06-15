/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:19:33 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/12 19:14:56 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    parseData();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy){*this = cpy;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src){
    if (this != &src){
        _data = src._data;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

const char* BitcoinExchange::BadInputDate::what() const throw(){
    return "Error: bad input => ";
}

const char* BitcoinExchange::BadInputValue::what() const throw(){
    return "Error : Bad input value needed";
}

const char* BitcoinExchange::NegativeValue::what() const throw(){
    return "Error: not a positive number.";
}

const char* BitcoinExchange::Overflow::what() const throw(){
    return "Error: too large a number.";
}

const char* BitcoinExchange::BadValue::what() const throw(){
    return "Error : Bad value -> min 1 / max 1000";
}

size_t BitcoinExchange::getDataSize(){
    return _data.size();
}

double convertToDouble(std::string amount){
    double converted;
    char *end;
    if (amount.empty())
        return 0;
    converted = strtod(amount.c_str(), &end);
    return converted;
}

bool isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

void BitcoinExchange::checkDate(std::string date, char format){
    std::string year;
    std::string month;
    std::string day;
    int i = 0;
    
    if (date.size() != 10)
            throw(BadInputDate());
    for (; i < 4; i++){
        if (!isdigit(date[i]))
            throw(BadInputDate());
        year += date[i];
    }
    if (date[i] != format)
        throw(BadInputDate());
    i++;
    for (; i < 7; i++){
        if (!isdigit(date[i]))
            throw(BadInputDate());
        month += date[i];
    }
    if (date[i] != format)
        throw(BadInputDate());
    i++;
    for (; i < 10; i++){
        if (!isdigit(date[i]))
            throw(BadInputDate());
        day += date[i];
    }

    int intYear = atoi(year.c_str());
    int intMonth = atoi(month.c_str());
    int intDay = atoi(day.c_str());
    
    if (intYear < MINYEAR)
        throw(BadInputDate());
    if (intMonth < 1 || intMonth > 12)
        throw(BadInputDate());
    if (intDay < 1 || intDay > 31)
        throw(BadInputDate());
    if (intMonth == 2){
        if (isLeap(intYear)){
            if(intDay > 29)
                throw(BadInputDate());
        }
        else
            if (intDay > 28)
                throw(BadInputDate());
    }
    if (intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11)
        if (intDay > 30)
            throw(BadInputDate());
}

void BitcoinExchange::checkValue(std::string value){
    float fvalue;
    char* end;
    if (value.find('.') != std::string::npos && (value.find('.') > 4 || value.find('.') == value.size() - 1))
            throw(BadValue());
    fvalue = std::strtof(value.c_str(), &end);
    if (end == value.c_str())
        throw(BadValue());
    if (*end != '\0')
        throw(BadValue());
    if (fvalue < 1)
        throw(NegativeValue());
    if (fvalue > 1000)
        throw(Overflow());
}

void BitcoinExchange::exchange(std::string* line){
    std::multimap<std::string, double>::iterator itDate = _data.lower_bound(line[DATE]);
    
    try{
        checkDate(line[DATE], '-');
        if (line[VALUE] == "")
            throw(BadInputValue());
        checkValue(line[VALUE]);
        if (itDate == _data.end())
            itDate--;
        if (itDate != _data.begin() && itDate->first != line[DATE])
            itDate--;
        std::cout<<line[DATE]<<" => "<<line[VALUE]<<" = "<<std::strtof(line[VALUE].c_str(), NULL) * itDate->second<<std::endl;
    }
    catch(BadInputDate& e){
        std::cout<<e.what()<<" "<<line[DATE]<<std::endl;
    }
    catch(BadInputValue& e){
        std::cout<<e.what()<<std::endl;
    }
    catch(BadValue& e){
        std::cout<<e.what()<<std::endl;
    }
    catch(Overflow& e){
        std::cout<<e.what()<<std::endl;
    }
    catch(NegativeValue& e){
        std::cout<<e.what()<<std::endl;
    }
    
}

void BitcoinExchange::parseData(){
    std::string line;
    std::string path = "data.csv";
    std::ifstream infile(path.c_str());
    std::multimap<std::string, double> res;
    
    if (!infile.is_open()){
        std::cout<<"Invalid database file, make sure the file exists and you have the permissions\n"; ;
    }
    while(getline(infile, line)){
        if (!line.c_str() || line != "date,exchange_rate"){
            size_t delimiter = line.find(",");
            std::string date = line.substr(0, delimiter);
            double amount = 0.0f;
            if (delimiter == std::string::npos)
                amount = convertToDouble("");
            else
                amount = convertToDouble(line.substr(delimiter + 1));
            res.insert(std::pair<std::string, double>(date, amount));
        }
    }
    infile.close();
    _data = res;
}