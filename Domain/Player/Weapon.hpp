#pragma once

namespace Domain::Player
{
    class Weapon 
    {
        public:
            Weapon()
            {}
            virtual int attack() = 0;
            virtual ~Weapon() = 0;
    };
    inline Weapon::~Weapon() {}
}