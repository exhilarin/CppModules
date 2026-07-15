
#include "BitcoinExchange.hpp"

double BitcoinExchange::getExchangeRate(const std::string &date)
{
    std::map<std::string, double>::iterator it;

    it = _database.lower_bound(date);

    if (it == _database.end())
    {
        it--;
        return it->second;
    }
    if (it->first == date)
        return it->second;
    if (it == _database.begin())
        throw std::runtime_error("No exchange rate available.");
    it--;

    return it->second;
}

static bool isValidValue(const std::string &value)
{
    double rate;
    char c;

    std::stringstream ss(value);
    ss >> rate;
    if (ss.fail())
        return false;

    if (ss >> c)
        return false;

    if (rate < 0 || rate > 1000)
        return false;

    return true;
}

static bool isValidDate(const std::string &date)
{
    if (date.length() != 10)
        return false;
    
    for (int i = 0; date[i]; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else
            if (!std::isdigit(date[i]))
                return false;
    }

    int year, month, day;

    std::stringstream(date.substr(0, 4)) >> year;
    std::stringstream(date.substr(5, 2)) >> month;
    std::stringstream(date.substr(8, 2)) >> day;
    
    if (year < 2009 || (month < 1 || month > 12) || day < 1)
        return false;

    int daysInMonth;
    bool leapYear = false;

    if (month == 1 || month == 3 || month == 5 ||
        month == 7 || month == 8 || month == 10 ||
        month == 12)
    {
        daysInMonth = 31;
    }
    else if (month == 4 || month == 6 ||
             month == 9 || month == 11)
    {
        daysInMonth = 30;
    }
    else // Leap Year
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            leapYear = true;

        if (leapYear)
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    if (day > daysInMonth)
        return false;

    return true;
}

static bool parse(std::string &line, std::string &date, std::string &value)
{
    size_t pos = line.find('|');
    if (pos == std::string::npos)
        return false;
    
    date = line.substr(0, pos);
    value = line.substr(pos + 1);

    while (!date.empty() && std::isspace(date[date.size() - 1]))
        date.erase(date.size() - 1);

    while (!value.empty() && std::isspace(value[0]))
        value.erase(0, 1);
    
    if (date.empty() || value.empty())
        return false;

    return true;
}

/*-------------- Main Functions ----------------*/

void BitcoinExchange::Process(const std::string &filename)
{
    std::string date, value;
    std::ifstream input_file(filename.c_str());
    if (!input_file.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return ;
    }
    std::string line;
    std::getline(input_file, line);
    while (std::getline(input_file, line)) // ----- Main Loop -----
    {
        if (!parse(line, date, value)) // Parse
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidDate(date)) // Date Check
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidValue(value)) // Value Check
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        double amount;
        std::stringstream(value) >> amount;
        double rate = getExchangeRate(date);
        double result = amount * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    input_file.close();
}

void BitcoinExchange::LoadDatabase(const std::string &csv)
{
    std::ifstream csv_file(csv.c_str());
    if (!csv_file.is_open())
    {
        std::cerr << "Error: could not open csv file." << std::endl;
        return ;
    }
    size_t pos;
    std::string line;
    std::getline(csv_file, line);
    while (std::getline(csv_file, line))
    {
        pos = 0;
        if ((pos = line.find(',', pos)) != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            std::string rateStr = line.substr(pos + 1);
            
            double rate;
            std::stringstream ss(rateStr);
            ss >> rate;
            if (ss.fail())
            {
                std::cerr << "Invalid exchange rate." << std::endl;
                return;
            }

            _database[date] = rate;
        }
    }
    csv_file.close();
}

void BitcoinExchange::Execute(const std::string &filename)
{
    LoadDatabase("data.csv");
    Process(filename);
}

/*--------------Orthodox----------------*/
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}