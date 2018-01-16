/* -----------------------------------------------------------------------------------
 *
 *      File            CString.h
 *      Date            2017/01/23
 *      Author        	mahmudul islam mahmud
 *      Contact         mimahmud@myseneca.ca
 *
 *      Description
 *
 * ----------------------------------------------------------------------------------- */

#ifndef __CString_h__
#define __CString_h__

#ifndef nullptr
#define nullptr 0
#endif

namespace w1
{
	const int MAX = 3;

	class CString
	{
		char _str[MAX+1];

	public:

		CString(const char* parm);

		void display(std::ostream& os) const;
	};

	std::ostream& operator << (std::ostream& os, const CString& C);

}	// namespace w1

#endif	// __CString_h__
