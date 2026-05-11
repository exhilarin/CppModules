
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <string>
# include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;


    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void execute(const std::string &filename);
        void loadDatabase(const std::string& file);
        // void process(const std::string& file);
};

#endif