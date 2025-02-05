#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	// std::cout << "[BitcoinExchange] Default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src): _exRate(src._exRate)
{
	// std::cout << "[BitcoinExchange] Copy constructor called." << std::endl;
	// *this = src;
}

BitcoinExchange&	BitcoinExchange::operator = (const BitcoinExchange& src)
{
	// std::cout << "[BitcoinExchange] Assignment constructor called." << std::endl;
	if (this != &src)
		_exRate = src._exRate;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "[BITCOINEXCHANGE] Destructor called." << std::endl;
}

std::map<std::string, double>	BitcoinExchange::getMapExchangeRate(void) const
{
	return _exRate;
}

void	BitcoinExchange::readDatabase(void)
{
	std::ifstream	file(database.c_str());		// string to char*
	if (!isAccessible(file, database))
		return ;

	std::string	line;
	std::getline(file, line);					//header skip
	while (std::getline(file, line))
	{
		std::istringstream	lineStream(line);
		std::string			date;
		std::string			rateStr;
		double				rate;

		std::getline(lineStream, date, ',');	// date
		std::getline(lineStream, rateStr);		// rate
		std::istringstream(rateStr) >> rate;	// string to double
		_exRate[date] = rate;					// set map[date] = rate
	}
	file.close();
}
// std::getline(input_stream, string_stored, delimiter):
// 	stops at the delimiter in the input_stream and returns a reference to it.
// 	Default delimiter is '\n'.

// bool	BitcoinExchange::isAccessible(std::ifstream& input, const std::string& fileName) const
// {
// 	if (!input.is_open())
// 	{
// 		std::cerr << "Error: Failed to open." << std::endl;
// 		return false;
// 	}

// 	// ate: Open a file for output and move the read/write control to the end of the file.
// 	// binary: Open in binary mode.
// 	std::ifstream					bigfile(fileName.c_str(), std::ifstream::ate | std::ifstream::binary);

// 	// tellg() tells the current pointer position in the text file.
// 	// 	But instead of put pointer, it tells the get pointer’s location.
// 	std::ifstream::pos_type			fileSize = bigFile.tellg();
// 	const std::ifstream::pos_type	maxSize = 10000000;		// 10 MG

// 	if (fileSize > maxSize)
// 	{
// 		std::cerr << "Error: " << fileName << " is too big." << std::endl;
// 		input.close();
// 		bigFile.close();
// 		return false;
// 	}
// 	bigFile.close();
// 	return true;
// }

void	BitcoinExchange::readInput(const std::string& file)
{
	std::ifstream	input(file.c_str());
	if (!input.is_open())
	{
		std::cerr << "Error: Failed to open." << std::endl;
		return ;
	}

	std::string		line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		if (!isValidLine(line))
			continue ;

		std::istringstream	lineStream(line);
		std::string			date;
		std::string			dateStr;
	}
}

void	BitcoinExchange::printBitcoin(const std::string& date, const std::string rateStr, double rate)
{

}

double	BitcoinExchange::getRate(std::string date)
{

}

bool	BitcoinExchange::isValidLine(const std::string& line) const
{

}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{

}

bool	BitcoinExchange::isLeapYear(int year) const
{

}

bool	BitcoinExchange::isValidRate(const std::string& rateStr, double rate) const
{

}
