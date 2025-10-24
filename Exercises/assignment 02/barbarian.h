/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/10/08
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include "characterTpl.h"
namespace seneca {
	template<typename T, typename Ability_t, typename Weapon_t>
	class Barbarian : public CharacterTpl<T> {
		int m_baseDefense;
		int m_baseAttack;
		Ability_t m_ability;
		Weapon_t m_weapon[2];
	public:
		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon) : CharacterTpl<T>(name, healthMax), m_baseDefense(baseDefense), 
			m_baseAttack(baseAttack), m_weapon{ primaryWeapon, secondaryWeapon } {
		}

		int getAttackAmnt() const override {
			double weaponSum = m_weapon[0] / 2 + m_weapon[1] / 2;
			return m_baseAttack + static_cast<int>(weaponSum);
		}

		int getDefenseAmnt() const override {return m_baseDefense;}

		Character* clone() const override { return new Barbarian(*this); }

		void attack(Character* enemy) override {
			std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
			m_ability.useAbility(this);
			int damage = getAttackAmnt();
			m_ability.transformDamageDealt(damage);
			std::cout << "    Barbarian deals " << damage << " melee damage!" << std::endl;
			enemy->takeDamage(damage);
		}
		void takeDamage(int dmg) override {
			std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
			int def = getDefenseAmnt();
			std::cout << "    Barbarian has a defense of " << def << ". Reducing damage received." << std::endl;
			int reducedDmg = dmg - def;
			if (reducedDmg < 0)
				reducedDmg = 0;
			m_ability.transformDamageReceived(reducedDmg);
			CharacterTpl<T>::takeDamage(reducedDmg);
		}

	};
}
#endif