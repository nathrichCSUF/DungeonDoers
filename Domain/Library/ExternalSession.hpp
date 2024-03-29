#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Session.hpp"
#include "../../External/External.hpp"

namespace Domain::Library
{
  class ExternalSession : public External::ExternalService
  {
    public:
        ExternalSession()  = default; 
        int GetConfirmationNumber() override
        {
          std::string name;
          std::string cardNumber;
          std::string expDate;
          int confirmationNumber = rand() %10000 + 1000; //generate random confirmation number!
          std::cout << "Enter card holder name: ";
          std::cin >> name;
          std::cout << "\nEnter card number: ";
          std::cin >> cardNumber;
          std::cout << "\nEnter card expiration date (MMYY): ";
          std::cin >> expDate;
          std::cout << "30 day Subscription Successfully Purchased.\n";
          std::cout << "Payement Confirmation Number: " << confirmationNumber << "\n";
          return confirmationNumber;
        }
        ~ExternalSession() noexcept override;


  }; // class BorrowerSession
  inline ExternalSession::~ExternalSession() noexcept
  {
    
  }




} // namespace Domain::Library
