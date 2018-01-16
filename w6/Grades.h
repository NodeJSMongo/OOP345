/* -----------------------------------------------------------------------------------
 *
 *      File            Grades.h
 *      Date            2015/10/14
 *      Author        	Young-Hwan Mun
 *      Contact         yhmun@myseneca.ca
 *
 *      Description     
 *
 * ----------------------------------------------------------------------------------- */
 
#ifndef _GRADES_H_
#define _GRADES_H_
 
#include <iomanip>
#include <fstream>
 
//namespace w6
//{
	class Grades
	{
		size_t _size;
		int* _numbers;
		double* _grades;
 
	public:
 
		Grades(const char* filename)
		: _size(0), _numbers(nullptr), _grades(nullptr)
		{
			std::fstream fs(filename);
            if (!fs)
                throw std::string("*** Failed to open file ") + std::string(filename) + std::string(" ***");
 
			std::string line;
			size_t count = 0;
 
			while(getline(fs, line))
			{
				count++;
			}
		
			fs.clear();
			fs.seekg(0, std::ios::beg);
 
			_numbers = new (std::nothrow) int[count];
			_grades = new (std::nothrow) double[count];
			_size = count;
 
			for(size_t i = 0; i < count; i++)
			{
				fs >> _numbers[i];
				fs >> _grades[i];
			}									
 
			fs.close();
		}
 
		virtual ~Grades()
		{
			delete[] _numbers;
			delete[] _grades;
		}
 
		/**
		 *	receives a reference to the output stream object and the expression to be
		 * 	used in determining the letter grade.  Your function displays the student 
		 *	number, the student grade, and the letter equivalent as shown below on the right. 
		 */
		void displayGrades(std::ostream& os, const char* (*express)(double)) const
		{
			for(size_t i = 0; i < _size; i++)
			{
				os << _numbers[i] << ' ' << std::fixed << std::setprecision(2) << _grades[i] << ' ' << express(_grades[i]) << std::endl;
			}	
		}
	};
//}
 
#endif 	// _GRADES_H_