#if !defined(VECTORS_H)
#define VECTORS_H

#include <vector>
#include <iostream>

namespace Tests
{
	template <typename T>
	class Vector
	{
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Vector(void);
		Vector(const Vector<T> &src);
		Vector(Vector<T> &&src);
		Vector<T> &operator=(const Vector<T> &src);
		Vector<T> &operator=(Vector<T> &&src);

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		explicit Vector(::size_t n);
		Vector(const std::initializer_list<T> &srcList);
		Vector(const std::vector<T> &srcData);
		Vector(std::vector<T> &&srcData);
		//Vector<T> &operator=(const std::vector<T> &srcData);	// optional, no need
		//Vector<T> &operator=(std::vector<T> &&srcData);		// optional, no need

		////////////////////////////////////////////////////////////////////////////////////
		// Methods
		void Push(T value);

		////////////////////////////////////////////////////////////////////////////////////
		// Members.
		const std::vector<T> &data;

	protected:
		////////////////////////////////////////////////////////////////////////////////////
		// Members.
		std::vector<T> data_;
	};

}
#include "vectors_inl.h"

#endif
