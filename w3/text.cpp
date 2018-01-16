/* -----------------------------------------------------------------------------------
 *
 *      File            Text.cpp
 *      Date            2015/09/25
 *      Author        	Young-Hwan Mun
 *      Contact         yhmun@myseneca.ca
 *
 *      Description     
 *
 * ----------------------------------------------------------------------------------- */
 
#include <iostream>
#include <fstream>
#include <utility>
#include "Text.h"
 
namespace w3
{
	Text::Text()
	: _lineCount(0), _lines(nullptr)
	{
		
	}
 
	Text::Text(const char* filename)
	: _lineCount(0), _lines(nullptr)
	{
		std::fstream fs(filename);
		if(fs.is_open()) 
		{
			std::string s;
			while(getline(fs, s))
			{
				_lineCount++;
			}
			
			fs.clear();
			fs.seekg(0, std::ios::beg);
 
			_lines = new (std::nothrow) std::string[_lineCount];
			for(size_t r = 0; r < _lineCount; r++)
			{
				std::getline(fs, _lines[r]);
			}			
 
			fs.close();
		}
		else
		{
			std::cerr << "Cannot open file " << filename << "\n";
		}	
	}
 
	Text::Text(const Text& rhs)	
	{
		_lines = nullptr;
		*this = rhs;
	}
 
	Text& Text::operator=(const Text& rhs)
	{
		if (this != &rhs)
		{
			delete [] _lines;
 
			_lineCount = rhs._lineCount;
			if (rhs._lines)
			{
				_lines = new (std::nothrow) std::string[_lineCount];
				for(size_t r = 0; r < _lineCount; r++)
				{
					_lines[r] = rhs._lines[r];
				}					
			}
			else
			{
				_lines = nullptr;
			}
		}
 
		return *this;
	}
 
	Text::Text(Text&& rhs)
	{
		_lines = nullptr;
		*this = rhs;
	}
 
	Text& Text::operator=(Text&& rhs)
	{
		if (this != &rhs)
		{
			delete [] _lines;
 
			// move
			_lineCount = rhs._lineCount;
			_lines = rhs._lines;
 
			// steal brains, make a zombie
			rhs._lineCount = 0;
			rhs._lines = nullptr;
		}
 
		return *this;
	}
 
	Text::~Text()
	{
		delete [] _lines;
	}
 
	size_t Text::size() const
	{
		return _lineCount;
	}	
}