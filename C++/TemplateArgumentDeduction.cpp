/*
=======================================
Automatic template argument deduction much like
how it's done for functions, but now including class constructors.
=======================================
*/

template <typename T = float> struct MyContainer
{
	MyContainer() : val{} {}
	MyContainer(T val) : val{val} {}

	T val;
};

MyContainer c1 {1};		// OK MyContainer<int>
MyContainer c2;			// OK MyContainer<float>
