
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>


class ExternalService : public Domain::Library::SessionHandler {


    std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)

    std::vector<std::string> getSessionCommands(int selection) override;


};
