# DungeonDoers
CSUF: CPSC 462 Software Design Project
CLI Based Adventure Game

Compile Code
Make sure to read to compile code.

Files without .o file. 

All #include's of .hpps have to match where you have placed the files in your computer.
Example: #include "/Users/hecthor/Desktop/fall_2019/462/sampleCode/TechnicalServices/Persistence/SimpleDB.hpp" 

Make sure to compile every .cpp file separately creating .o files.
Example: g++ -std=c++17 -c main.cpp 


It should create a .o file inside your file. Make sure to do this to every .cpp file inside the sample code. 
Another example creating the .o file inside /Domain/AccountManagement file, creating the .o file for UserAccounts.cpp.
 

Once all .o files have been created, compile all .o files into an executable file. Include the path if some .o files are not at the root.
Example:g++ main.o UI/SimpleUI.o  TechnicalServices/Persistence/SimpleDB.o Domain/AccountManagement/UserAccounts.o Domain/Library/Session.o -o main
 
 
Should create an .exec file inside the root file. 

Then just run ./main 

Sample run: Denied 
To gain access change the SimpleDB.cpp or use any of the stored users to gain access. 

We are in!
