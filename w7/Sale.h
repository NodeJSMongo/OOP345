#ifndef _SALE_H_
#define _SALE_H_
 
#include <vector>
#include "Product.h"
 
namespace w7
{
	class Sale
	{
		std::vector<iProduct*> _products;
 
	public:
 
		Sale(const char* filename);
 
		virtual ~Sale();
 
		/**
		 *	receives a reference to the output object and displays the sale information
		 * 	as shown in the sample output above.  The output includes column headings 
		 *	and the total sale amount including taxes paid.  The product number and cost
		 * 	occupy fields of width 10. 
		 */
		void display(std::ostream& os) const;
	};
}
 
#endif 	// _SALE_H_