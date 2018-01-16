#include <iostream>
#include <fstream>
#include "Message.h"

using namespace std;

namespace w5
{
	Message::Message()
	{

	}

	Message::Message(std::ifstream& in, char c)
	{
		std::string user;
		std::string reply;
		std::string tweet;
		char t;

		in >> user;
		if (!in.fail())
		{
			t = in.get();
			if (t != c)
			{
				t = in.get();
				if (t == '@')
				{
					in >> reply;
					in.ignore();
					getline(in, tweet, c);
				}
				else
				{
					getline(in, tweet, c);
					tweet = t + tweet;
				}

				if (tweet.size() > 0)
				{
					_user  = user;
					_reply = reply;
					_tweet = tweet;
				}
			}
		}
	}

	bool Message::empty() const
	{
		return _tweet.size() == 0;
	}

	void Message::display(std::ostream& os) const
	{
		os << "Message\n";
		os << " User  : " << _user << "\n";
		if (_reply.size() > 0)
		   os << " Reply : " << _reply << "\n";
  		os << " Tweet : " << _tweet << "\n";
	}
}
