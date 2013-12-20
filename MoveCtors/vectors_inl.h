#if !defined(VECTORS_INL_H)
#define VECTORS_INL_H

namespace Tests
{
	template <typename T>
	Vector<T>::Vector(void) : data(data_)
	{
		std::cout << "Vector<T>::Vector(void)" << std::endl;
	}

	template <typename T>
	Vector<T>::Vector(const Vector<T> &src) : data(data_), data_(src.data_)
	{
		std::cout << "Vector<T>::Vector(const Vector<T> &)" << std::endl;
	}

	template <typename T>
	Vector<T>::Vector(Vector<T> &&src) : data(data_), data_(std::move(src.data_))
	{
		std::cout << "Vector<T>::Vector(Vector<T> &&)" << std::endl;
	}

	template <typename T>
	Vector<T> &Vector<T>::operator=(const Vector<T> &src)
	{
		std::cout << "Vector<T> &Vector<T>::operator=(const Vector<T> &)" << std::endl;
		this->data_ = src.data;
		return *this;
	}

	template <typename T>
	Vector<T> &Vector<T>::operator=(Vector<T> &&src)
	{
		std::cout << "Vector<T> &Vector<T>::operator=(Vector<T> &&)" << std::endl;
		// Since std::vector<T> has its own move ctor and move assignment operator,
		// it is unnecessary to clear and swap.
		//this->data_.clear();
		//this->data_.swap(src.data_);
		this->data_ = std::move(src.data_);
		return *this;
	}

	// Note: data_(n) calls ctor std::vector<T>(n).
	/* WARNING:
	Another ctor with std::initializer_list<T> should be accompanied with this ctor.
	Otherwise, a single member brace list such as {2} is translated as a scalr value, and
	this ctor is called instead of Vector(const std::vector<T> &).
	In other words, Vector<int>({2}) does the same thing as Vector<int>({0, 0}) because it is
	translated as Vector<int>(2). A ctor with std::initializer_list<T> fixed this issue.
	*/
	template <typename T>
	Vector<T>::Vector(::size_t n) : data(data_), data_(n)
	{
		std::cout << "Vector<T>::Vector(::size_t)" << std::endl;
	}

	template <typename T>
	Vector<T>::Vector(const std::initializer_list<T> &srcList) : data(data_), data_(srcList)
	{
		std::cout << "Vector<T>::Vector(const std::initializer_list<T> &)" << std::endl;
	}

	template <typename T>
	Vector<T>::Vector(const std::vector<T> &srcData) : data(data_), data_(srcData)
	{
		std::cout << "Vector<T>::Vector(const std::vector<T> &)" << std::endl;
	}

	template <typename T>
	Vector<T>::Vector(std::vector<T> &&srcData) : data(data_), data_(std::move(srcData))
	{
		std::cout << "Vector<T>::Vector(std::vector<T> &&)" << std::endl;
	}

	/*
	Vector<T> &Vector<T>::operator=(const std::vector<T> &) can be replaced with 
	Vector(const std::vector<T> &) + Vector<T> &operator=(Vector<T> &&).
	*/
	//template <typename T>
	//Vector<T> &Vector<T>::operator=(const std::vector<T> &srcData)
	//{
	//	this->data_ = srcData;
	//	return *this;
	//}

	/*
	Vector<T> &Vector<T>::operator=(std::vector<T> &&) can be replaced with
	Vector(std::vector<T> &&) + Vector<T> &operator=(Vector<T> &&).
	*/
	//template <typename T>
	//Vector<T> &Vector<T>::operator=(std::vector<T> &&srcData)
	//{
	//	this->data_.clear();		// Important!
	//	this->data_.swap(srcData);
	//	return *this;
	//}

	template <typename T>
	void Vector<T>::Push(T value)
	{
		this->data_.push_back(value);
	}

	template <typename T>
	std::vector<T> FuncStdVector(const std::vector<T> &src)
	{
		return{ 1, 2, 3 };
	}

	template <typename T>
	Vector<T> FuncA(const Vector<T> &src)
	{
		// Vector(const std::initializer_list<T> &)
		return{ 1, 2, 3 };
	}
}

#endif
