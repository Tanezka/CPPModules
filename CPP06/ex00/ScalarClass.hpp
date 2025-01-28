#ifndef SCALARCLASS_H
# define SCALARCLASS_H

class ScalarConverter
{
public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &tmp);
        ScalarConverter &operator=(const ScalarConverter &source);
        static void convert(char* tmp);
        static void convert_int(double tmp);
        static void convert_float(double tmp);
        static void convert_char(double tmp);
};
#endif
