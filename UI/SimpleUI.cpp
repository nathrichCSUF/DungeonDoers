#include <iomanip>
        // setw()
#include <iostream>
        // streamSize
#include <limits>
    // numeric_limits
#include <memory>
    // unique_ptr, make_unique<>()
#include <string>
    // string, getline()
#include <vector>

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/Domain/AccountManagement/UserAccounts.hpp"

// Include for now - will replace next increment
#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/Domain/Library/Session.hpp"

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Logging/LoggerHandler.hpp"
#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Logging/SimpleLogger.hpp"
// Include for now - will replace next increment
#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Persistence/AccountsDB.hpp"

// Include for now - will replace next increment

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/UI/SimpleUI.hpp"

namespace UI
{
  // Default constructor
  SimpleUI::SimpleUI()
  : _accounts      ( std::make_unique<Domain::AccountManagement::UserAccounts>()  ),   // will replace these factory calls with abstract factory calls in the next increment
    _loggerPtr     ( std::make_unique<TechnicalServices::Logging::SimpleLogger>() ),   // will replace these factory calls with abstract factory calls in the next increment
    _persistentData( std::make_unique<TechnicalServices::Persistence::AccountsDB>() )    // will replace these factory calls with abstract factory calls in the next increment
  {
    _logger << "Simple UI being used and has been successfully initialized";
  }


  // Destructor
  SimpleUI::~SimpleUI() noexcept
  {
    _logger << "Simple UI shutdown successfully";
  }



  // Operations launch UI
  void SimpleUI::launch()
  {
    // 1) Fetch roles to select from
    std::vector<std::string> roleLegalValues = _persistentData->findRoles();
    std::string selectedRole;

    // 2) Present login screen to user and valid roles
    //    Once user selects a valid role, user needs to
    //    be aunthenticated by providing a valid username and password
    do
    {
            unsigned menuSelection;

      do
      {
        for( unsigned i = 0; i != roleLegalValues.size(); ++i )   std::cout << std::setw( 2 ) << i << " - " << roleLegalValues[i] << '\n';
        std::cout << "  Enter Option (0-" << roleLegalValues.size()-1 << "): ";
        std::cin  >> menuSelection;
        std::cin.ignore(  std::numeric_limits<std::streamsize>::max(), '\n' );

      } while( menuSelection >= roleLegalValues.size() );

      selectedRole = roleLegalValues[menuSelection];

      std::string userName;
      std::cout << "\n  Username: ";
      std::getline( std::cin, userName );

      std::string passPhrase;
      std::cout << "  Password: ";
      std::getline( std::cin, passPhrase );

    

      // 3) Validate user is authorized for this role
      if( _accounts->isAuthenticated( { userName, passPhrase, {selectedRole} } ) )
      {
        _logger << "Login Successful for \"" + userName + "\" as role \"" + selectedRole + "\"\n";
        break;
      }

      std::cout << "** Login failed\n";
      _logger << "Login failure for \"" + userName + "\" as role \"" + selectedRole + "\"\n";

    } while( true );



    // 4) Fetch functionality options for this role
    std::unique_ptr<Domain::Library::SessionHandler> sessionControl = Domain::Library::SessionHandler::createSession( selectedRole );

    std::vector<std::string> commands = sessionControl->getCommands();
    unsigned menuSelection;
    do
    {
      for( unsigned i = 0; i != commands.size(); ++i )   std::cout << std::setw( 2 ) << i << " - " << commands[i] << '\n';
      std::cout << "  role (0-" << commands.size()-1 << "): ";
      std::cin  >> menuSelection;
    } while( menuSelection >= roleLegalValues.size() );

    std::string selectedCommand = commands[menuSelection];
    _logger << "Selected command \"" + selectedCommand + "\" chosen";
  }

}