
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdlib>
# include <fstream>
# include <string>
# include <sstream>
# include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double>   _database;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void Execute(const std::string &filename);
        void LoadDatabase(const std::string &csv);
        void Process(const std::string &filename);

        double getExchangeRate(const std::string &date);
};

#endif