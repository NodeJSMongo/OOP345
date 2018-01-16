#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "Stations.h"

using namespace std;

namespace w2
{
	Stations::Stations(const char* filename)
	: _filename(filename), _cntStation(0), _stations(nullptr)
	{
		//cout << "Stations(" << filename << ")\n";
		std::fstream fs(filename);
		if(!fs.is_open())
		{
			cerr << "Cannot open file " << filename << "\n";
			exit(1);
		}

		// read station count;
		fs >> _cntStation;
		//cout << "station count = " << _cntStation << "\n";

		// skip; + \n
		char c;
		fs.get(c);
		if (c != ';')
		{
			cerr << "expected ';' but found '" << c << "'\n";
			fs.close();
			exit(2);
		}

		fs.get(c);
		if (c != '\n')
		{
			std::cerr << "expected '\\n' but found '" << c << "'\n";
			fs.close();
			exit(3);
		}

		_stations = new Station[_cntStation];
		for(int s = 0; s < _cntStation; s++)
		{
			std::string name = "";
			int cntStudent;
			int cntAdult;

			getline(fs, name, ';');
			fs >> cntStudent;
			fs >> cntAdult;

			_stations[s].set(name, cntStudent, cntAdult);

			fs.get(c);
			if (c != '\n')
			{
				std::cerr << "expected ';' but found '" << c << "'\n";
				fs.close();
				exit(4);
			}
		}

		fs.close();
	}

	Stations::~Stations()
	{
		fstream fs;
		fs.open(_filename.c_str(), ios::out);
		if (fs.is_open())
		{
			fs << _cntStation << ";\n";
			for (int s = 0; s < _cntStation; s++)
			{
				fs << _stations[s].getName() << ";"
				   << _stations[s].inStock(STUDENT_PASS) << " "
				   << _stations[s].inStock(ADULT_PASS) << endl;
			}
			fs.close();
		}

		delete [] _stations;
	}

	void Stations::update() const
	{
		cout << endl;
		cout << "Passes Sold :\n";
		cout << "-------------\n";

		for (int s = 0; s < _cntStation; s++)
		{
			int cntStudent, cntAdult;

			cout << _stations[s].getName() << "\n";
			cout << " Student Passes sold : ";
			cin >> cntStudent;

			cout << " Adult   Passes sold : ";
			cin >> cntAdult;
			_stations[s].update(STUDENT_PASS, -cntStudent);
			_stations[s].update(ADULT_PASS, -cntAdult);
		}
	}

	void Stations::restock() const
	{
		cout << endl;
		cout << "Passes Added :\n";
		cout << "-------------\n";

		for (int s = 0; s < _cntStation; s++)
		{
			int cntStudent, cntAdult;

			cout << _stations[s].getName() << "\n";
			cout << " Student Passes added : ";
			cin >> cntStudent;

			cout << " Adult   Passes added : ";
			cin >> cntAdult;
			_stations[s].update(STUDENT_PASS, cntStudent);
			_stations[s].update(ADULT_PASS, cntAdult);
		}
	}

	void Stations::report() const
	{
		cout << endl;
		cout << "Passes in Stock : Student Adult\n";
 		cout << "-------------------------------\n";

		for(int s = 0; s < _cntStation; s++)
		{
			cout << left << setw(19) << _stations[s].getName();
			cout << right << setw(6) << _stations[s].inStock(STUDENT_PASS);
			cout << right << setw(6) << _stations[s].inStock(ADULT_PASS);
			cout << endl;
		}
	}
}
