#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>

int	main(void)
{
	Data test;
	uintptr_t value;
	Data* ptr;

	value = Serializer::serialize(&test);
	ptr = Serializer::deserialize(value);
	std::cout << "The value before: " << test.value << std::endl;
	std::cout << "Main ptr: " << &test << std::endl;
	std::cout << "Serialized: " << value << std::endl;
	std::cout << "Deserialized: " << ptr  << std::endl;
	std::cout << "The value after: " << ptr->value << std::endl;
}
