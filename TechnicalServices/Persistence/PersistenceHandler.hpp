#pragma once

#include <stdexcept>   // domain_error
#include <string>
#include <vector>




namespace TechnicalServices::Persistence
{
  // Function argument type definitions
  struct UserCredentials
  {
    std::string               userName;
    std::string               passPhrase;
    std::vector<std::string>  roles;
  };


  // Persistence Package within the Technical Services Layer Abstract class
  class PersistenceHandler
  {
    public:
      // Exceptions
      struct NoSuchUser : std::domain_error {using domain_error::domain_error;};


      // Constructors and assignment operations
      PersistenceHandler()                                       = default;                     // default ctor
      PersistenceHandler( const PersistenceHandler &  original ) = default;                     // copy ctor
      PersistenceHandler(       PersistenceHandler && original ) = default;                     // move ctor


      // Operations
      virtual std::vector<std::string> findRoles()                                       = 0;   // Returns list of all legal roles
      virtual UserCredentials          findCredentialsByName( const std::string & name ) = 0;   // Returns credentials for specified user, throws NoSuchUser if user not found


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~PersistenceHandler() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      PersistenceHandler & operator=( const PersistenceHandler &  rhs ) = default;              // copy assignment
      PersistenceHandler & operator=(       PersistenceHandler && rhs ) = default;              // move assignment
  };


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline PersistenceHandler::~PersistenceHandler() noexcept
  {}


} // namespace TechnicalServices::Persistence
