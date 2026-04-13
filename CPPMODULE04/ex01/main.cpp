#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() 
{
  const int numAnimals = 10;
  Animal *animals[numAnimals];

  std::cout << BLUE << "--- Creating 5 Dogs and 5 Cats ---" << RESET
            << std::endl;
  int i = 0;
  while (i < numAnimals / 2) 
  {
    animals[i] = new Dog();
    i++;
  }
  i = numAnimals / 2;
  while (i < numAnimals) 
  {
    animals[i] = new Cat();
    i++;
  }

  std::cout << BLUE << "--- Deleting all animals ---" << RESET << std::endl;
  i = 0;
  while (i < numAnimals) 
  {
    delete animals[i];
    i++;
  }

  std::cout << BLUE << "--- Testing Deep Copy ---" << RESET << std::endl;
  {
    Dog basic;
    basic.setIdea(0, "Don't forget to eat");
    std::cout << "Original idea: " << basic.getIdea(0) << std::endl;
    {
      Dog tmp = basic;
      std::cout << "Copy idea: " << tmp.getIdea(0) << std::endl;
      tmp.setIdea(0, "Barking at the mailman");
      std::cout << "Changed copy idea: " << tmp.getIdea(0) << std::endl;
    }
    std::cout << "Original idea after copy scope: " << basic.getIdea(0)
              << std::endl;
  }

  std::cout << BLUE << "--- Testing Deep Copy Assignment ---" << RESET
            << std::endl;
  {
    Cat cat1;
    cat1.setIdea(0, "Catch that mouse");
    Cat cat2;
    cat2 = cat1;
    cat1.setIdea(0, "Time for a nap");
    std::cout << "cat1 idea: " << cat1.getIdea(0) << std::endl;
    std::cout << "cat2 idea: " << cat2.getIdea(0) << std::endl;
  }
  return 0;
}
