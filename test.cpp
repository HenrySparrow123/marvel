#include "marvel.hpp"
#include <iostream>

int main()
{
    Personne sorciere("Wanda", "Maximof", Personne::FEMME);
    std::stringstream ss;
    sorciere.afficher(ss&);

    std::cout << ss.str();

}