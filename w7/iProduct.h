#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_
 
#include <iostream>
#include <fstream>
 
namespace w7 
{
	class iProduct 
	{
	public:
		virtual ~iProduct() {}
		virtual double getCharge() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};
 
	std::ostream& operator<<(std::ostream& os, const iProduct& P); 
	iProduct* readProduct(std::ifstream& in);
}
 
#endif	// _I_PRODUCT_H_