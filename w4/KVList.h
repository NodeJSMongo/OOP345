#ifndef _KVLIST_H_
#define _KVLIST_H_

//namespace w4
//{
	template <typename K, typename V, int N>
	class KVList
	{
		K _keys[N];
		V _values[N];
		size_t _size;

	public:
		/**
		 *	default constructor - adopts a safe empty state
		 */
		KVList()
		: _size(0)
		{

		}

		/**
		 *	returns the number of entires in the key-value list
		 */
		size_t size() const
		{
			return _size;
		}

		/**
		 *	returns an unmodifiable reference to the key of element i in the list
		 */
		const K& key(int i) const
		{
			//if (i >= 0 && i < _size)
				return _keys[i];
			//else
			//	;
		}

		/**
		 *	returns an unmodifiable reference to the value of element i in the list
		 */
		const V& value(int i) const
		{
			//if (i >= 0 && i < _size)
				return _values[i];
			//else
			//	;
		}

		/**
		 *	adds a new element to the list if room exists and returns a reference to the current object,
		 * 	does nothing if no room exists
		 */
		KVList& add(const K& k, const V& v)
		{
			if (_size < N)
			{
				_keys[_size] = k;
				_values[_size] = v;
				_size++;
			}
			else
			{
				;	// client says does nothing if no room exists
			}

			return *this;
		}

		/**
		 *	returns the index of the first element in the list with a key equal to k - defaults to 0
		 */
		int find(const K& k) const
		{
			for(int i = 0; i < _size; i++)
			{
				if (k == _keys[i])
				{
					return i;
				}
			}

			return 0;	// client says defaults to 0
		}

		/**
		 *	replaces element i in the list with the key and value received and returns a reference to the current object
		 */
		KVList& replace(int i, const K& k, const V& v)
		{
			if (i >= 0 && i < _size)
			{
				_keys[i] = k;
				_values[i] = v;
			}

			return *this;
		}
	};
//}

#endif 	// _KVLIST_H_
