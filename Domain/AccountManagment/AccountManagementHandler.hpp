#pragma once

#include <string>

#include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::AccountManagement
{
     // Import the User Credentials type from the lower layer and publish it as your own
  using TechnicalServices::Persistence::UserCredentials;
 
 
  // Account Management Package within the Domain Layer Abstract class
  class AccountManagementHandler
  {
    public:
      // Constructors and assignment operations
      AccountManagementHandler()                                                            = default;    // default ctor
      AccountManagementHandler( const AccountManagementHandler &  original )                = default;    // copy ctor
      AccountManagementHandler(       AccountManagementHandler && original )                = default;    // move ctor


      // Operations
      virtual bool isAuthenticated( const  UserCredentials & credentials ) = 0;


      // Abstract class destructor
      virtual ~AccountManagementHandler() noexcept = 0;  // must be virtual and pure

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      AccountManagementHandler & operator=( const AccountManagementHandler &  rhs ) = default;    // copy assignment
      AccountManagementHandler & operator=(       AccountManagementHandler && rhs ) = default;    // move assignment
 };





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline AccountManagementHandler::~AccountManagementHandler() noexcept
  {}

} // namespace Domain::AccountManagements