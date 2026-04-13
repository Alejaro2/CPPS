#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

class ClapTrap 
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
  		ClapTrap(void);
  		ClapTrap(std::string const &name);
  		ClapTrap(const ClapTrap &copy);
  		ClapTrap &operator=(const ClapTrap &copy);
  		~ClapTrap(void);

  		void attack(const std::string &target);
  		void takeDamage(unsigned int amount);
  		void beRepaired(unsigned int amount);

  		std::string const &getName(void) const;
  		int const &getHitPoints(void) const;
  		int const &getEnergyPoints(void) const;
  		int const &getAttackDamage(void) const;

  		void setName(std::string const &name);
  		void setHitPoints(int const &value);
  		void setEnergyPoints(int const &value);
  		void setAttackDamage(int const &value);
};

#endif
