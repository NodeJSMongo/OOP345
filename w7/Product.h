#ifndef _PRODUCT_H_
#define _PRODUCT_H_
 
#include "iProduct.h"
 
namespace w7
{
	class Product : public iProduct
	{
		int _number;
		double _price;
 
	public:
		
		Product(int number, double price);
 
		virtual double getCharge() const;
		virtual void display(std::ostream& os) const;
	};
 
	class TaxableProduct : public Product
	{
		char _taxable;
 
	public:	
 
		TaxableProduct(int number, double price, char taxable);
 
		virtual double getCharge() const;
		virtual void display(std::ostream& os) const;
	};
}
 
#endif 	// _PRODUCT_H_