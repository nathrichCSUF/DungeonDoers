#pragma once

#include <memory>
#include <string>
#include <vector>

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/Domain/Library/Session.hpp"


namespace Domain::Library
{
  class PlayerSession : public Domain::Library::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~PlayerSession() noexcept override;
  }; // class BorrowerSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline PlayerSession::~PlayerSession() noexcept
  {}


  inline std::vector<std::string> PlayerSession::getCommands()
  {
    return { "Start New Game", "Open Save Slot", "Purchase Item", "Make Payment", "Log Out", "Help" };
  }

} // namespace Domain::Library
