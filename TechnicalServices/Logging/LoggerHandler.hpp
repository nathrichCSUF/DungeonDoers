#pragma once

#include <iostream>
#include <string>


namespace TechnicalServices::Logging
{
  // Logging Package within the Technical Services Layer Abstract class
  class LoggerHandler
  {
    public:
      // Constructors
      LoggerHandler( std::ostream & loggingStream = std::clog);             // default ctor
      LoggerHandler( const LoggerHandler &  original ) = default;           // copy ctor
      LoggerHandler(       LoggerHandler && original ) = default;           // move ctor


      // Operations
      virtual LoggerHandler & operator<< ( const std::string & message ) = 0;

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~LoggerHandler() noexcept = 0;


    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      LoggerHandler & operator=( const LoggerHandler  & rhs ) = delete;    // copy assignment
      LoggerHandler & operator=(       LoggerHandler && rhs ) = delete;    // move assignment

      std::ostream & _loggingStream;
  };





  /*****************************************************************************
  ** Inline default implementations
  ******************************************************************************/
  inline LoggerHandler::~LoggerHandler() noexcept
  {}


  inline LoggerHandler::LoggerHandler( std::ostream & loggingStream )
  : _loggingStream( loggingStream )
  {}
} // namespace TechnicalServices::Logging
