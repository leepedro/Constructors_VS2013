#if !defined(INHERIT_CTOR_H)
#define INHERIT_CTOR_H

// Inheriting ctor is NOT supported by VS2013!

class BaseA
{
public:
	BaseA(void) = default;
	BaseA(int i_value, double d_value);

protected:
	int i_ = 0;
	double d_ = 0.0;
};

BaseA::BaseA(int i_value, double d_value) : i_(i_value), d_(d_value) {}

class DerivedB : public BaseA
{
protected:
	char c_ = 'a';
};

class DerivedC : public BaseA
{
public:
	// Following line should internally create DerivedC::DerivedC(int i_value, double d_value)
	// NOT supported by VS2013.
	using BaseA::BaseA;

protected:
	char c_ = 'a';
};

#endif
