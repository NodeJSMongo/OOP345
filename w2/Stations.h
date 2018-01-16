#ifndef __Stations_h__
#define __Stations_h__

#include "Station.h"

namespace w2
{
	class Stations
	{
		std::string _filename;
		int _cntStation;
		Station* _stations;

	public:

		Stations(const char* filename);
		virtual ~Stations();

		/**
		 *	accepts the number of passes sold and updates the data for each station in turn
		 */
		void update() const;

		/**
		 *	accepts the number of passes added and updates the data for each station in turn
		 */
		void restock() const;

		/**
		 *	reports the number of passes currently available at each station
		 */
		void report() const;

	};

}	// namespace w2

#endif	// __Stations_h__
