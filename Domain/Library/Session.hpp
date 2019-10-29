#pragma once

#include <memory>  // unique_ptr
#include <string>
#include <vector>


namespace Domain::Library
{
  // Library Package within the Domain Layer Abstract class
  // The SessionHandler abstract class serves as the generalization of all user commands
  class SessionHandler
  {
    public:
      // Constructors and assignment operations
      SessionHandler()                                           = default;  // default ctor
      SessionHandler( const SessionHandler &  original )         = default;  // copy ctor
      SessionHandler(       SessionHandler && original )         = default;  // move ctor

      // Operations
      virtual std::vector<std::string> getCommands() = 0;  // retrieves the list of actions (commands)

      // Object Factory returning a specialized object specific to the specified role
      static std::unique_ptr<SessionHandler> createSession( const std::string & role );

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~SessionHandler() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      SessionHandler & operator=( const SessionHandler &  rhs ) = default;  // copy assignment
      SessionHandler & operator=(       SessionHandler && rhs ) = default;  // move assignment

  };    // class SessionHandler





     /*****************************************************************************
     ** Inline implementations
     ******************************************************************************/
  inline SessionHandler::~SessionHandler() noexcept
  {}

} // namespace Domain::Library
