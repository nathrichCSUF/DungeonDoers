#include <exception>
#include <iostream>
#include <memory>
#include <new>
#include <iostream>
#include <locale>

#include "/UI/SimpleUI.hpp"
#include "/UI/UserInterfaceHandler.hpp"



int main()
{
    try
    {
        std::cout << "\n**********************************************\n";
        std::cout << "\n**********************************************\n";
        std::cout << "\n********   ****************   ****************\n";
        std::cout << "\n********  * ***************  * ***************\n";
        std::cout << "\n********  ** **************  ** **************\n";
        std::cout << "\n********  *** *************  *** *************\n";
        std::cout << "\n********  **** ************  **** ************\n";
        std::cout << "\n********  *** *************  *** *************\n";
        std::cout << "\n********  ** **************  ** **************\n";
        std::cout << "\n********  * * UNGEON ******  * * OERS ********\n";
        std::cout << "\n********   ****************   ****************\n";
        std::cout << "\n**********************************************\n\n";





        std::unique_ptr<UI::UserInterfaceHandler> userInterface( new UI::SimpleUI );

        std::cout << "\n*****Welcome******\n\n";

         userInterface->launch();

        std::cout << "\nProgram complete, initiating shutdown\n";
    }
    catch(const std::bad_alloc& ex)
    {
        std::cerr << "Fatal: Uncaught memory allocation exception\n\n"
        << ex.what() << '\n';
    }
    catch(const std::exception& ex)
    {
        std::cerr << "Fatal: Uncaught standard exception\n"
        << ex.what() << '\n';
    }
    catch( ... )
    {
        std::cerr << "Fatal: Uncaught (unkown type) exception\n";
    }
    
}
