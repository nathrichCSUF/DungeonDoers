#pragma once 
#include "Weapon.hpp"

namespace Domain::Player 
{
    class KnifeWeapon : public Domain::Player::Weapon //New derived Class 
    {
        private:
            int damage;
        public:
        KnifeWeapon()
        {
            damage = 1; //Less damage then a sword
        }
        ~KnifeWeapon()
        {}
        int attack() override 
        {
            return damage;
        }
    };
}