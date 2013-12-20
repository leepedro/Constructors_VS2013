#include "vectors.h"

void CheckStdVector(void)
{
	std::vector<int> s1 = { 10, 11 };
	std::vector<int> s2{ 10, 11 };
	std::vector<int> s3({ 10, 11 });

	// This creates a one-element vector as it is supposed to be.
	std::vector<int> s4({ 3 });

	// This creates a three-element vector as it is supposed to be.
	std::vector<int> s5(3);	
}

int main(void)
{
	//CheckStdVector();

	// Vector(void)
	Tests::Vector<int> v1;
	v1.Push(10);

	// Vector(const Vector<T> &)
	Tests::Vector<int> v2 = v1;
	Tests::Vector<int> v3(v1);

	// Vector(Vector<T> &&)
	Tests::Vector<int> v4 = std::move(v1);
	Tests::Vector<int> v5(std::move(v2));

	// Vector<T> &operator=(const Vector<T> &)
	v3.Push(20);
	v1 = v3;

	// Vector<T> &operator=(Vector<T> &&)
	v3.Push(30);
	v2 = std::move(v3);

	// Vector(::size_t)
	Tests::Vector<int> v6(4);
	//Tests::Vector<int> v6 = 4;	// Blocked by explicit declaration.

	// Vector(const std::vector<T> &)
	std::vector<int> s1 = { 10 };
	Tests::Vector<int> v7 = s1;
	Tests::Vector<int> v8(s1);

	// Vector(const std::initializer_list<T> &)
	Tests::Vector<int> v9({ 11, 12 });
	Tests::Vector<int> v10 = { 11, 12 };
	Tests::Vector<int> v11({ 11 });
	Tests::Vector<int> v12 = { 11 };

	// Vector(std::vector<T> &&)
	Tests::Vector<int> v13 = std::move(s1);

	// Vector<T> &operator=(const std::vector<T> &) or
	// Vector(const std::vector<T> &) + Vector<T> &operator=(Vector<T> &&)
	std::vector<int> s2 = { 20, 30 };
	v12 = s2;

	// Vector<T> &operator=(std::vector<T> &&) or
	// Vector(std::vector<T> &&) + Vector<T> &operator=(Vector<T> &&)
	v12 = std::move(s2);

	// Arguments
	Tests::FuncStdVector<int>({ 0, 1, 2 });
	Tests::FuncA(v12);

	// Vector(const std::initializer_list<T> &) for input argument.
	Tests::FuncA<int>({ 1, 2, 3 });
}