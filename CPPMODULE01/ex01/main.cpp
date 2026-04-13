#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    
    Zombie *horde = zombieHorde(N, "Horde");
    int i = 0;
    while(i < N)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}