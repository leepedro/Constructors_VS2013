#include "inherit_ctor.h"

int main(void)
{
	BaseA a1;
	BaseA a2(1, 2.5);

	DerivedB b1;
	//DerivedB b2(1, 2.5);	// C2661: undefined ctor.

	// Following line should be BaseA(), but it is actually the implicitly declared
	// DerivedC(void).
	DerivedC c1;

	// Following line should be DerivedC::DerivedC(int i_value, double d_value),
	// but it is not supported by VS2013.
	//DerivedC c2(1, 2.5);
}