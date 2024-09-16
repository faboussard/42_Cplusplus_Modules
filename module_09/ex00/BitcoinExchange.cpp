#include "BitcoinExchange.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

BitcoinExchange::BitcoinExchange(const std::string &inputFile,
                                 const std::string &dataFile)
    : _inputFile(inputFile), _dataFile(dataFile) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
    : _inputFile(rhs._inputFile), _dataFile(rhs._dataFile),
      _databaseMap(rhs._databaseMap), _inputDataMap(rhs._inputDataMap) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  if (this != &rhs) {
    _inputFile = rhs._inputFile;
    _dataFile = rhs._dataFile;
    _databaseMap = rhs._databaseMap;
    _inputDataMap = rhs._inputDataMap;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/*============================================================================*/
/*       getter */
/*============================================================================*/

BitcoinExchange::map &BitcoinExchange::getDatabaseMap() { return _databaseMap; }

BitcoinExchange::map &BitcoinExchange::getInputbaseMap() {
  return _inputDataMap;
}

std::string &BitcoinExchange::getInputFile() { return _inputFile; }

std::string &BitcoinExchange::getDataFile() { return _dataFile; }

/*============================================================================*/
/*      Public  member functions */
/*============================================================================*/

void BitcoinExchange::open_file(const char *filename, std::ifstream &infile) {
  infile.open(filename);
  if (!infile.is_open()) {
    std::cerr << BAD_OPENING_ERROR_MESSAGE << filename << std::endl;
    exit(EXIT_FAILURE);
  }
}

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

bool BitcoinExchange::checkDate(std::string const &date) {
  if (date.empty()) {
    std::cerr << "Error: Bad input - empty date => " << date << std::endl;
    return false;
  }

  if (date > getTodayDate()) {
    std::cerr << "Error: Bad input - date is upper than today ! Date: " << date
              << std::endl;
    return false;
  }

  std::istringstream iss(date);
  int year, month, day;
  char delimiter;

  if (!(iss >> year >> delimiter >> month >> delimiter >> day)) {
    std::cerr << "Error: Bad input - invalidate format date. Date: " << date
              << std::endl;
    return false;
  }

  if (delimiter != DELIMITER_DATE) {
    std::cerr << "Error: Bad input - invalidate delimiter. Delimiter should be "
              << DELIMITER_DATE << " and is " << delimiter << std::endl;
    return false;
  }

  if (month < 1 || month > 12) {
    std::cerr << "Error: Bad input - invalidate month. Date:  " << date
              << std::endl;
    return false;
  }
  if (day < 1 || day > 31) {
    std::cerr << "Error: Bad input - invalidate day. Date:  " << date
              << std::endl;
    return false;
  }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
    std::cerr << "Error: Bad input - invalidate day. Date: " << date
              << std::endl;
    return false;
  }

  if (month == 2) {
    bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (day > (leapYear ? 29 : 28)) {
      std::cerr << "Error: Bad input for February(leap year or not). Date: "
                << date << std::endl;
      return false;
    }
  }
  return true;
}

bool BitcoinExchange::checkAmount(std::string const &amount) {
  char *end;
  float num;
  errno = 0;

  double tmp = std::strtod(amount.c_str(), &end);
  if (amount.empty()) {
    std::cerr << "Error: Bad input - amount is empty. Amount: " << amount
              << std::endl;
    return (false);
  }
  if (errno == EINVAL) {
    std::cerr << "Error: Bad input - amount is not a valid number. Amount: "
              << amount << std::endl;
    return (false);
  }
  num = static_cast<float>(tmp);
  if (num < 0.0) {
    std::cerr << "Error: Bad input - Not a positive number. Amount: " << amount
              << std::endl;
    return (false);
  }
  if (num >= INT8_MAX) {
    std::cerr << "Error: Bad input - Amount exceeds maximum value. Amount: "
              << amount << std::endl;
    return (false);
  }
  return (true);
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &key,
                                float &value, bool isInputFile) {
  std::istringstream iss(line);
  std::getline(iss, key, isInputFile ? DASH_SEPARATOR : COMA_SEPARATOR);
  std::string valueStr;
  std::getline(iss, valueStr);

  if (isInputFile) {
    if (!checkDate(key) || !checkAmount(valueStr)) {
      return false;
    }
  }
  try {
    value = std::stof(valueStr);
  } catch (const std::invalid_argument &) {
    return false;
  }
  return true;
}

void BitcoinExchange::processFile(std::ifstream &infile, map myMap,
                                  std::string &fileName) {
  std::string line;
  std::string key;
  float value;
  int linenumber = 2;

  std::getline(infile, line);
  while (std::getline(infile, line)) {
    if (parseLine(line, key, value, fileName == _inputFile)) {
      myMap[key] = value;
    } else {
      std::cerr << "File : " << fileName << " Bad input on line " << linenumber
                << std::endl
                << std::endl;
    }
    linenumber++;
  }
}

bool BitcoinExchange::extractFile(std::string &fileName, map myMap) {
  try {
    std::ifstream data_infile;
    open_file(fileName.c_str(), data_infile);
    processFile(data_infile, myMap, fileName);
    data_infile.close();
    return true;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  }
}

float BitcoinExchange::calculateRate(map::iterator it, float price) {
  map::iterator rate_it = _databaseMap.lower_bound(it->first);

  if (rate_it == _databaseMap.end() || rate_it->first != it->first) {
    if (rate_it != _databaseMap.begin()) {
      --rate_it;
    } else {
      return 0.0f;
    }
  }
  return price * rate_it->second;
}

/*============================================================================*/
/*       Public member functions                                             */
/*============================================================================*/

void BitcoinExchange::print_database(const map &database) const {
  for (map::const_iterator it = database.begin(); it != database.end(); ++it) {
    std::cout << "Date: " << it->first << std::endl;
  }
}

void BitcoinExchange::findRate() {
  if (!extractFile(_inputFile, _inputDataMap) ||
      !extractFile(_dataFile, _inputDataMap)) {
    std::cerr << "Error: could not extract input or data file." << std::endl;
    return;
  }

  for (map::iterator it = _inputDataMap.begin(); it != _inputDataMap.end();
       ++it) {
    float price = it->second;
    float rate = calculateRate(it, price);

    //		if (rate = INTROUVABLE)
    //			std::cerr << "no echange rate found for this date" <<
    // std::endl;
    if (rate != 0.0f) {
      std::cout << it->first << " => " << price << " = " << rate << std::endl;
    } else {
      std::cout << it->first << " => " << price << " = " << price << std::endl;
    }
  }
}

/*============================================================================*/
/*       Non member functions                                             */
/*============================================================================*/

std::string getTodayDate() {
  std::time_t now = std::time(0);
  std::tm *now_tm = std::localtime(&now);
  std::ostringstream oss;
  oss << (now_tm->tm_year + 1900) << "-" << (now_tm->tm_mon + 1) << "-"
      << now_tm->tm_mday;

  return oss.str();
}