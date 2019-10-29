#pragma once

#include <memory>    // std::unique_ptr
#include <string>

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/Domain/AccountManagement/AccountManagementHandler.hpp"

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Logging/LoggerHandler.hpp"
#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Persistence/PersistenceHandler.hpp"


namespace Domain::AccountManagement
{
  class UserAccounts : public Domain::AccountManagement::AccountManagementHandler
  {
    public:
      using AccountManagementHandler::AccountManagementHandler;  // inherit constructors
      UserAccounts();

      // Operations
      bool isAuthenticated( const UserCredentials & credentials ) override;


      // Destructor
      ~UserAccounts() noexcept override;


    private:
      // These smart pointers hold pointers to lower architectural layer's interfaces
      std::unique_ptr<TechnicalServices::Persistence::PersistenceHandler>    _persistentData;
      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>             _loggerPtr;


      // convenience reference object enabling standard insertion syntax
      // This line must be physically after the definition of _loggerPtr
      TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;
  };
} // namespace Domain::AccountManagement
