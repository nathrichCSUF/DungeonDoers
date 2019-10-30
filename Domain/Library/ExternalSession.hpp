#pragma once

#include <memory>
#include <string>
#include <vector>

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/Domain/Library/Session.hpp"


namespace Domain::Library
{
  class ExternalSession : public Domain::Library::SessionHandler
  {
    public:
        
        using SessionHandler::SessionHandler;  // inherit constructors
        unsigned menuType = 0; 
        
        // Operations
        std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)
        std::vector<std::string> getSessionCommands(int selection) override;
        std::vector<std::string> displayDetails(); 

        // Destructor
        // Pure virtual destructor helps force the class to be abstract, but must still be implemented
        ~ExternalSession() noexcept override;


  }; // class BorrowerSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline ExternalSession::~ExternalSession() noexcept
  {}

 // inline std::vector<std::string> ExternalSession::displayDetails(){
   //   {""}

  //}

  inline std::vector<std::string> ExternalSession::getCommands()
  {
    return { "Log Out", "Purchase/Renew Subsription", "Help" }; //Menu
  }
  inline std::vector<std::string> ExternalSession::getSessionCommands(int selection)
  {
        std::string name;
        std::string cardNumber;
        std::string expDate;

      switch(menuType){
            case 0: //Menu 
                switch(selection){
                    case 1: //Purchase/Renew 
                        //menuType = 1; 
                        std::cout << "Enter card holder name: ";
                        std::cin >> name;
                        std::cout << "\nEnter card number: ";
                        std::cin >> cardNumber;
                        std::cout << "\nEnter card expiration date (MMYY): ";
                        std::cin >> expDate;
                        std::cout << "30 day Subscription Successfully Purchased.\n";
                        std::cout << "Payement Confirmation Number: 43245\n";
                        return {"Log Out", "Purchase/Renew Subscription", "Help"};
                    case 2: //Help 
                        menuType = 1;
                        return {"Log Out", "Prev Menu"};
                    default:
                        return {"Log Out", "Purchase/Renew Subscription", "Help"};
            }
            case 1: //Help Screen
                
                    std::cout << "To play the game you must be a valid subscriber. Enter your payment info by going back to menu\n";
                    std::cout << "and clicking Pay/Renew Subscriptions. Enter your valid payment information to add 30 days to your subscription\n";
                    menuType = 0;
                    return {"Log Out", "Purchase/Renew Subscription", "Help"};
                

            default:
                return {"Log Out", "Purchase/Renew Subsription", "Help"};

      }
    return {"Log Out", "Purchase/Renew Subsription", "Help"};
  }


} // namespace Domain::Library
