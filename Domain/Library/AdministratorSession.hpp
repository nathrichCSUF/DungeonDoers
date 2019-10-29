#pragma once

#include <memory>
#include <string>
#include <vector>

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/Domain/Library/Session.hpp"


namespace Domain::Library
{
  class AdministratorSession : public Domain::Library::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


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
    return { "Check Accounts", "Add or Delete Accounts", "Add or Delete Item", 
              "Record Statistics", "Update Statistics", "Check Payment", 
              "Log Information", "Log Out", "Help" };
  }

} // namespace Domain::Library
