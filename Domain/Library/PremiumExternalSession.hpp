#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Session.hpp"
#include "../../External/External.hpp"

namespace Domain::Library
{
  class PremiumExternalSession : public External::ExternalService
  {
    public:
        PremiumExternalSession()  = default; 
        int GetConfirmationNumber() override
        {
          std::string name;
          std::string cardNumber;
          std::string expDate;
          std::string email;
          int confirmationNumber = rand() %10000 + 1000; //generate random confirmation number!
          std::cout << "Enter card holder name: ";
          std::cin >> name;
          std::cout << "\nEnter card number: ";
          std::cin >> cardNumber;
          std::cout << "\nEnter card expiration date (MMYY): ";
          std::cin >> expDate;
          std::cout << "30 day Subscription Successfully Purchased.\n";
          std::cout << "Enter your email for a chance to win big: ";
          std::cin >> email;
          std::cout << "\nAs a Premium Member, the confirmation code also provides free premium items!\n";
          std::cout << "Payement Confirmation Number: " << confirmationNumber << "\n";
          return confirmationNumber;
        }
        ~PremiumExternalSession() noexcept override;


  }; // class BorrowerSession
  inline PremiumExternalSession::~PremiumExternalSession() noexcept
  {
    
  }




} // namespace Domain::Library
