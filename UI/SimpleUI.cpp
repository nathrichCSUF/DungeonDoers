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

#include "../Domain/AccountManagement/UserAccounts.hpp"                                

#include "../Domain/Library/Session.hpp"

#include "../TechnicalServices/Logging/LoggerHandler.hpp"
#include "../TechnicalServices/Logging/SimpleLogger.hpp"
// Include for now - will replace next increment
#include "../TechnicalServices/Persistence/AccountsDB.hpp"

// Include for now - will replace next increment

#include "SimpleUI.hpp"

namespace UI
{
  // Default constructor
  SimpleUI::SimpleUI()
  : _accounts      ( std::make_unique<Domain::AccountManagement::UserAccounts>()  ),   // will replace these factory calls with abstract factory calls in the next increment
    _loggerPtr     ( std::make_unique<TechnicalServices::Logging::SimpleLogger>() ),   // will replace these factory calls with abstract factory calls in the next increment
    _persistentData( std::make_unique<TechnicalServices::Persistence::AccountsDB>() )    // will replace these factory calls with abstract factory calls in the next increment
  {
  }


  // Destructor
  SimpleUI::~SimpleUI() noexcept
  {

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
    bool outOfMenu = false;
    unsigned menuSelection = 1;
    std::string selectedCommand;
    do{ 
      if (!outOfMenu)     
      {
          do //run initial command 
        { 
          for( unsigned i = 0; i != commands.size(); ++i )   std::cout << std::setw( 2 ) << i << " - " << commands[i] << '\n'; //Lists all commands
          std::cout << "  role (0-" << commands.size()-1 << "): "; //Lists options
          std::cin  >> menuSelection; //0-4 command szie= 5
        } while( menuSelection >= commands.size() ); //always false so it runs once 

        selectedCommand = commands[menuSelection]; //displays what was added 
        _logger << "Selected command \"" + selectedCommand + "\" chosen\n";
        outOfMenu = true;
      }
      else //start getting session commands 
      {
        std::vector<std::string> sessionCommands = sessionControl->getSessionCommands(menuSelection); //Gets new set of comands
        for( unsigned i = 0; i != sessionCommands.size(); ++i )   std::cout << std::setw( 2 ) << i << " - " << sessionCommands[i] << '\n'; //display commanfs
        std::cout << "  role (0-" << sessionCommands.size()-1 << "): ";
        std::cin >> menuSelection; //Read from initial commands

        selectedCommand = sessionCommands[menuSelection]; //displays what was added 
        _logger << "Selected command \"" + selectedCommand + "\" chosen\n";
      }

    }while((menuSelection != 0));


  }

}
