#pragma once

// Extract the rate, specified by the input file, from the database.csv
// If the data of the date doesn't exist, use the closest earlier date's data.
# include <iostream>	// cout
# include <fstream>		// file stream: reading and writing file stream
# include <sstream>		// string stream
# include <string>		// getline
# include <stdexcept>	// std::logic_error for logical mistakes, such as invalid arguments or precondition violations.
# include <map>


const std::string	database = "data.csv";

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);											// Default constructor
		BitcoinExchange(const BitcoinExchange& src);					// Copy constructor
		BitcoinExchange&	operator = (const BitcoinExchange& src);	// Assignment operator
		~BitcoinExchange(void);											// Destructor

		std::map<std::string, double>	getMapExchangeRate(void) const;	// Unused

		void	readDatabase(void);
		void	readInput(const std::string& file);

	private:
		std::map<std::string, double>	_exRate;						// Database stored in map format
		// Chose map because it automatically maintains keys in sorted order,
		// which makes it easy to find the closest exchange rate to a given date.

		bool	isAccessible(std::ifstream& input) const;
		bool	isValidLine(const std::string& line) const;
		bool	isValidDate(const std::string& date) const;
		bool	isLeapYear(int year) const;
		bool	isValidRate(const std::string& rateStr, double *rate) const;

		void	printBitcoin(const std::string& date, const std::string rateStr, double rate);
		double	getRate(std::string date);
};