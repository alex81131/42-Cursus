#pragma once

# include <iostream>	// cout
# include <ifstream>	// ifstream: input file stream
# include <sstream>		// string stream
# include <string>		// getline
# include <map>


const std::string	database_path = "data.csv"

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);											// Default constructor
		BitcoinExchange(const std::string& name);						// Parameterized Constructor
		BitcoinExchange(const BitcoinExchange& src);					// Copy constructor
		BitcoinExchange&	operator = (const BitcoinExchange& src);	// Assignment operator
		~BitcoinExchange(void);											// Destructor

		std::map<std::string, double>	getMapExchangeRate(void) const;

		void	readDataCSV(void);
		void	readDataTXT(const std::string& fileName);
		void	printBitcoin(const std::string& date, const std::string rateStr, double rate);
		double	getRate(std::string date);

		bool	isAccessible(std::ifstream& input, const std::string& fileName) const;
		bool	isValidLine(const std::string& line) const;
		bool	isValidDate(const std::string& date) const;
		bool	isLeapYear(int year) const;
		bool	isValidRate(const std::string& rateStr, double rate) const;

	private:
		std::map<std::string, double>	_mapExchangeRate;
};