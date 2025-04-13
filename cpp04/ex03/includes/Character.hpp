#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Utils.hpp"

// Définir une taille maximale pour le sol (Materias déséquipées)
#define MAX_FLOOR 100

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];

	// Tableau statique pour les Materias déséquipées
	AMateria *_floor[MAX_FLOOR];
	int _floor_count;

public:
	Character();
	Character(std::string const &name);
	Character(const Character &copy);
	virtual ~Character();

	Character &operator=(const Character &assign);

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

	// Méthode pour utiliser toutes les Materias de l'inventaire sur une cible
	void useAll(ICharacter &target);

	// Méthode pour nettoyer le sol si besoin ailleurs que dans le destructeur
	void cleanFloor();
};

#endif
