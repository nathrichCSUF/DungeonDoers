#pragma once

#include <memory>
#include <string>
#include <vector>
#include <stdlib.h>

#include "/Domain/Library/Session.hpp"


namespace Domain::Library
{
  class PlayerSession : public Domain::Library::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors
      unsigned menuType = 0;
      int enemyHealth = 2;
       std::vector<std::string> weapons;
      // Operationsfr
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)
       std::vector<std::string> getSessionCommands(int selection) override;
      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~PlayerSession() noexcept override;

  }; // class BorrowerSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline PlayerSession::~PlayerSession() noexcept
  {}


  inline std::vector<std::string> PlayerSession::getCommands()
  {
    return { "Log Out", "Load Game", "Pay/Renew Subscription"};
  }
  inline std::vector<std::string> PlayerSession::getSessionCommands(int selection)
  {
    std::string name;
    std::string cardNumber;
    std::string expDate;
    int receiptCode = rand() %10000 + 1000;
    switch(menuType){
      case 0: //Menu 
        switch(selection)
        {
          case 1: //Load Game 
            menuType = 1; //Change to Select Save SLot
            return {"Log Out","Slot 1 ","Slot 2","Slot 3"};
          case 2: //Pay/Renew Subscription
            std::cout << "Enter card holder name: ";
            std::cin >> name;
            std::cout << "\nEnter card number: ";
            std::cin >> cardNumber;
            std::cout << "\nEnter card expiration date (MMYY): ";
            std::cin >> expDate;
            std::cout << "30 day Subscription Successfully Purchased.\n";
            std::cout << "Payement Confirmation Number: " << receiptCode << "\n";
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
            return {"Log Out","Start Dungeon","Buy Items"};
          case 2:
            menuType = 2;
            std::cout << "You have loaded slot 2\n";
            return {"Log Out","Start Dungeon","Buy Items"};
          case 3:
            menuType = 2;
            std::cout << "You have loaded slot 3\n";
            return {"Log Out","Start Dungeon","Buy Items"}; 
          default:
            menuType = 0;
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};
        }
      case 2: //Game Menu
        switch(selection){
          case 1: //Start Dungeon 
            std::cout << "You are Fighting the Big Monster, Aragort!\n";
            menuType = 3;
            return {"Log Out","Attack","Item"};
          case 2: //Buy Items
            std::cout << " You have bought items \n ";
            return {"Log Out","Start Dungeon","Buy Items"}; 
          default:
          menuType = 0;
              return { "Log Out", "Load Game", "Pay/Renew Subscription"};
        }
      case 3: //Battle 
        switch(selection){
          case 1: //Attack
            std::cout << "You hit Aragort!\n";
            enemyHealth-=1;
            if (enemyHealth <=0) //if enemy dies
            {
              std::cout << "You Killed Aragort! You beat the game!\n";
              std::cout << "Collect your prize!\n";
              menuType = 4;
              return { "Log Out", "Collect Treasure"};
            }
            
            menuType = 3; //if not go to battle screen
            return {"Log Out","Attack","Item"};
        
          case 2: // Items
            std::cout << " You have used an item\n ";
            return {"Log Out","Attack","Item"}; 
          default:
            menuType = 0;
            return { "Log Out", "Load Game", "Pay/Renew Subscription"};
        }
      case 4:
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
