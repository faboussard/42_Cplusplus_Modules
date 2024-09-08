#include "Serializer.hpp"
#include "data.hpp"

#include <iostream>

int main()
{
	Data* data;
	uintptr_t serializedData;
	Data* deserializedData;

	data = new Data;
	data->num = 42;
	data->str = "Hello World";
	data->c = 'c';

	std::cout << "Data             : " << data << std::endl;
	serializedData = Serializer::serialize(data);
	std::cout << "Serializer         : " << std::hex << serializedData << std::endl;
	std::cout << std::dec;
	deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized data: " << deserializedData << std::endl << deserializedData->num << std::endl << deserializedData->str << std::endl << deserializedData->c << std::endl;

	delete data;

	return 0;
}