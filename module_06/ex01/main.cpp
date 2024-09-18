#include "Serializer.hpp"
#include "data.hpp"

#include <iostream>

int main() {
  Data *data;
  uintptr_t serializedData;
  Data *deserializedData;

  data = new Data;
  data->num = 42;
  data->string = "Hello World";
  data->c = 'c';

  std::cout << "Data: " << data << std::endl;

  serializedData = Serializer::serialize(data);
  std::cout << "Serialized: " << std::hex << serializedData << std::endl;
  std::cout << std::dec;

  deserializedData = Serializer::deserialize(serializedData);
  std::cout << "Deserialized data: " << deserializedData << std::endl
            << deserializedData->num << std::endl
            << deserializedData->string << std::endl
            << deserializedData->c << std::endl;

  delete data;

  return 0;
}