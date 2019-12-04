#pragma once

#include <memory>
#include <string>
#include <vector>
#include <stdlib.h>


namespace Domain::Library
{
  class CreatorSession : public Domain::Library::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors
      CreatorSession()
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)
       std::vector<std::string> getSessionCommands(int selection) override;
      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~CreatorSession() noexcept override;


  }; 
}