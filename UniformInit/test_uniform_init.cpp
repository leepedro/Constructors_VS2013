/*
Visual Studio 2013 throws an error C2440: '<function-style-cast>': cannot convert from 'initializer-list' to 'TestClass<int>' at Func() function.
It is interesting that there is an identical syntax in main() function, but the compiler doesn't throw an error there.
I tested the same source code against GCC and Clang in Linux, and both of them compile without a problem.
*/
#include <iostream>

template <typename T>
class TestClass
{
public:
	T x, y;
	bool operator==(const TestClass<T> &rhs) const;
};

template <typename T>
bool TestClass<T>::operator==(const TestClass<T> &rhs) const
{
	return this->x == rhs.x && this->y == rhs.y;
}

void Func(const TestClass<int> &src)
{
	if (src == TestClass<int>{ 1, 2 })		// C2440 error!!!
		std::cout << "good" << std::endl;
	//std::cout << "bad" << std::endl;
}

int main(void)
{
	TestClass<int> s1{ 1, 2 };
	if (s1 == TestClass<int>{1, 2})			// identical syntax compiles here!!!
		std::cout << "good" << std::endl;
	Func(s1);
}