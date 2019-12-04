#pragma once

#include <memory>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Session.hpp"
#include "ExternalSession.hpp"
#include "../Player/Shop.hpp"
#include "../Player/Weapon.hpp"
#include "../../External/External.hpp"
#include "../../External/ExternalLaunch.hpp"

namespace Domain::Library
{
  class PlayerSession : public Domain::Library::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors
      PlayerSession():SessionHandler()
      {
        _shop = std::make_unique<Domain::Player::Shop>();
        _esLaunch = std::make_unique<External::ExternalLaunch>();
      }
      std::unique_ptr<Domain::Player::Weapon> _weapon;
      unsigned menuType = 0;
      unsigned weaponIndex;
      int enemyHealth = 2;
      int receiptCode;
       std::vector<std::string> weapons;
      // Operationsfr
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)
       std::vector<std::string> getSessionCommands(int selection) override;
      unsigned GetItems();
      int GetReceiptCodeFromExternal();
      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~PlayerSession() noexcept override;
    private:
      std::unique_ptr<Domain::Player::Shop> _shop;
      std::unique_ptr<External::ExternalLaunch> _esLaunch;
      std::unique_ptr<External::ExternalService> _es;

  }; // class BorrowerSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline PlayerSession::~PlayerSession() noexcept
  {}

  inline unsigned PlayerSession::GetItems()  
  {
    unsigned choice = 0;
     for( unsigned i = 0; i != _shop->weapons.size(); ++i )
     {
       std:: cout << i + 1 << ": " << _shop->weapons[i] << "\n";
     }
     std::cin >> choice;
     return choice -1;
  }
  inline int PlayerSession::GetReceiptCodeFromExternal()
  {
    std::unique_ptr<External::ExternalService> _es = _esLaunch->LaunchExternalService(); //Launch desired service
    return _es->GetConfirmationNumber();
  }
  inline std::vector<std::string> PlayerSession::getCommands()
  {
    return { "Log Out", "Load Game", "Pay/Renew Subscription"};
  }
  inline std::vector<std::string> PlayerSession::getSessionCommands(int selection)
  {
    switch(menuType){
      case 0: //Menu 
        switch(selection)
        {
          case 1: //Load Game 
            menuType = 1; //Change to Select Save SLot
            return {"Log Out","Slot 1 ","Slot 2","Slot 3"};
          case 2: //Pay/Renew Subscription
             _es; 
            receiptCode = GetReceiptCodeFromExternal();
            std::cout << "Received Confirmation Number from External Service :" << receiptCode << "\n";
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};
          default:
            menuType = 0;
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};
        }
      case 1://Save Slot Selection 
        switch(selection)
        {
          case 1:
            menuType = 2;
            std::cout << "You have loaded slot 1\n";
            return {"Log Out","Buy Items"}; 
          case 2:
            menuType = 2;
            std::cout << "You have loaded slot 2\n";
            return {"Log Out","Buy Items"}; 
          case 3:
            menuType = 2;
            std::cout << "You have loaded slot 3\n";
            return {"Log Out","Buy Items"}; 
          default:
            menuType = 0;
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};
        }
      case 2: //Select Item
        switch(selection)
        {
          case 1: //Buy Iems
            std::cout << "Pick your weapons\n";
            weaponIndex = GetItems(); //Return list of weapons
            _weapon = _shop->PurchaseWeapon(_shop->weapons[weaponIndex]);
            std::cout << "You have purchased " << _shop->weapons[weaponIndex] <<  "\n";
            menuType = 3; //Change to Enemy Encounter
            return { "Log Out", "Start Dungeon"};
          default:
            menuType = 0;
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};
        }
      case 3: //Encounter Enemy 
        switch(selection){
          case 1: //Start Dungeon 
            std::cout << "You are Fighting the Big Monster, Aragort!\n";
            menuType = 4;
            return {"Log Out","Attack"};//,"Item"};
          default:
          menuType = 0;
              return { "Log Out", "Load Game", "Pay/Renew Subscription"};
        }
      case 4: //Battle 
        switch(selection){
          case 1: //Attack
            std::cout << "You hit Aragort!\n";
            enemyHealth-=_weapon->attack();
            if (enemyHealth <=0) //if enemy dies
            {
              std::cout << "You Killed Aragort! You beat the game!\n";
              std::cout << "Collect your prize!\n";
              menuType = 5;
              return { "Log Out", "Collect Treasure"};
            }
            
            menuType = 4; //if not go to battle screen
            return {"Log Out","Attack","Item"};
        
          // case 2: // Items
          //   std::cout << " You have used an item\n ";
          //   return {"Log Out","Attack","Item"}; 
          default:
            menuType = 0;
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};
        }
      case 5: //Collect Treasure end screen
        switch(selection){
          case 1: //Collect Treasure
            std::cout << "You have beaten Dungeon Doers!\n";
            std::cout << "Returning to main menu!\n";
            menuType = 0;
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};
          default:
            menuType = 0;
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};        
        }
      default:
        menuType = 0;
        return { "Log Out", "Load Game", "Pay/Renew Subscription"};
  }//end of first switch statement
  return { "Log Out", "Load Game", "Pay/Renew Subscription"};
}//end of function
  


} // namespace Domain::Library
