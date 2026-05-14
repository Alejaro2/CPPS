#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

bool ScalarConverter::isChar(const std::string &literal) {
  if (literal.length() == 1 && !std::isdigit(literal[0]) &&
      std::isprint(literal[0]))
    return true;
  return false;
}

bool ScalarConverter::isInt(const std::string &literal) {
  size_t i = 0;
  if (literal.empty())
    return false;

  if (literal[i] == '+' || literal[i] == '-')
    i++;

  if (i == literal.length())
    return false;

  while (i < literal.length()) {
    if (!std::isdigit(literal[i])) {
      return false;
    }
    i++;
  }
  long var = std::strtol(literal.c_str(), NULL, 10);
  if (var > INT_MAX || var < INT_MIN) {
    return false;
  }
  return true;
}

bool ScalarConverter::isFloat(const std::string &literal) {
  size_t i = 0;
  if (literal.empty())
    return false;

  if (literal[i] == '+' || literal[i] == '-')
    i++;

  if (i == literal.length())
    return false;

  if (literal[literal.length() - 1] != 'f') {
    return false;
  }
  int dot_count = 0;
  while (i < literal.length() - 1) {
    if (!std::isdigit(literal[i]) && literal[i] != '.')
      return false;

    if (literal[i] == '.')
      dot_count++;
    i++;
  }
  if (dot_count != 1)
    return false;

  return true;
}

bool ScalarConverter::isDouble(const std::string &literal) {
  size_t i = 0;
  if (literal.empty())
    return false;

  if (literal[i] == '+' || literal[i] == '-')
    i++;

  if (i == literal.length())
    return false;

  int dot_count = 0;
  while (i < literal.length()) {
    if (!std::isdigit(literal[i]) && literal[i] != '.')
      return false;

    if (literal[i] == '.')
      dot_count++;
    i++;
  }
  if (dot_count > 1)
    return false;

  return true;
}

ScalarConverter::Type ScalarConverter::detectType(const std::string &literal) {
  if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
      literal == "-inf" || literal == "+inff" || literal == "-inff" ||
      literal == "inf" || literal == "inff")
    return PSEUDO;

  if (isChar(literal))
    return CHAR;

  if (isInt(literal))
    return INT;

  if (isFloat(literal))
    return FLOAT;

  if (isDouble(literal))
    return DOUBLE;

  return INVALID;
}

void ScalarConverter::convert(const std::string &literal) {
  Type type = detectType(literal);

  switch (type) {
  case INT:
    printInt(literal);
    break;
  case FLOAT:
    printFloat(literal);
    break;
  case DOUBLE:
    printDouble(literal);
    break;
  case CHAR:
    printChar(literal);
    break;
  case PSEUDO:
    printPseudo(literal);
    break;
  case INVALID:
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    break;
  }
}

void ScalarConverter::printInt(const std::string &literal) {
  int i = std::atoi(literal.c_str());
  if (i >= 0 && i <= 127) {
    if (std::isprint(i))
      std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(i) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFloat(const std::string &literal) {
  float f = std::strtof(literal.c_str(), NULL);
  if (f >= 0 && f <= 127) {
    if (std::isprint(static_cast<int>(f)))
      std::cout << "char: '" << (static_cast<char>(f)) << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  if (f >= INT_MIN && f <= INT_MAX)
    std::cout << "int: " << (static_cast<int>(f)) << std::endl;
  else
    std::cout << "int: impossible" << std::endl;
  if (f == std::floor(f)) {
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
  } else {
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
  }
}

void ScalarConverter::printDouble(const std::string &literal) {
  double d = std::strtod(literal.c_str(), NULL);
  if (d >= 0 && d <= 127) {
    if (std::isprint(static_cast<int>(d)))
      std::cout << "char: '" << (static_cast<char>(d)) << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  if (d >= INT_MIN && d <= INT_MAX)
    std::cout << "int: " << (static_cast<int>(d)) << std::endl;
  else
    std::cout << "int: impossible" << std::endl;
  if (d == std::floor(d)) {
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
  } else {
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
  } 
}

void ScalarConverter::printChar(const std::string &literal) {
  char c = literal[0];
  if (std::isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << (static_cast<int>(c)) << std::endl;
  std::cout << "float: " << (static_cast<float>(c)) << ".0f" << std::endl;
  std::cout << "double: " << (static_cast<double>(c)) << ".0" << std::endl;
}

void ScalarConverter::printPseudo(const std::string &literal) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (literal[literal.length() - 1] == 'f' && literal != "+inf" &&
      literal != "-inf") {
    std::cout << "float: " << literal << std::endl;
    std::cout << "double: " << literal.substr(0, literal.length() - 1)
              << std::endl;
  } else {
    std::cout << "float: " << literal << "f" << std::endl;
    std::cout << "double: " << literal << std::endl;
  }
}
