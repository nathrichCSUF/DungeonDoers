#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/Domain/Library/Session.hpp"


namespace Domain::Library
{

  class AdministratorSession : public Domain::Library::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors
      unsigned menuType = 0;
      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)

      std::vector<std::string> getSessionCommands(int selection) override;
      //std::vector<std::string> getList() override; // retrieves the list of actions (commands)

      // std::vector<std::string> AddToList();  // retrieves the list of actions (commands)

      // std::vector<std::string> DeleteFromList();  // retrieves the list of actions (commands)

      // std::vector<std::string> AddItem();  // retrieves the list of actions (commands)

      // std::vector<std::string> DeleteItem();  // retrieves the list of actions (commands)

      // std::vector<std::string> getRecordStatistcs();  // retrieves the list of actions (commands)

      // std::vector<std::string> checkPayment(const std::string & payment);  // retrieves the list of actions (commands)

      // std::vector<std::string> recordLog();  // retrieves the list of actions (commands)

      // std::vector<std::string> logOut();  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~AdministratorSession() noexcept override;
  }; // class AdministratorSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline AdministratorSession::~AdministratorSession() noexcept
  {}


  inline std::vector<std::string> AdministratorSession::getCommands()
  {
    return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };
  }
inline std::vector<std::string> AdministratorSession::getSessionCommands(int selection)
{
    switch(menuType){
      case 0: //Menu 
        switch(selection)
        {
          case 1: //Players list that haven't paid 
            //menuType = 1;
            std::cout << "Successfully retrieved player list...\n"
                      << "David     123@gmail.com\n"
                      << "Josh      456@gmail.com\n"
                      << "Geo       789@yahoo.com\n"
                      << "Thomas    abc@yahoo.com\n\n\n";
             return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };

      case 2: // Add player
        //menuType = 1;
            std::cout << "Successfully added player\n\n\n";
             return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };
          
      case 3: // Delete player
        // menuType = 1;
            std::cout << "Successfully deleted player\n\n\n";
             return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item",
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };
          
      case 4: // Add item
        // menuType = 1;
            std::cout << "Successfully added item\n\n\n";
             return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };
         
      case 5: // Deleted item
        // menuType = 1;
            std::cout << "Successfully deleted item\n\n\n";
             return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };
         
      case 6: // Record statistics
        // menuType = 1;
            std::cout << "Successfully recorded statistics\n\n\n";
             return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };
          
      case 7: // Update statistics
        // menuType = 1;
            std::cout << "Successfully updated statistics\n\n\n";
             return { "Log Out", "Help" };
          
      case 8: // Check Payment
        // menuType = 1;
            int payment;
            std::cout << "Enter payment: ";
            std::cin >> payment;

            std::cout << "Valid payment\n\n\n";

             return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };
          
      case 9: // Log information
        // menuType = 1;
            std::cout << "Successfully logged all information\n\n\n";
             return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" };
      default:
          break;

            
        }
          
    } //end of swithc function
    return { "Log Out", "Check Player List", "Add Player", "Delete Player", "Add Item", "Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Help" }; 
} //end of function 
// inline std::string AdministratorSession::getList()
//   {
//     return "List........";
//     // static std::vector<UserInfo> storedUsers =
//     // {
//     // // Username    Email           Payed
//     //   {"Nathan",   "123@yahoo.com", "Y"},
//     //   {"Hector",   "456@yahoo.com", "Y"},
//     //   {"Jonathan", "789@yahoo.com", "N"},
//     //   {"David",    "103@yahoo.com", "Y"},
//     //   {"Josh",     "abc@yahoo.com", "N"},
//     //   {"Pablo",    "def@yahoo.com", "Y"},
//     //   {"Bob",      "hij@yahoo.com", "N"},
//     //   {"Luis",     "klm@yahoo.com", "N"},
//     //   {"Jessica",  "nop@yahoo.com", "Y"},
//     //   {"Maria",    "qrs@yahoo.com", "Y"},
//     //   {"Lisa",     "tuv@yahoo.com", "Y"},
//     //   {"Nate",     "wxy@yahoo.com", "Y"},
//     //   {"Bianka",   "z01@yahoo.com", "N"},
//     // };
//   }

//   // inline std::vector<std::string> getPayment(const std::string & payment);  // retrieves the list of actions (commands)

  // inline std::vector<std::string> AddToList()
  // {
  // }
} // namespace Domain::Library
