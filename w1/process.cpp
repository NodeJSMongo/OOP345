/* -----------------------------------------------------------------------------------
 *
 *      File           process.h
 *      Date           2017/01/23
 *      Author         mahmudul islam mahmud
 *      Contact        mimahmud@myseneca.ca
 *
 *      Description
 *
 * ----------------------------------------------------------------------------------- */

#include <iostream>
#include "CString.h"

using namespace std;

namespace w1
{
	void process(const char* parm)
	{
		CString cs(parm);
		cout << cs << endl;
	}
}
