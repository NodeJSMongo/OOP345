/* -----------------------------------------------------------------------------------
 *
 *      File           CString.cpp
 *      Date           2017/01/23
 *      Author         mahmudul islam mahmud
 *      Contact        mimahmud@myseneca.ca
 *
 *      Description
 *
 * ----------------------------------------------------------------------------------- */

#include <iostream>
#include <cstring>

#include "CString.h"

using namespace std;

namespace w1
{
	CString::CString(const char* parm)
	{
		if (parm == nullptr)
		{
			_str[0] = '\0';
			return;
		}

		strncpy(_str, parm, MAX);
		_str[MAX] = '\0';
	}

	void CString::display(std::ostream& os) const
	{
		os << _str;
	}

	std::ostream& operator << (std::ostream& os, const CString& C)
	{
		static int call = 0;
		os << call++ << ": ";
		C.display(os);
		return os;
	}
}
