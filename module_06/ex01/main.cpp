#include "Serializer.hpp"
#include "data.hpp"

#include <iostream>

// Serialized data ?

//pk ce resultat ? pk serializer na pas la meme adresse ?
//❯ ./Serializer
//		Data             : 0x5d263ab55eb0
//Serializer         : 102418775105200
//Deserialized data: 0x5d263ab55eb0
//42
//Hello World
//c

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