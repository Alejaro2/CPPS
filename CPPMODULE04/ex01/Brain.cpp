#include "Brain.hpp"

Brain::Brain() 
{
  std::cout << YELLOW << "Brain has been constructed!" << RESET << std::endl;
}

Brain::Brain(const Brain &other) 
{
  std::cout << YELLOW << "Brain has been copied!" << RESET << std::endl;
  *this = other;
}

Brain &Brain::operator=(const Brain &other) 
{
  std::cout << YELLOW << "Brain has been assigned!" << RESET << std::endl;
  if (this != &other) 
  {
    int i = 0;
    while (i < 100) 
    {
      this->_ideas[i] = other._ideas[i];
      i++;
    }
  }
  return *this;
}

Brain::~Brain() 
{
  std::cout << RED << "Brain has been destroyed!" << RESET << std::endl;
}

void Brain::setIdea(int index, std::string idea) 
{
  if (index >= 0 && index < 100) 
  {
    this->_ideas[index] = idea;
  }
}

std::string Brain::getIdea(int index) const 
{
  if (index >= 0 && index < 100) 
  {
    return this->_ideas[index];
  }
  return "";
}
