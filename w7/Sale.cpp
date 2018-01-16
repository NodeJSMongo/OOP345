#include <iomanip>
#include "Sale.h"
 
namespace w7
{
	Sale::Sale(const char* filename)
	{
		std::ifstream fs(filename);	
		if (!fs)
			throw std::string("*** Failed to open file ") + std::string(filename) + std::string(" ***");
 
		iProduct* p;
		while((p = readProduct(fs)))
		{			
			_products.push_back(p);		
		}											
 
		fs.close();
	}
 
	Sale::~Sale()
	{
		for(int i = 0; i < _products.size(); i++)
			delete _products[i];
	}
 
	void Sale::display(std::ostream& os) const
	{
		std::cout << "Product No      Cost Taxable" << std::endl;
		
		double cost = 0.0;
		for (int i = 0; i < _products.size(); i++)		
		{
			os << *_products[i] << std::endl;	
			cost += _products[i]->getCharge();
		}
 
		std::cout << std::setw(10) << "Total" << std::fixed << std::setprecision(2) << std::setw(10) << cost << std::endl;
	}
}