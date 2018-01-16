#ifndef __Station_h__
#define __Station_h__

#ifndef nullptr
#define nullptr
#endif

namespace w2
{
	enum PassType
	{
		ADULT_PASS,		// exactly the same as #define STUDENT_PASS 0
		STUDENT_PASS,	// exactly the same as #define STUDENT_PASS 1
		PASS_COUNT		// exactly the same as #define STUDENT_PASS 2
	};

	class Station
	{
		/**
		 *	the name of the station - stored as a string object
		 */
		std::string _name;

		/**
		 *	the number of student passes - stored as an unsigned int
		 *	the number of adult passes - stored as an unsigned int
		 */
		unsigned int _numPasses[PASS_COUNT];

	public:

		/**
		 *	a default constructor that initializes the instance variables through an initialization list
		 */
		Station();

		/**
		 *	sets the instance variables to the values received in its parameters
		 */
		void set(const std::string&, unsigned, unsigned);

		/**
		 *	updates the number of passes - sold if negative, added if positive
		 */
		void update(PassType, int);

		/**
		 *	returns the number of passes of the requested type
		 */
		unsigned inStock(PassType) const;

		/**
		 *	returns a reference to a string object holding the name of the station
		 */
		const std::string& getName() const;
	};

}	// namespace w2

#endif	// __Station_h__
