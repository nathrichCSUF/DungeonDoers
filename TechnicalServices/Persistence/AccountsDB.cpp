#include <string>
#include <vector>
#include <memory>     // make_unique()
#include <ctime> 

#include "AccountsDB.hpp"
#include "../Logging/SimpleLogger.hpp"
#include "PersistenceHandler.hpp"

namespace TechnicalServices::Persistence
{
  AccountsDB::AccountsDB()
  : _loggerPtr( std::make_unique<TechnicalServices::Logging::SimpleLogger>() )     // will replace these factory calls with abstract factory calls next increment
  {

  }




  AccountsDB::~AccountsDB() noexcept
  {

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



// ExternalSystem::ExternalSystem(){
//   cardHolderName = " ";
//   cardNum = " ";
//   expdate = " ";
//   std::cout << "External Payment System successfully opened"<< endl; 

// }

// ExternalSystem::~ExternalSystem(){
//   std::cout << "External Payment System has now closed." << endl;
// }

// void ExternalSystem::setPaymentInfo(std::string name,std::string card, std::string expirationDate){
//   cardHolderName = name; 
//   cardNum = car;
//   expDate = expirationDate; 
// }

// bool ExternalSystem::validatePayment(){
//   if(cardNum.length() == 16 && expDate.length() == 4){
//     std::
//     return true;
//   }
//   else 
//     return false; 
// }

// void ExternalSystem::displaySubscriptionInfo(){
//   std::cout << "Purchase a 30 Day Subscription.\nCost:$5." << endl; 
// }

// void ExternalSystem::receipt(){
//   std::int count = 1; 
//   std::time_t t = std::time(0);
//   std::tm* timePtr = std::localtime(&t);

//   std::cout << "Dongeon Doers" << endl;
//   std::cout <<"# " << count << endl; 
//   std::cout << "Date: " << (timePtr->tm_mday) << "/" << (timePtr->tm_mon)+1 << "/" << (timePtr->tm_year)+1900 << endl;
//   std::cout << "Time: " << (timePter->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec) << endl; 
//   std::cout << endl;
//   std::cout << "30 day Subscription\t\t5.00"
//   std::cout << endl;
//   std::cout <<"Thank you for your purchase." << endl;
// }

