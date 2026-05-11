#include "BitcoinExchange.hpp"

void BitcoinExchange::loadDatabase(const std::string& file)
{
    std::ifstream csv;
}

void BitcoinExchange::execute(const std::string &filename)
{
    loadDatabase("data.csv");
    // process(filename);
}

/*---------------Constructure--------------*/
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}