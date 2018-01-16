#include <iomanip>
#include "Product.h"
 
namespace w7
{
 	std::ostream& operator<<(std::ostream& os, const iProduct& P)
 	{
 		P.display(os);
 		return os;
 	}
 
	iProduct* readProduct(std::ifstream& in)
	{
		int number;
		double price;
		char taxable;
 
		in >> number;
		if (in.fail())
			return (iProduct*) 0;
 
		in >> price;
		if (in.fail())
			return (iProduct*) 0;
 
		taxable = in.get();
		if (taxable == '\n')
		{
			return new Product(number, price);
		}
		else
		{
			in >> taxable;	
			return new TaxableProduct(number, price, taxable);
		}
	}
 
	Product::Product(int number, double price)
	: _number(number), _price(price)
	{
 
	}
 
	double Product::getCharge() const
	{
		return _price;
	}
 
	void Product::display(std::ostream& os) const
	{
		os << std::setw(10) << _number << std::fixed << std::setprecision(2) << std::setw(10) << _price;
	}
 
	TaxableProduct::TaxableProduct(int number, double price, char taxable)
	: Product(number, price), _taxable(taxable)
	{
		
	}
 
	double TaxableProduct::getCharge() const
	{
		double charge = Product::getCharge();
 
		if (_taxable == 'H') charge *= 1.13;
		else if (_taxable == 'P') charge *= 1.08;
		
		return charge;
	}
 
	void TaxableProduct::display(std::ostream& os) const
	{
		Product::display(os);
		os << ' ' << (_taxable == 'H'? "HST" : "PST");
	}	
}