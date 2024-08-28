#include "Brain.hpp"
#include "utils.hpp"

Brain::Brain() {
  std::cout << "Brain: ";
  DEFAULT_CONSTRUCTOR_MESSAGE;
}

Brain::~Brain() {
  std::cout << "Brain: ";
  DESTRUCTOR_MESSAGE;
}

Brain::Brain(const Brain &other) {
  *this = other;
  COPY_CONSTRUCTOR_MESSAGE;
}

std::string &Brain::getIdea(int index) {
  if (index >= 0 && index < 100) {
    return ideas[index];
  }
  throw std::out_of_range("Index out of range");
}

void Brain::setIdea(int index, const std::string &idea) {
  if (index >= 0 && index < 100) {
    ideas[index] = idea;
  } else {
    throw std::out_of_range("Index out of range");
  }
}

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    std::cout << "Brain: ";
    std::copy(other.ideas, other.ideas + 100, ideas);
    COPY_ASSIGNMENT_MESSAGE;
  }
  return *this;
}
