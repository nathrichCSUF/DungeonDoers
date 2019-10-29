#include <string>
#include <vector>
#include <memory>     // make_unique()

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Persistence/AccountsDB.hpp"
#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Logging/SimpleLogger.hpp"
#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace TechnicalServices::Persistence
{
  AccountsDB::AccountsDB()
  : _loggerPtr( std::make_unique<TechnicalServices::Logging::SimpleLogger>() )     // will replace these factory calls with abstract factory calls next increment
  {
    _logger << "Accounts DB being used and has been successfully initialized";
  }



  AccountsDB::~AccountsDB() noexcept
  {
    _logger << "Accounts DB shutdown successfully";
  }


// Roles output in UI for user
  std::vector<std::string> AccountsDB::findRoles()
  {
    return { "Create Account", "Player", "Administrator"};
  }

  UserCredentials AccountsDB::findCredentialsByName( const std::string & name )
  {
    static std::vector<UserCredentials> storedUsers =
    {
    // Username    Pass Phrase         Authorized roles
      {"Nathan",   "Nathan",     {"Administrator", "Player"}},
      {"Hector",   "Hector",     {"Administrator", "Player"}},
      {"Jonathan", "Jonathan",   {"Administrator", "Player"}},
      {"David",    "David",      {"Player"}},
      {"Josh",     "Josh",       {"Player"}},
      {"Pablo",    "Pablo",      {"Player"}},
      {"Bob",      "Bob",        {"Player"}},
      {"Luis",     "Luis",       {"Player"}},
      {"Jessica",  "Jessica",    {"Player"}},
      {"Maria",    "Maria",      {"Player"}},
      {"Lisa",     "Lisa",       {"Player"}},
      {"Nate",     "Nate",       {"Player"}},
      {"Bianka",   "Bianka",     {"Player"}}
    };

    for( const auto & user : storedUsers ) if( user.userName == name ) return { user.userName, user.passPhrase, user.roles };

    // Name not found, throw something
    std::string message = __func__;
    message += " attempt to find user \"" + name + "\" failed";

    _logger << message;

    throw PersistenceHandler::NoSuchUser( message );
  }

} // namespace TechnicalServices::Persistence
