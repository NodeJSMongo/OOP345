/* -----------------------------------------------------------------------------------
 *
 *      File            Text.h
 *      Date            2015/09/25
 *      Author        	Young-Hwan Mun
 *      Contact         yhmun@myseneca.ca
 *
 *      Description     
 *
 * ----------------------------------------------------------------------------------- */
 
#ifndef _TEXT_H_
#define _TEXT_H_
 
namespace w3
{
	class Text
	{
		size_t _lineCount;
		std::string* _lines;
 
	public:
 
		Text();
 
		Text(const char* filename);
 
		/**
		 *	a copy constructor
		 */
		Text(const Text& rhs);
 
		/**
		 *	a copy assignment operator
		 */
		Text& operator=(const Text& rhs);
 
		/**
		 *	a move constructor
		 */
		Text(Text&& rhs);
 
		/**
		 *	a move assignment operator
		 */
		Text& operator=(Text&& rhs);
 
		/**
		 *	a destructor
		 */
		virtual ~Text();
 
		/**
		 *	a member function named size_t size() const that returns the number of records of text data
		 */
		size_t size() const;
	};
 
}	// namespace w2  
 
#endif	// _TEXT_H_