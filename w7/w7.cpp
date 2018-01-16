#include <iostream>
#include <string>
#include "Sale.h"
 
int main(int argc, char** argv) 
{
	if (argc != 2) 
	{
		std::cerr << argv[0] << ": incorrect number of arguments\n"; 
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}
 
	try 
	{
		w7::Sale sale(argv[1]);
		sale.display(std::cout);
	}
    catch (const std::string& msg) 
    {
        std::cerr << msg << std::endl;
        return 2;
    }
    catch (const char* msg) 
    {
        std::cerr << msg << std::endl;
        return 2;
    }
 
	std::cout << "\nPress any key to continue ... ";
	std::cin.get();
 
	return 0;
}