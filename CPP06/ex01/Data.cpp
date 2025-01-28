#include "Data.hpp"

Data::Data(): value(42)
{

}

Data::~Data()
{

}
Data::Data(const Data &other)
{
	*this = other;
}

Data &Data::operator=(const Data &other)
{
	this->value = other.value;
	return *this;
}
