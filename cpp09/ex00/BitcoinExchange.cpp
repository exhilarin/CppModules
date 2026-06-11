
#include "BitcoinExchange.hpp"

void BitcoinExchange::loadDatabase(const std::string& file)
{
    std::ifstream csv(file.c_str());
    if (!csv.is_open())
    {
        std::cerr << "Error: File is not open" << std::endl;
        std::exit(1);
    }
    size_t comma_pos;
    std::string line;
    std::string date;   
    std::string rate_str;
    float rate;
    std::getline(csv, line);
    while (std::getline(csv, line))
    {
        comma_pos = line.find(",");
        if(comma_pos != std::string::npos)
        {
            date = line.substr(0, comma_pos);
            rate_str = line.substr(comma_pos + 1);
            std::stringstream ss(rate_str);
            ss >> rate;
            if (ss.fail())
            {
                std::cerr << "Error: Failed to casting (String -> Float)" << std::endl;
                std::exit(2);
            }
            _database[date] = rate;
        }
    }
    csv.close();
}

void BitcoinExchange::execute(const std::string &filename)
{
    loadDatabase("data.csv");
    std::cout << _database;
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