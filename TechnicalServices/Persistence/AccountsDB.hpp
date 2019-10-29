#pragma once

#include <memory>    // unique_ptr
#include <string>
#include <vector>

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Logging/LoggerHandler.hpp"
#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Persistence/PersistenceHandler.hpp"




namespace TechnicalServices::Persistence
{
  class AccountsDB : public TechnicalServices::Persistence::PersistenceHandler
  {
    public:
      using PersistenceHandler::PersistenceHandler;    // inherit constructors
      AccountsDB();


      // Operations
      std::vector<std::string> findRoles()                                 
          override;  // Returns list of all legal roles
      UserCredentials          findCredentialsByName( const std::string & name ) 
          override;  // Returns credentials for specified user, throws NoSuchUser if user not found


      ~AccountsDB() noexcept override;

    private:
      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>             
          _loggerPtr;

      // convenience reference object enabling standard insertion syntax
      // This line must be physically after the definition of _loggerPtr
      TechnicalServices::Logging::LoggerHandler                            & 
        _logger = *_loggerPtr;

  }; // class AccountsDB
}  // namespace TechnicalServices::Persistence
