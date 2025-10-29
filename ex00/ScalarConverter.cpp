#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
    (void)other; 
    return *this; 
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) {
    size_t i = 0;
    
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    
	if (literal[i] == '+' || literal[i] == '-')
		if (literal.length() == 1)
			return false;
    return literal.length() > 0;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    
    size_t i = 0;
    bool hasDecimal = false;
    
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    
    for (; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
		else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    
    return hasDecimal;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    
    size_t i = 0;
    bool hasDecimal = false;
    
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    
    return hasDecimal;
}

void ScalarConverter::convertFromChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int n) {
    if (n >= 32 && n <= 126)
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    else if (n >= 0 && n <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float f) {
    if (f >= 32 && f <= 126 && !std::isnan(f) && !std::isinf(f))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else if (f >= 0 && f <= 127 && !std::isnan(f) && !std::isinf(f))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max() 
        && !std::isnan(f) && !std::isinf(f))
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f)) {
        if (f > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    
    // Handle special double values
    if (std::isnan(f))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(f)) {
        if (f > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else if (f == static_cast<int>(f))
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromDouble(double d) {
    if (d >= 32 && d <= 126 && !std::isnan(d) && !std::isinf(d))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= 0 && d <= 127 && !std::isnan(d) && !std::isinf(d))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() 
        && !std::isnan(d) && !std::isinf(d))
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (std::isnan(d))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(d)) {
        if (d > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) {
        if (d == static_cast<int>(d))
            std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    } else {
        std::cout << "float: impossible" << std::endl;
    }
    
    // Handle special double values
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d)) {
        if (d > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        double d;
        if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else
            d = -std::numeric_limits<double>::infinity();
        
        convertFromDouble(d);
        return;
    }
    
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        float f;
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else
            f = -std::numeric_limits<float>::infinity();
        
        convertFromFloat(f);
        return;
    }
    if (isChar(literal)) {
        convertFromChar(literal[0]);
    } else if (isInt(literal)) {
        int value = std::atoi(literal.c_str());
        convertFromInt(value);
    } else if (isFloat(literal)) {
        float value = std::atof(literal.c_str());
        convertFromFloat(value);
    } else if (isDouble(literal)) {
        double value = std::atof(literal.c_str());
        convertFromDouble(value);
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}