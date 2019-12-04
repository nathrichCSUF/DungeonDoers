#pragma once 
#include "Weapon.hpp"

namespace Domain::Player 
{
    class SwordWeapon : public Domain::Player::Weapon
    {
        private:
            int damage;
        public:
        SwordWeapon()
        {
            damage = 3;
        }
        ~SwordWeapon()
        {}
        int attack() override 
        {
            return damage;
        }
    };
}