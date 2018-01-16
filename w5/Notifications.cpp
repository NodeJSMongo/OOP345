#include <iostream>
#include <fstream>
#include "Notifications.h"

#define MAX_MESSAGES 10

namespace w5
{
	Notifications::Notifications()
	:  _messages(new Message[MAX_MESSAGES]), _size(0)
	{

	}

	Notifications::Notifications(const Notifications& other)
	{
		_messages = nullptr;
		*this = other;
	}

	Notifications& Notifications::operator=(const Notifications& rhs)
	{
		if (this != &rhs)
		{
			delete [] _messages;

			_size = rhs._size;
			if (rhs._messages)
			{
				_messages = new Message[MAX_MESSAGES];
				for(int i = 0; i < MAX_MESSAGES; i++)
					_messages[i] = rhs._messages[i];
			}
			else
			{
				_messages = nullptr;
			}
		}

		return *this;
	}

	Notifications::Notifications(Notifications&& other)
	{
		_messages = nullptr;
		*this = std::move(other);
	}

	Notifications&& Notifications::operator=(Notifications&& rhs)
	{
		if (this != &rhs)
		{
			delete [] _messages;

			_messages = rhs._messages;
			_size = rhs._size;

			rhs._messages = nullptr;
			rhs._size = 0;
		}

		return std::move(*this);
	}

	Notifications::~Notifications()
	{
		delete [] _messages;
	}

	void Notifications::operator+=(const Message& msg)
	{
		if (_size < MAX_MESSAGES)
			_messages[_size++] = msg;
	}

	void Notifications::display(std::ostream& os) const
	{
		for(int i = 0; i < _size; i++)
		{
			_messages[i].display(os);
			os << std::endl;
		}
	}
}
