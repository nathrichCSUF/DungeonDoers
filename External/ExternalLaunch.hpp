
#pragma once
#include <memory>
#include <vector>
#include <string>

#include "External.hpp"
#include "../Domain/Library/ExternalSession.hpp"
#include "../Domain/Library/PremiumExternalSession.hpp"
namespace External
{ 
    struct ExternalLaunch 
    {
        
        ExternalLaunch()
        {
            services = {"Regular","Premium"};
        }
        std::unique_ptr<ExternalService> LaunchExternalService() 
        {
            int serviceChoice;
            std::cout << "1: Regular 30 Day Payment Service\n";
            std::cout << "2: Premium Yearly  Payment Service with Extra Secret Benefits!\n";
            std::cout << "Enter 1 for Regular 30 Day External Payment Service, or Enter 2 for extra benefits!\n";
            std::cin >> serviceChoice;
            if (serviceChoice == 1)
            {
                 return std::make_unique<Domain::Library::ExternalSession>();
            }
            if (serviceChoice == 2) //new derived class
            {
                 return std::make_unique<Domain::Library::PremiumExternalSession>();
            }
        }
        
        
        std::vector<std::string> services;
    };
}