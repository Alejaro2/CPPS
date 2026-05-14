#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <string>


class ScalarConverter {
	private:

		enum Type { 
			CHAR, 
			INT, 
			FLOAT, 
			DOUBLE, 
			PSEUDO, 
			INVALID 
		};
		ScalarConverter();
		ScalarConverter(ScalarConverter const & other);
		ScalarConverter & operator=(ScalarConverter const & other);
		~ScalarConverter();
	

		static Type detectType(const std::string& literal);
		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		static void printInt(const std::string& literal);
		static void printFloat(const std::string& literal);
		static void printDouble(const std::string& literal);
		static void printChar(const std::string& literal);
		static void printPseudo(const std::string& literal);
		

	public:
		static void convert(std::string const & literal);
};

#endif