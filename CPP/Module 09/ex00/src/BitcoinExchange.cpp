#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src): _exRate(src._exRate)
{
	// std::cout << "[BitcoinExchange] Copy constructor called." << std::endl;
	// *this = src;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src)
{
	// std::cout << "[BitcoinExchange] Assignment constructor called." << std::endl;
	if (this != &src)
		_exRate = src._exRate;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

std::map<std::string, double>	BitcoinExchange::getMapExchangeRate(void) const
{
	return _exRate;
}

void	BitcoinExchange::readDatabase(void)
{
	std::ifstream	file(database.c_str());		// string to char*
	if (!isAccessible(file))
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

bool	BitcoinExchange::isAccessible(std::ifstream& input) const
{
	if (!input.is_open())
	{
		std::cerr << "Error: Failed to open." << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::readInput(const std::string& file)
{
	std::ifstream	input(file.c_str());
	if (!isAccessible(input))
		return ;

	std::string		line;
	std::getline(input, line);					//header skip
	while (std::getline(input, line))
	{
		if (!isValidLine(line))
			continue ;

		std::istringstream	lineStream(line);
		std::string			date;
		std::string			rateStr;
		double				rate;

		std::getline(lineStream, date, '|');	// date
		std::getline(lineStream, rateStr);		// rate
		if (!isValidDate(date))
			continue;
		if (!isValidRate(rateStr, &rate))
			continue;
		printBitcoin(date, rateStr, rate);
	}
	input.close();
}

bool	BitcoinExchange::isValidLine(const std::string& line) const
{
	try
	{
		if (line.empty())
			return false;
		if (line.find('|') == std::string::npos)
			throw std::logic_error("Bad input (rate unavailable) => " + line);
	}
	catch (std::logic_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
	return true;
}
// std::logic_error: 是在程式執行前能夠檢查出來的錯誤，通常代表程式邏輯本身的錯誤。
// std::runtime_error: 是在程式執行期間發生的錯誤，無法在編譯時預知的錯誤。
// 當檢查到用戶輸入不正確（如日期格式錯誤或非法數字）時，使用 std::logic_error 更合適。

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	try
	{
		if (date.size() != 11)								// date + space = 11
			throw std::logic_error("Bad input (date format) => " + date);
		for (int i = 0; i < 10; i++)
		{
			if (i == 4 || i == 7) {
				if (date[i] != '-')
					throw std::logic_error("Bad input (date format) => " + date);
			}
			else {
				if (!std::isdigit(date[i]))
					throw std::logic_error("Bad input (date format) => " + date);
			}
		}

		int	year, month, day;
		std::istringstream	issYear(date.substr(0, 4));		// .substr(start_pos, length)
		std::istringstream	issMonth(date.substr(5, 2));
		std::istringstream	issDay(date.substr(8, 2));
		issYear >> year;
		issMonth >> month;
		issDay >> day;

		int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (isLeapYear(year))
			daysInMonth[2] = 29;
		if (day > daysInMonth[month])
			throw std::logic_error("Bad input (impossible date) => " + date);
	}
	catch(std::logic_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	BitcoinExchange::isValidRate(const std::string& rateStr, double *rate) const
{
	std::istringstream	iss(rateStr);

	try
	{
		if (!(iss >> *rate))
			throw std::logic_error("Not a number.");
		if (*rate < 0)
			throw std::logic_error("Not a positive number.");
		if (*rate > 1000)
			throw std::logic_error("Number too big.");
	}
	catch (std::logic_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::printBitcoin(const std::string& date, const std::string rateStr, double rate)
{
	double	dbRate = getRate(date);

	if (dbRate < 0)
		return ;
	dbRate *= rate;
	std::cout << date << "=>" << rateStr << " = " << dbRate << std::endl;
}
// date and rateStr have an innate space relatively at the end and at the beginning

double	BitcoinExchange::getRate(std::string date)
{
	// upper_bound points to the first element greater than the given "date"
	std::map<std::string, double>::const_iterator	it = _exRate.upper_bound(date);
	if (it == _exRate.begin())
	{
		std::cout << "Error: No available rate for the given date or earlier." << std::endl;
		return -1.0;
	}
	--it;
	return it->second;
}
// Get the next date and then step back to make sure we get the  closest earlier date's data,
// skipping the if-condition loops