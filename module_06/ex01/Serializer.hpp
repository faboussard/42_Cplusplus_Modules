#pragma once

#include "data.hpp"
#include <iostream>
#include <stdint.h>
#include <string>

// uintptr_t

class Serializer {

private:
  Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &other);
  ~Serializer();

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};