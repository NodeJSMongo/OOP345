#ifndef _NOTIFICATIONS_H_
#define _NOTIFICATIONS_H_

#include "Message.h"

namespace w5
{
	class Notifications
	{
		Message* _messages;
		size_t _size;

	public:
		/**
		 *	default constructor - empty
		 */
		Notifications();

		/**
		 *	copy constructor
		 */
		Notifications(const Notifications& other);

		/**
		 *	copy assignment operator
		 */
		Notifications& operator=(const Notifications& rhs);

		/**
		 *	move constructor
		 */
		Notifications(Notifications&& other);

		/**
		 *	move assignment operator
		 */
		Notifications&& operator=(Notifications&& rhs);

		/**
		 *	destructor
		 */
		~Notifications();

		/**
		 *	adds msg to the set
		 */
		void operator+=(const Message& msg);

		/**
		 *	inserts the Message objects to the os output stream
		 */
		void display(std::ostream& os) const;
	};
}

#endif 	// _NOTIFICATIONS_H_
