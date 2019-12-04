
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>

namespace External
{ 
    class ExternalService { //Interface for External Service

    public:
        ExternalService()                                           = default;  // default ctor
        ExternalService( const ExternalService &  original )         = default;  // copy ctor
        ExternalService(       ExternalService && original )         = default;  // move ctor
        virtual int GetConfirmationNumber() = 0;  
        virtual ~ExternalService() = 0;

    };
    inline ExternalService::~ExternalService() {}
}
