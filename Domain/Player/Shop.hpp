#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Weapon.hpp"
#include "SwordWeapon.hpp"
namespace Domain::Player
{
    struct Shop 
    {
        
        Shop()
        {
            weapons = {"Sword"};
        }
        std::unique_ptr<Weapon> PurchaseWeapon(std::string name) 
        {
            if (name == "Sword")
            {
                 return std::make_unique<Domain::Player::SwordWeapon>();
            }
        }
        
        
        std::vector<std::string> weapons;
    };
}