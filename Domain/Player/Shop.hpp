#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Weapon.hpp"
#include "SwordWeapon.hpp"
#include "KnifeWeapon.hpp"
namespace Domain::Player
{
    struct Shop 
    {
        
        Shop()
        {
            weapons = {"Sword","Knife"};
        }
        std::unique_ptr<Weapon> PurchaseWeapon(std::string name) 
        {
            if (name == "Sword")
            {
                 return std::make_unique<Domain::Player::SwordWeapon>();
            }
            if (name == "Knife") //new derived class
            {
                 return std::make_unique<Domain::Player::KnifeWeapon>();
            }
        }
        
        
        std::vector<std::string> weapons;
    };
}